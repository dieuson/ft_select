/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <dvirgile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by dvirgile          #+#    #+#             */
/*   Updated: 2017/02/24 18:35:03 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putstr(uint8_t *str)
{
	if (!str)
	{
		write(0, "(null)", 6);
		return (6);
	}
	write(0, str, ftp_strlen(str));
	return (ftp_strlen(str));
}
