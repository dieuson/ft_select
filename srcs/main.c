/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:48:10 by dvirgile          #+#    #+#             */
/*   Updated: 2017/12/13 15:48:11 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int				is_arrow(int key)
{
	if (key == K_DOWN || key == K_UP || key == K_LEFT || key == K_RIGHT)
		return (1);
	return (0);
}

static int				return_values(t_var *files)
{
	FT_INIT(t_var*, head, files);
	if (!files)
		return (int_error("files", "empty files list"));
	tputs(tgetstr("ho", NULL), 1, ft_putchar_int);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_int);
	while (files)
	{
		if (files->disp_attribute == T_UNDERREVERSE ||
				files->disp_attribute == T_REVERSE)
		{
			ft_putstr_fd(files->name, 1);
			if (files->next)
				ft_putstr_fd(" ", 1);
		}
		files = files->next;
	}
	if (s_select.lst_lst)
		free_lst_lst(s_select.lst_lst);
	s_select.lst_lst = NULL;
	if (head)
		free_files_list(head);
	ft_putstr_fd("\n", 1);
	return (1);
}

int						select_loop(void)
{
	FT_INIT(int, key, 0);
	while (42)
	{
		display_elements(s_select.files);
		if (!s_select.files)
			return (return_values(s_select.files));
		key = readkey();
		if (key == K_RETURN)
			return (return_values(s_select.files));
		else if (is_arrow(key) && s_select.running)
			move_list(key);
		else if (key == K_SPACE && s_select.running)
			select_element();
		else if (key == K_BACKSP && s_select.running)
			delete_element();
		else if (key == K_ESCAPE)
			return (0);
		s_select.last_v_x = 0;
		s_select.last_v_y = 0;
		s_select.last_h_x = 0;
		s_select.last_h_y = 0;
	}
	return (1);
}

int						main(int argc, char **argv, char **envp)
{
	if (argc <= 1 || !argv)
		return (int_error("files", "No Arguments"));
	else if (!envp)
		return (int_error("Env", "No environnement"));
	if (!(init_all()))
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
