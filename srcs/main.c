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

int				is_arrow(int key)
{
	if (key == K_DOWN || key == K_UP || key == K_LEFT || key == K_RIGHT)
		return (1);
	return (0);
}

int 					return_values(t_var *files)
{
	FT_INIT(t_var*, head, files);
	if (!files)
		return (int_error("files", "empty files list"));
	ft_putendl("");
	while (files)
	{
		if (files->disp_attribute == T_UNDERREVERSE ||
				files->disp_attribute == T_REVERSE)
		{
					
			ft_printf("%s", files->name);
			if (files->next)
				ft_putstr(" ");
		}
		files = files->next;
	}
	if (head)
		free_files_list(head);
	ft_putstr("\n");
	return (1);
}

int 					select_loop(void)
{
	FT_INIT(int, key, 0);
	tputs(tgetstr("clear", NULL),1,ft_putchar_int);
	tputs(tgetstr("sc", NULL), 1, ft_putchar_int);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_int);
	while (42)
	{
		display_completion(s_select.files);
		key = readkey();
		if (key == K_RETURN)
			return (return_values(s_select.files));
		else if (is_arrow(key))
			move_list(key);
		else if (key == K_SPACE)
			select_element();
		else if (key == K_BACKSP)
			delete_element();
		else if (key == K_ESCAPE)
			return (0);
	}
	return (1);
}

int						main(int argc, char **argv, char **envp)
{
	if (argc <= 1 || !argv || !envp)
		return (0);
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
