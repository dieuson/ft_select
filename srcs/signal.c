/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <dvirgile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:18:58 by dvirgile          #+#    #+#             */
/*   Updated: 2017/03/02 17:38:40 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_sigwinch(int sig)
{
	(void)sig;
	ioctl(0, TIOCGWINSZ, s_select.win);
	tputs(tgetstr("ho", NULL), 1, ft_putchar_int);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_int);
	display_elements(s_select.files);
}

void		ft_sigstop(int sig)
{
	s_select.t_back.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &s_select.t_back);
	tputs(tgetstr("me", NULL), 1, ft_putchar_int);
	tputs(tgetstr("vs", NULL), 1, ft_putchar_int);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	s_select.is_stop = true;
	ft_reset_termios(s_select.t_back);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");
	tputs(tgetstr("clear", NULL),1,ft_putchar_int);
	(void)sig;
}

void		ft_sigkill(int sig)
{
	(void)sig;
	ft_reset_termios(s_select.t_back);
	tputs(tgetstr("clear", NULL),1,ft_putchar_int);
	exit(0);
}

void		ft_segfault(int sig)
{
	(void)sig;
	ft_reset_termios(s_select.t_back);
	ft_putstr("Segfault\n");
	exit(0);
}

void 		ft_wake_up(int sig)
{
	tputs(tgetstr("clear", NULL),1,ft_putchar_int);
	signal(SIGTSTP, ft_sigstop);
	init_termios(s_select.my_termios);
	display_elements(s_select.files);
	(void)sig;	
}

void		ft_signal(void)
{
	signal(SIGWINCH, ft_sigwinch);
	signal(SIGTSTP, ft_sigstop);
	signal(SIGCONT, ft_wake_up);
//	signal(SIGKILL, ft_sigkill);
//	signal(SIGQUIT, ft_sigkill);
	signal(SIGINT, ft_sigkill);
//	signal(SIGINT, ft_sigstop);
//	signal(SIGSEGV, ft_segfault);
}
