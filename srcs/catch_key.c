/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:33:04 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int		detect_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 67)
		return (K_RIGHT);
	else if (key[0] == 27 && key[1] == 91 && key[2] == 68)
		return (K_LEFT);
	else if (key[0] == 27 && key[1] == 91 && key[2] == 65)
		return (K_UP);
	else if (key[0] == 27 && key[1] == 91 && key[2] == 66)
		return (K_DOWN);
	else if (key[0] == 27 && key[1] == 91 && key[2] == 51 && key[3] == 126)
		return (K_BACKSP);
	else if (key[0] == 27 && !key[1])
		return (K_ESCAPE);
	return (K_UNKNOWN);
}

int				readkey(void)
{
	FT_INIT(char*, c, s_select.c);
	ft_bzero(c, 16);
	if (read(STDIN_FILENO, c, 15))
	{
		if (c[0] == 27)
			return (detect_arrow(c));
	}
	if (c[0] == 32)
		return (K_SPACE);
	else if (c[0] == 127)
		return (K_BACKSP);
	else if (c[0] == 10)
		return (K_RETURN);
	else if (c[0] == 4)
		return (K_ESCAPE);
	return (K_UNKNOWN);
}
