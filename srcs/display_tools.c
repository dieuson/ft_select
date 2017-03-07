#include "../includes/ft_select.h"

t_completion	*change_col(t_completion *all_col, t_completion *head,
					int *ref_col, int *nb_elem)
{
	(*ref_col)++;
	if (all_col && all_col->next)
		all_col = all_col->next;
	else
	{
		if (*nb_elem)
		{
			*ref_col = 0;
			all_col = head;
			(*nb_elem)--;
			if (all_col && all_col->next)
				ft_putendl("");
		}
	}
	return (all_col);
}

int		if_col(t_var *col, char *tmp,
								int len_str, t_completion **all_col)
{
	FT_INIT(int, nb_elem, -1);
	FT_INIT(t_var *, tmp_col, NULL);
	if (col)
	{
		tmp = set_sentence(tmp, len_str, col);
		tmp_col = col;
		col = col->next;
		ft_strdel(&(tmp_col)->name);
		free(tmp_col);
		(*all_col)->elem = col;
	}
	return (nb_elem);
}