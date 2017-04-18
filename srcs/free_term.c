/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:32:50 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

 void			free_edition_line(void)
{
	if (s_select.win)
		free(s_select.win);
	if (s_select.c)
		free(s_select.c);
	if (s_select.lst_lst)
		free_lst_lst(s_select.lst_lst);
}

void				ft_reset_termios(struct termios t_back)
{
	tcsetattr(0, 0, &t_back);
	tputs(tgetstr("me", NULL), 1, ft_putchar_int);
	tputs(tgetstr("vs", NULL), 1, ft_putchar_int);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	if (!s_select.is_stop)
		free_edition_line();
	s_select.is_stop = false;
}
