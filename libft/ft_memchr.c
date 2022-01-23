/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:27:46 by oshelba           #+#    #+#             */
/*   Updated: 2021/10/23 13:53:47 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			val;
	char			*str;

	i = 0;
	val = (char)c;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == val)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}