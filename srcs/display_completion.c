/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_completion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:35:46 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		display_form(t_completion *all_col, int nb_elem, int len_str, int nb_col)
{
	FT_INIT(t_var *, col, all_col->elem);
	FT_INIT(char *, tmp, NULL);
	tmp = ft_strnew(s_select.len_str + 100);
	while (all_col && nb_elem)
	{
		col = all_col->elem;
		if_col(col, tmp, len_str, &all_col);
		all_col = all_col->next;
	}
	ft_strdel(&tmp);
	ft_putendl("");
	if (nb_col)
		return ;
}

static float	*get_display_values(int nb_elem, int len)
{
	FT_INIT(float*, tab_val, (float*)malloc(sizeof(float) * 6));
	tab_val[0] = (float)nb_elem;
	tab_val[1] = (float)len;
	tab_val[2] = arrondi(s_select.win->ws_col / (tab_val[1] + 2));
	tab_val[3] = s_select.win->ws_row;
	tab_val[4] = ft_nb_elem_lst(tab_val[0], tab_val[2]);
	tab_val[5] = s_select.win->ws_row;
	return (tab_val);
}

static	int		ask_to_show_data(float *disp_val)
{
	FT_INIT(int, max_elem_lst, disp_val[5]);
	FT_INIT(int, elem_lst, disp_val[4]);
	static int i = 0;

	i++;
	if (max_elem_lst < elem_lst || (s_select.len_str + 2) > s_select.win->ws_col)
	{
		s_select.running = 0;
		return (int_error("Window", "Too small window"));
	}
	s_select.running = 1;
	return (1);
}


void			display_completion(t_var *match_files)
{
	if (!match_files)
		return (void_error("Data", "no arguments to display"));
	FT_INIT(float*, disp_val, get_display_values(s_select.nb_elem, s_select.len_str));
	FT_INIT(t_completion *, lst_lst, NULL);
	FT_INIT(t_completion*, tmp_lst, NULL);
	FT_INIT(float, nb_col, disp_val[2]);
	FT_INIT(float, nb_elem_lst, disp_val[4]);
	tputs(tgetstr("rc", NULL), 1, ft_putchar_int);
	tputs(tgetstr("clear", NULL),1,ft_putchar_int);
	if (!ask_to_show_data(disp_val))
	{
		free(disp_val);
		return ;
	}
	if (s_select.lst_lst)
	{
		free_lst_lst(s_select.lst_lst);
		s_select.lst_lst = NULL;
	}
	lst_lst = build_lst_lst(match_files, (nb_elem_lst == 0 ?
			1 : nb_elem_lst), nb_col);
	s_select.lst_lst = build_lst_lst(match_files, (nb_elem_lst == 0 ?
			1 : nb_elem_lst), nb_col);
	tmp_lst = lst_lst;
	display_form(lst_lst, disp_val[0], disp_val[1], disp_val[2]);
	free_lst_lst(tmp_lst);
	free(disp_val);
}
