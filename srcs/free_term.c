/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:47:40 by dvirgile          #+#    #+#             */
/*   Updated: 2017/12/13 15:47:42 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void				free_edition_line(void)
{
	if (g_select.win)
		free(g_select.win);
	if (g_select.c)
		free(g_select.c);
	if (g_select.lst_lst)
		free_lst_lst(g_select.lst_lst);
}

void				ft_reset_termios(struct termios t_back)
{
	tcsetattr(0, 0, &t_back);
	tputs(tgetstr("me", NULL), 1, ft_putchar_int);
	tputs(tgetstr("vs", NULL), 1, ft_putchar_int);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	if (!g_select.is_stop)
		free_edition_line();
	g_select.is_stop = false;
}
