/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <dvirgile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by dvirgile          #+#    #+#             */
/*   Updated: 2017/02/24 18:33:45 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrspace(char const *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		ft_putchar(s[x]);
		x++;
	}
	ft_putchar(' ');
}
