/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:47:05 by dvirgile          #+#    #+#             */
/*   Updated: 2017/12/13 15:47:05 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static t_var		*create_elem(t_var *elem, int pos_x, int pos_y)
{
	FT_INIT(t_var*, cell, NULL);
	if (!(cell = (t_var*)malloc(sizeof(t_var))))
		return (var_error("malloc", "create_elem"));
	cell->name = ft_strdup(elem->name);
	cell->disp_attribute = elem->disp_attribute;
	elem->pos_x = pos_x + 1;
	elem->pos_y = pos_y + 1;
	cell->index_init = elem->index;
	cell->index = pos_x;
	cell->pos_x = pos_x + 1;
	cell->pos_y = pos_y + 1;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}

static t_completion	*create_cell(t_var *elem, int pos_y)
{
	FT_INIT(t_completion *, new_cell, NULL);
	if (!(new_cell = (t_completion*)malloc(sizeof(t_completion))))
		return (completion_error("malloc", "create_cell"));
	new_cell->elem = elem;
	new_cell->pos_y = pos_y;
	new_cell->next = NULL;
	return (new_cell);
}

static t_var		*build_col(t_var **match_files, int nb_elem_lst, int pos_y)
{
	FT_INIT(t_var *, col, NULL);
	FT_INIT(t_var *, head_col, NULL);
	FT_INIT(int, pos_x, 0);
	while (match_files && (*match_files) && nb_elem_lst > 0)
	{
		if (!col)
			MULTI(head_col, col, create_elem(*match_files, pos_x, pos_y));
		else
		{
			col->next = create_elem(*match_files, pos_x, pos_y);
			col = col->next;
		}
		nb_elem_lst--;
		pos_x++;
		(*match_files) = (*match_files)->next;
	}
	if (pos_x >= s_select.last_h_x && pos_y >= s_select.last_h_y)
	{
		s_select.last_h_x = pos_x;
		s_select.last_h_y = pos_y ? pos_y : 1;
	}
	head_col->len_col = pos_x;
	return (head_col);
}

t_completion		*build_lst_lst(t_var *match_files, int nb_elem, int nb_col)
{
	FT_INIT(t_completion *, all_col, NULL);
	FT_INIT(t_completion *, head_all_col, NULL);
	FT_INIT(t_var *, tmp, NULL);
	FT_INIT(int, pos_y, 1);
	while (match_files && nb_elem > 0)
	{
		tmp = build_col(&match_files, nb_col, pos_y);
		if (!all_col)
			MULTI(head_all_col, all_col, create_cell(tmp, pos_y));
		else
		{
			all_col->next = create_cell(tmp, pos_y);
			all_col = all_col->next;
		}
		pos_y++;
		nb_elem--;
	}
	all_col->next = NULL;
	if (all_col->elem)
		s_select.last_v_x = all_col->elem->len_col;
	s_select.last_v_y = pos_y ? pos_y - 1 : 1;
	head_all_col->nb_col = pos_y;
	s_select.nb_rows = pos_y;
	return (head_all_col);
}
