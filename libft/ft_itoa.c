/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:34:34 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_size(int n)
{
	int size;

	size = 0;
	if (!n)
		return (0);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	sign = ft_sign(n);
	str = (char*)malloc(sizeof(str) * (ft_size(n) + sign + 1));
	if (!str)
		return (NULL);
	if (sign == 1)
		n = -n;
	i = ft_size(n) + sign;
	str[i] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (n != 0)
	{
		str[--i] = ((n % 10) + '0');
		n /= 10;
	}
	if (sign == 1)
		str[--i] = '-';
	return (str);
}
