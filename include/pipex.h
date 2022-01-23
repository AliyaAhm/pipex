#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>

void    procc_fd1(int pipe_fd, char **argv, char **env, int fd_1);
char    **find_path(char **env);
void    check_fd(int *fd_1, int *fd_2, char **argv);
void    error_proc();

#endif
