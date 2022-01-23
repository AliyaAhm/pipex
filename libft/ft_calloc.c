/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:34:17 by oshelba           #+#    #+#             */
/*   Updated: 2021/10/22 21:27:18 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	mem;

	if (size == 0)
		mem = count;
	else
		mem = count * size;
	p = malloc(mem);
	if (!p)
		return (NULL);
	return (ft_memset(p, 0, mem));
}