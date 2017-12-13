/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <dvirgile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by dvirgile          #+#    #+#             */
/*   Updated: 2017/02/24 18:34:18 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_fillstr2(long int nb, char *str, int i)
{
	int			temp;
	int			size;

	temp = nb;
	size = 1;
	while (temp / 10 > 0)
	{
		size = size * 10;
		temp = temp / 10;
	}
	while (size > 0)
	{
		temp = 0;
		temp = nb / size;
		nb = nb % size;
		size = size / 10;
		str[i] = '0' + temp;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_ltoa(long int nb)
{
	int			i;
	char		*str;

	str = (char *)malloc(13);
	i = 0;
	if (nb < 0)
	{
		str[i] = '-';
		nb = -nb;
		i++;
	}
	str = ft_fillstr2(nb, str, i);
	return (str);
}
