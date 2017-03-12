/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:32:44 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int 		termios_error(int error_type)
{
	if (error_type == 1)
		ft_putstr_fd("No Term found\n", 2);
	else if (error_type == 2)
		ft_putstr_fd("Unvalid term\n", 2);
	return (0);
}

int		init_termios(struct termios my_termios)
{
	FT_INIT(char*, term_name, NULL);
	if ((term_name = getenv("TERM")) == NULL)
		return (termios_error(1));
	if (tgetent(NULL, term_name) == ERR)
		return (termios_error(2));
	tputs(tgetstr("clear", NULL),1,ft_putchar_int);
	tputs(tgetstr("sc", NULL), 1, ft_putchar_int);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_int);
	tcgetattr(STDIN_FILENO, &my_termios);
	my_termios.c_lflag &= ~ICANON;
	my_termios.c_lflag &= ~ECHO;
	my_termios.c_cc[VMIN] = 1;
	my_termios.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &my_termios);
	return (1);
}
