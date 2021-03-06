/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:47:23 by dvirgile          #+#    #+#             */
/*   Updated: 2017/12/13 15:47:23 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		display_form(t_completion *all_col,
				int nb_elem, int len_str, int nb_col)
{
	FT_INIT(t_var *, col, all_col->elem);
	FT_INIT(char *, tmp, NULL);
	tmp = ft_strnew(g_select.len_str + 100);
	while (all_col && nb_elem)
	{
		col = all_col->elem;
		if_col(col, tmp, len_str, all_col);
		all_col = all_col->next;
	}
	ft_strdel(&tmp);
	if (nb_col)
		return ;
}

static float	*get_display_values(int nb_elem, int len)
{
	FT_INIT(float*, tab_val, (float*)malloc(sizeof(float) * 6));
	tab_val[0] = (float)nb_elem;
	tab_val[1] = (float)len;
	tab_val[2] = arrondi(g_select.win->ws_col / (tab_val[1] + 2));
	tab_val[3] = g_select.win->ws_row;
	tab_val[4] = ft_nb_elem_lst(tab_val[0], tab_val[2]);
	tab_val[5] = g_select.win->ws_row;
	return (tab_val);
}

static	int		ask_to_show_data(float *disp_val)
{
	FT_INIT(int, max_elem_lst, disp_val[5]);
	FT_INIT(int, elem_lst, disp_val[4]);
	FT_INIT(int, nb_rows, g_select.nb_rows);
	FT_INIT(int, len_line, (g_select.len_str + 2));
	if (max_elem_lst < elem_lst || (nb_rows > 0
		&& nb_rows > g_select.win->ws_row)
		|| len_line > g_select.win->ws_col)
	{
		g_select.running = 0;
		return (int_error("Window", "Too small window"));
	}
	g_select.running = 1;
	return (1);
}

void			display_elements(t_var *match_files)
{
	if (!match_files)
		return (void_error("Data", "no arguments to display"));
	FT_INIT(float*, disp_val,
			get_display_values(g_select.nb_elem, g_select.len_str));
	FT_INIT(t_completion *, lst_lst, NULL);
	FT_INIT(t_completion*, tmp_lst, NULL);
	FT_INIT(float, nb_col, disp_val[2]);
	FT_INIT(float, nb_elem_lst, disp_val[4]);
	tputs(tgetstr("ho", NULL), 1, ft_putchar_int);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_int);
	if (!ask_to_show_data(disp_val))
		return (free(disp_val));
	if (g_select.lst_lst)
	{
		free_lst_lst(g_select.lst_lst);
		g_select.lst_lst = NULL;
	}
	lst_lst = build_lst_lst(match_files, (nb_elem_lst == 0 ?
			1 : nb_elem_lst), nb_col);
	g_select.lst_lst = build_lst_lst(match_files, (nb_elem_lst == 0 ?
				1 : nb_elem_lst), nb_col);
	tmp_lst = lst_lst;
	display_form(lst_lst, disp_val[0], disp_val[1], disp_val[2]);
	free(disp_val);
	free_lst_lst(tmp_lst);
}
