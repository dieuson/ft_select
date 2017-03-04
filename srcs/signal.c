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
}

void		ft_sigint(int sig)
{
	(void)sig;
}

void		ft_sigkill(int sig)
{
	(void)sig;
	exit(0);
}

void		ft_signal(void)
{
	signal(SIGWINCH, ft_sigwinch);
	signal(SIGINT, ft_sigint);
}
