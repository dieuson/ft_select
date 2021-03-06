/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <dvirgile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by dvirgile          #+#    #+#             */
/*   Updated: 2017/02/24 18:34:39 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_nb(const char *str, int *i)
{
	int	ret;

	ret = 0;
	if (str[*i] == '.')
		*i += 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret *= 10;
		ret += str[*i] - '0';
		*i += 1;
	}
	return (ret);
}
