/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_list_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:42:37 by dvirgile          #+#    #+#             */
/*   Updated: 2017/12/13 15:42:40 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int	check_positions_h_2(int pos_x, int pos_y)
{
	if (pos_y == s_select.last_v_y && pos_x > s_select.last_v_x)
		FT_MULTI3(s_select.pos_x, s_select.pos_y, 1);
	else if (pos_x <= 0 && pos_y == 1)
	{
		s_select.pos_x = s_select.last_v_x;
		s_select.pos_y = s_select.last_v_y;
	}
	else if (pos_x <= 0 && pos_y)
	{
		s_select.pos_x = s_select.last_h_x;
		s_select.pos_y = (s_select.pos_y > 1) ? s_select.pos_y - 1 : pos_y;
	}
	else if (pos_y > s_select.last_v_y)
		s_select.pos_y = 1;
	else
		return (1);
	return (0);
}

int			check_positions_h(int pos_x, int pos_y)
{
	if (pos_x > s_select.last_h_x)
	{
		if (pos_x > s_select.last_h_x && pos_y == s_select.last_v_y)
			FT_MULTI3(s_select.pos_x, s_select.pos_y, 1);
		else
		{
			s_select.pos_x = 1;
			s_select.pos_y++;
		}
	}
	else
		return (check_positions_h_2(pos_x, pos_y));
	return (0);
}

int			check_positions_v(int pos_x, int pos_y,
			t_completion *lst_lst, int key)
{
	if (pos_y <= 0 && pos_x == 1 && lst_lst)
	{
		s_select.pos_x = s_select.last_h_x;
		s_select.pos_y = s_select.last_h_y;
	}
	else if (pos_y <= 0 && pos_x > 1)
	{
		s_select.pos_y = (s_select.pos_x > (s_select.last_v_x + 1)) ?
							s_select.last_h_y : s_select.last_v_y;
		s_select.pos_x--;
	}
	else if (s_select.len_current_col > 0 &&
		pos_y >= s_select.len_current_col && key == K_DOWN)
	{
		if (pos_x == s_select.last_h_x && pos_y > s_select.last_h_y)
			FT_MULTI3(s_select.pos_x, s_select.pos_y, 1);
		else
		{
			s_select.pos_x++;
			s_select.pos_y = 1;
		}
	}
	else
		return (1);
	return (0);
}
