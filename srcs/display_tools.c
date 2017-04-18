#include "../includes/ft_select.h"

static int 	get_len_col_elem(t_completion *lst_lst, int pos_x)
{
	FT_INIT(int, len_col, 0);
	FT_INIT(t_var*, col, NULL);
	while (lst_lst)
	{
		col = lst_lst->elem;
		while (col)
		{
			if (col && col->pos_x == pos_x)
				if (col->pos_y > len_col)
					len_col = col->pos_y;
			col = col->next;
		}
		lst_lst = lst_lst->next;
	}
	return (len_col);
}

int		if_col(t_var *col, char *tmp,
								int len_str, t_completion *all_col)
{
	FT_INIT(int, nb_elem, -1);
	FT_INIT(int, len_current_line, 1);
	if (all_col && all_col && (all_col)->elem)
		len_current_line = (all_col)->elem->len_col;
	while (col && all_col)
	{
		if (col && (col->disp_attribute == T_UNDERLINE ||
			col->disp_attribute == T_UNDERREVERSE))
		{
			s_select.len_current_line = len_current_line;
			s_select.len_current_col =
				get_len_col_elem(s_select.lst_lst, col->pos_x);
		}
		tmp = set_sentence(tmp, len_str, col);
		col = col->next;
	}
	ft_putendl("");
	return (nb_elem);
}