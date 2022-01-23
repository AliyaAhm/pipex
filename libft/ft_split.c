/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:42:48 by oshelba           #+#    #+#             */
/*   Updated: 2021/10/25 19:47:49 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	ft_cntwd(char const *s, char c)
{
	int	i;
	int	count_of_word;

	i = 0;
	count_of_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_of_word++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count_of_word);
}

char	*ft_word(char const *s, char c, int i)
{
	int		len_of_word;
	char	*word;

	len_of_word = 0;
	while (s[i + len_of_word] && s[i + len_of_word] != c)
		len_of_word++;
	word = (char *)malloc(sizeof(char) * (len_of_word + 1));
	return (word);
}

char	**ft_needle(char const *s, char c, char **arrayword)
{
	int	k;
	int	i;
	int	j;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arrayword[k] = ft_word(s, c, i);
			if (!(arrayword[k]))
				ft_error(arrayword);
			j = 0;
			while (s[i] && s[i] != c)
				arrayword[k][j++] = s[i++];
			arrayword[k++][j] = '\0';
		}
		else
			i++;
	}
	arrayword[k] = NULL;
	return (arrayword);
}

char	**ft_split(char const *s, char c)
{
	char	**arrayword;
	int		l;

	if (!s)
		return (NULL);
	l = ft_cntwd(s, c);
	arrayword = (char **)malloc(sizeof(char *) * (l + 1));
	if (!arrayword)
		return (NULL);
	return (ft_needle(s, c, arrayword));
}