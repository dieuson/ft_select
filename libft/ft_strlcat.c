/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:33:25 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	i_dst;

	i = 0;
	j = 0;
	i_dst = 0;
	if (dst)
	{
		while (dst[i] != '\0' && i < size)
		{
			i++;
			i_dst++;
		}
		while (src[j] != '\0' && i < size - 1)
			dst[i++] = src[j++];
		if (i < size)
			dst[i] = '\0';
	}
	return (i_dst + ft_strlen(src));
}
