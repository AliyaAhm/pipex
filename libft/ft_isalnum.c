/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:22:21 by oshelba           #+#    #+#             */
/*   Updated: 2021/10/26 01:04:13 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= '0') && (c <= '9')) || ((c >= 'a')
			&& (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	return (0);
}