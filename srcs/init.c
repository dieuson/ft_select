/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:32:50 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static struct winsize		*init_win(void)
{
	struct winsize 	*win;

	win = (struct winsize*)malloc(sizeof(struct winsize));
	if (!win)
		return (NULL);
	win->ws_row = 0;
	win->ws_col = 0;
	win->ws_xpixel = 0;
	win->ws_ypixel = 0;
	ioctl(0, TIOCGWINSZ, win);
	return (win);
}


static int 					init_struct(void)
{
	s_select.cursor = 0;
	s_select.nb_rows = 0;
	s_select.len_str = 0;
	s_select.nb_elem = 0;
	if (!(s_select.win = init_win()))
		return (int_error("malloc", "init win"));
	s_select.c = ft_strnew(16);
	tcgetattr(STDIN_FILENO, &s_select.t_back);
	init_termios(s_select.my_termios);
	return (1);
}

int							init_all(void)
{
	ft_signal();
	if (!(init_struct()))
		return (int_error("init all", "Error init struct select"));
	return (1);
}
