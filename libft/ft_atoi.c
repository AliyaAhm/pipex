/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:29:06 by oshelba           #+#    #+#             */
/*   Updated: 2021/10/26 01:03:16 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static long	ft_maxmin(char *s, int minus)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if ((((nb * 10) + (s[i] - '0')) < nb) && minus == 1)
			return (-1);
		else if ((((nb * 10) + (s[i] - '0')) < nb) && minus == -1)
			return (0);
		nb = (nb * 10) + (s[i] - '0');
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	int			minus;
	long		res;
	int			i;
	char		*s;

	i = 0;
	res = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'\
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	s = (char *)str;
	res = minus * ft_maxmin(&s[i], minus);
	return ((int)res);
}