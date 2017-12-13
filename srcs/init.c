/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:47:57 by dvirgile          #+#    #+#             */
/*   Updated: 2017/12/13 15:47:58 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static struct winsize		*init_win(void)
{
	struct winsize *win;

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

static int					init_struct(void)
{
	g_select.cursor = 0;
	g_select.nb_rows = 0;
	g_select.len_str = 0;
	g_select.nb_elem = 0;
	g_select.lst_lst = NULL;
	g_select.pos_x = 1;
	g_select.pos_y = 1;
	g_select.index = 0;
	g_select.len_current_col = 0;
	g_select.len_current_line = 0;
	g_select.running = 1;
	g_select.is_stop = false;
	if (!(g_select.win = init_win()))
		return (int_error("malloc", "init win"));
	g_select.c = ft_strnew(16);
	tcgetattr(STDIN_FILENO, &g_select.t_back);
	if (!init_termios(g_select.my_termios))
		return (0);
	return (1);
}

int							init_all(void)
{
	ft_signal();
	if (!(init_struct()))
		return (int_error("init all", "Error init struct select"));
	return (1);
}
