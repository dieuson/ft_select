/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distrib_tasks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:30:13 by dvirgile          #+#    #+#             */
/*   Updated: 2017/12/13 15:30:15 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void					set_style_move(int index, t_var *files)
{
	while (index > -1 && files)
	{
		if (files->index == index && files->disp_attribute == T_NORMAL)
			files->disp_attribute = T_UNDERLINE;
		else if (files->index == index && files->disp_attribute == T_REVERSE)
			files->disp_attribute = T_UNDERREVERSE;
		else if (files->index != index && files->disp_attribute == T_UNDERLINE)
			files->disp_attribute = T_NORMAL;
		else if (files->index != index &&
				files->disp_attribute == T_UNDERREVERSE)
			files->disp_attribute = T_REVERSE;
		files = files->next;
	}
}

static void				set_style_space(int index, t_var *files)
{
	while (index != -1 && files)
	{
		if (files->index == index && files->disp_attribute != T_UNDERREVERSE)
			files->disp_attribute = T_UNDERREVERSE;
		else if (files->index == index &&
				files->disp_attribute == T_UNDERREVERSE)
			files->disp_attribute = T_NORMAL;
		files = files->next;
	}
}

void					delete_element(void)
{
	FT_INIT(int, index, 0);
	FT_INIT(t_var*, prev, NULL);
	if (!g_select.files)
		return ;
	index = go_to_position(g_select.pos_x, g_select.pos_y, K_SPACE);
	prev = delete_index(index);
	if (prev && prev->next && prev->prev)
		index = prev->next->index;
	else if (prev && !prev->next && prev->prev)
	{
		index = prev->prev->index;
		g_select.pos_x = prev->prev->pos_x;
		g_select.pos_y = prev->prev->pos_y - 1;
	}
	else if (prev && prev->next && !prev->prev)
	{
		index = prev->index;
		g_select.pos_x = prev->pos_x - 1;
		g_select.pos_y = prev->pos_y - 1;
	}
	else
		FT_MULTI4(index, g_select.pos_x, g_select.pos_y, 1);
	set_style_move(index, g_select.files);
}

void					select_element(void)
{
	FT_INIT(int, index, 0);
	if (!g_select.files)
		return ;
	index = go_to_position(g_select.pos_x, g_select.pos_y, K_SPACE);
	set_style_space(index, g_select.files);
	set_style_move(index, g_select.files);
}

void					move_list(int key)
{
	if (key == K_RIGHT)
		g_select.pos_x += 1;
	else if (key == K_LEFT)
		g_select.pos_x -= 1;
	else if (key == K_UP && g_select.nb_elem > 1)
		g_select.pos_y -= 1;
	else if (key == K_DOWN && g_select.nb_elem > 1)
		g_select.pos_y += 1;
	FT_INIT(int, index, 0);
	if (!g_select.files)
		return ;
	if (g_select.nb_elem > 1)
		index = go_to_position(g_select.pos_x, g_select.pos_y, key);
	set_style_move(index, g_select.files);
}
