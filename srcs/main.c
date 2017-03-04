/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:32:48 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int 					return_values(t_var *files)
{
	FT_INIT(t_var*, head, files);
	if (!files)
		return (int_error("files", "empty files list"));
	while (files)
	{
		ft_printf("%s", files->name);
		if (files->next)
			ft_putstr(" ");
		files = files->next;
	}
	free_files_list(head);
	ft_putstr("\n");
	return (1);
}

int 					select_loop(void)
{
	FT_INIT(int, key, 0);
	while (42)
	{
		key = readkey();
		display_completion(s_select.files);
		if (key == K_RETURN)
			return (return_values(s_select.files));
	}
	return (1);
}

int						main(int argc, char **argv, char **envp)
{
	if (!(init_all()))
	{
		ft_reset_termios(s_select.t_back);
		return (0);
	}
	if (!argc || !argv || !envp)
	{
		ft_reset_termios(s_select.t_back);
		return (0);
	}
	if (!(s_select.files = get_files(argv + 1)))
	{
		ft_reset_termios(s_select.t_back);
		return (int_error("files", "No Arguments"));
	}
	select_loop();
	ft_reset_termios(s_select.t_back);
	return (0);
}
