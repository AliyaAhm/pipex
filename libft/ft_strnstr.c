/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:45:12 by oshelba           #+#    #+#             */
/*   Updated: 2021/10/23 22:10:16 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)hays);
	while (hays[i] && i < len)
	{
		j = 0;
		while (hays[i + j] && needle[j] && ((i + j) < len) \
		&& needle[j] == hays[i + j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&hays[i]);
		if (hays[i + j] == '\0' || (i + j) == len)
			return (NULL);
		i++;
	}
	return (0);
}