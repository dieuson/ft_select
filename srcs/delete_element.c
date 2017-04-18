#include "../includes/ft_select.h"

t_var	*find_cell(int index)
{	
	FT_INIT(t_var*, files, s_select.files);
	if (index == -1 || !s_select.files)
		return (NULL);
	while (index != -1 && files && files->index != index)
		files = files->next;
	return (files);
}

static t_var 	*delete_cell_2(t_var *files, t_var *prev)
{
	if (prev && files->next && files->prev)
	{
		prev->next = files->next;
		ft_strdel(&files->name);
		free(files);
		files = NULL;
	}
	else if (!prev && files->next)
	{
		prev = files->next;
		prev->prev = NULL;
		ft_strdel(&files->name);
		free(files);
		files = NULL;
		s_select.files = prev;
	}
	return (prev);
}

t_var 	*delete_cell(t_var *files, t_var *prev, int index)
{
	if (files && files->index != index)
		return (delete_cell(files->next, files, index));
	else if (!files)
		return (NULL);
	if (!files->next)
	{
		ft_strdel(&files->name);
		free(files);
		files = NULL;
		if (prev)
		{
			prev->next = NULL;
			files = prev;
			s_select.pos_x = files->pos_x;
			s_select.pos_y = files->pos_y;
		}
		else
			s_select.files = NULL;
	}
	else
		prev = delete_cell_2(files, prev);
	return (prev);
}

t_var 	*delete_index(int index)
{
	FT_INIT(t_var*, files, s_select.files);
	FT_INIT(t_var*, prev, NULL);
	if (!s_select.files)
	{
		tputs(tgetstr("rc", NULL), 1, ft_putchar_int);
		tputs(tgetstr("clear", NULL),1,ft_putchar_int);
		ft_reset_termios(s_select.t_back);
		exit(0);
	}
	prev = delete_cell(files, prev, index);
	return (prev);
}