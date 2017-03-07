/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:36:48 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static t_var 					*create_elem(t_var *elem, int index)
{
	FT_INIT(t_var*, cell, NULL);
	if (!(cell = (t_var*)malloc(sizeof(t_var))))
		return (var_error("malloc", "create_cell"));	
	cell->name = ft_strdup(elem->name);
	cell->disp_attribute = elem->disp_attribute;
	cell->index_init = elem->index;
	cell->index = index;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}

static t_completion	*create_cell(t_var *elem, int index)
{
	FT_INIT(t_completion *, new_cell, NULL);
	new_cell = (t_completion*)malloc(sizeof(t_completion));
	new_cell->elem = elem;
	new_cell->index = index;
	new_cell->next = NULL;
	return (new_cell);
}

static t_var	*build_col(t_var **match_files, int nb_elem_lst, int col_numb)
{
	FT_INIT(t_var *, col, NULL);
	FT_INIT(t_var *, head_col, NULL);
	FT_INIT(int, index, 0);
	while (match_files && (*match_files) && nb_elem_lst > 0)
	{
		if (!col)
			MULTI(head_col, col, create_elem(*match_files, index));
		else
		{
			col->next = create_elem(*match_files, index);
			col = col->next;
		}
		nb_elem_lst--; 
		index++;
		(*match_files) = (*match_files)->next;
	}
	if (col)
		col->next = NULL;
	s_select.last_h_x = index >= s_select.last_h_y ? col_numb + 1
							: s_select.last_h_x;
	s_select.last_h_y = index >= s_select.last_h_y ? index : s_select.last_h_y;
	head_col->len_col = index;
	return (head_col);
}

t_completion	*build_lst_lst(t_var *match_files, int nb_elem, int nb_col)
{
	FT_INIT(t_completion *, all_col, NULL);
	FT_INIT(t_completion *, head_all_col, NULL);
	FT_INIT(t_var *, tmp, NULL);
	FT_INIT(int, col_numb, 0);
	while (match_files && nb_col > 0)
	{
		tmp = build_col(&match_files, nb_elem, col_numb);
		if (!all_col)
			MULTI(head_all_col, all_col, create_cell(tmp, col_numb));
		else
		{
			all_col->next = create_cell(tmp, col_numb);
			all_col = all_col->next;
		}
		col_numb++;
		nb_col--;
	}
	all_col->next = NULL;
	s_select.last_v_x = col_numb;
	s_select.last_v_y = all_col->elem->len_col;
	head_all_col->nb_col = col_numb;
	return (head_all_col);
}
