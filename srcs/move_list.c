#include "../includes/ft_select.h"

static int 			move_y(int pos_y, t_var *col)
{
	if (!col)
		return (-1);
	if (pos_y > col->len_col)
		s_select.pos_y = col->len_col;
	if (pos_y < 0)
		s_select.pos_y = 1;
	pos_y = s_select.pos_y;
	while (col && pos_y > 1)
	{
		pos_y--;
		col = col->next;
	}
	if (!col)
		return (-1);
	return (col->index_init);
}

static int 		check_positions_h(int pos_x, int pos_y, t_completion *lst_lst)
{	
	if (pos_x > lst_lst->nb_col)
	{
		s_select.pos_x = 1;
		s_select.pos_y++;
	}
	else if (pos_x <= 0 && pos_y == 1)
	{
		s_select.pos_x = s_select.last_h_x;
		s_select.pos_y = s_select.last_h_y;
	}
	else if (pos_x <= 0 && pos_y)
	{
		s_select.pos_x = lst_lst->nb_col;
		if ((s_select.pos_y - 1) > 0)
			s_select.pos_y--;
	}
	else
		return (1);
	return (0);
}

static int 		check_positions_v(int pos_x, int pos_y, t_completion *lst_lst)
{	
	if (pos_y <= 0 && pos_x == 1 && lst_lst)
	{
		s_select.pos_x = s_select.last_v_x;
		s_select.pos_y = s_select.last_v_y;
	}
	else if (pos_y > lst_lst->elem->len_col)
	{
		s_select.pos_x++;
		s_select.pos_y = 1;
	}
	else if (!pos_y)
	{
		s_select.pos_y = s_select.last_h_y;
		s_select.pos_x--;
	}
	else if (pos_x == s_select.last_v_x && pos_y >= s_select.last_h_y)
	{
		s_select.pos_y = 1;
		s_select.pos_x = 1;
	}
	else
		return (1);
	return (0);
}

static int 			move_x(int pos_x, int pos_y, int key)
{
	FT_INIT(t_completion *, lst_lst, s_select.lst_lst);
	if (!lst_lst)
		return (-1);
	if ((key == K_RIGHT || key == K_LEFT) &&
			!check_positions_h(pos_x, pos_y, lst_lst))
		return (move_x(s_select.pos_x, s_select.pos_y, key));
	else if ((key == K_UP || key == K_DOWN) &&
			!check_positions_v(pos_x, pos_y, lst_lst))
		return (move_x(s_select.pos_x, s_select.pos_y, key));
	while (lst_lst && pos_x > 1)
	{
		pos_x--;
		lst_lst = lst_lst->next;
	}
	if (!lst_lst)
		return (-1);
	if (pos_y > lst_lst->elem->len_col && key == K_RIGHT)
	{
		s_select.pos_y = 1;
		s_select.pos_x = 1;
		return (move_x(1, 1, key));
	}

	return (move_y(pos_y, lst_lst->elem));
}


int 			go_to_position(int pos_x, int pos_y, int key)
{
	FT_INIT(int, index, 0);
	FT_INIT(t_var*, files, s_select.files);
	if (!files)
		return (-1);
	index = move_x(pos_x, pos_y, key);
	return (index);
}