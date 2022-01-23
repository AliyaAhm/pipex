#include "../include/pipex.h"

void    error_proc()
{
    perror("\033[31mError:\e{0m");
    exit(EXIT_FAILURE);
}

void	error_file(char *file)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void check_fd(int *fd_1, int *fd_2, char **argv)
{
    if ((*fd_1 = open(argv[1], O_RDONLY)) < 0)
        error_file(argv[1]);
    if ((*fd_2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644) < 0)
        error_file(argv[4]);
}

char    **find_path(char **env)
{
    int     i;
    char    **str;

    i = 0;
    while(env[i])
    {
        if (ft_strnstr(env[i], "PATH=", 5))
        {
            str = ft_split(env[i] + 5, ':');
            if (!str)
                error_proc();
            return (str);
        }
        i++;
    }
    return (NULL);
}

char    *f_getline(char *cmd, char **arr)
{
    int     i;
    char    *tmp;
    char    *line;

    i = 0;
    while (arr[i])
    {
        tmp = ft_strjoin(arr[i], "/");
        line = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(line, F_OK) == 0)
            return (line);
        else
            free(line);
        i++;
    }
    error_cmd(cmd);
    return (NULL);
}

void    procc_fd1(int pipe_fd, char **argv, char **env, int fd_1)
{
    char    *line;
    char    **cmd;
    char    **path;

    dup2(pipe_1, 0);
    dup2(pipe_fd[1], 1);
    cmd = ft_split(argv[2], ' ');
    path = path_find(env);
    line = f_getline(cmd[0], path);
    close(fd_1);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    execve(line, cmd, env);
}

void    procc_fd2(int pipe_fd, char **argv, char **env, int fd_2)
{
    char    *line;
    char    **cmd;
    char    **path;

    dup2(pipe_fd[0], 0);
    dup2(fd_2, 1);
    cmd = ft_split(argv[3], ' ');
    path = path_find(env);
    line = f_getline(cmd[0], path);
    close(fd_2);
    close(pipe_fd[1]);
    close(pipe_fd[0]);
    execve(line, cmd, env);
}

int main(int argc, char **argv, char **env)
{
    int     fd_1;
    int     fd_2;
    int     pipe_fd[2];
    pid_t   pid;

    if (argc != 5)
    {
        ft_putstr_fd("\033[31mError:\e[0m Wrong number of arguments.\n", 2);
		ft_putstr_fd("Example: ./pipex file1 'cmd1' 'cmd2' file2\n", 2);
        exit(EXIT_SUCCESS);
    }
    check_fd(&fd_1, &fd_2, argv);
    if (pipe(pipe_fd) == -1)
        error_proc();
    pid = fork();
    if (pid == -1)
        error_proc();
    if (pid == 0)
        procc_fd1(pipe_fd, argv, env, fd_1);
    pid = fork();
    if (pid == -1)
        error_proc();
    if (pid == 0)
        procc_fd2(pipe_fd, argv, env, fd_2);
    close(fd_1);
    close(fd_2);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    wait(0);
    wait(0);
    return(0);
}