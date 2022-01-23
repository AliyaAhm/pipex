/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:29:27 by oshelba           #+#    #+#             */
/*   Updated: 2021/10/23 11:08:33 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dst);
}