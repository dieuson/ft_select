/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <dvirgile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by dvirgile          #+#    #+#             */
/*   Updated: 2017/02/24 18:33:05 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_bin(unsigned int nbr)
{
	if (nbr <= 64)
		return (1);
	else if (nbr <= 1024)
		return (2);
	else if (nbr <= 32768)
		return (3);
	else
		return (4);
}
