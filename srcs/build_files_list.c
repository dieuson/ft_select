#include "../includes/ft_select.h"

t_var 					*create_var_cell(char *name)
{
	FT_INIT(t_var*, cell, NULL);
	if (!(cell = (t_var*)malloc(sizeof(t_var))))
		return (var_error("malloc", "create_cell"));
	if (ft_strrchr(name, '/') && (int)ft_strlen(ft_strrchr(name, '/') + 1))
		name = ft_strrchr(name, '/') + 1;
	cell->name = ft_strdup(name);
	cell->disp_attribute = T_NORMAL;
	cell->index = 0;
	cell->pos_x = 0;
	cell->pos_y = 0;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}

void			free_files_list(t_var *files)
{
	FT_INIT(t_var*, tmp, NULL);
	if (!files)
		return ;
	while (files)
	{
		ft_strdel(&(files->name));
		tmp = files;
		files = files->next;
		if (tmp)
			free(tmp);
	}
}

t_var 					*get_files(char **argv)
{
	FT_INIT(t_var*, files, NULL);
	FT_INIT(t_var*, head, NULL);
	FT_INIT(int, i, 0);
	FT_INIT(int, max_len, 0);
	while (argv && argv[i])
	{
		if ((int)ft_strlen(argv[i]))
		{
			if (!files)
				MULTI(head, files, create_var_cell(argv[i]));
			else
			{
				files->next = create_var_cell(argv[i]);
				files->prev = files;
				files = files->next;
			}
			if (files)
			{
				max_len = max_len > (int)ft_strlen(files->name)
						? max_len : (int)ft_strlen(files->name);
				files->index = i;
			}
		}
		i++;
	}
	s_select.len_str = max_len;
	s_select.nb_elem = i;
	if (head)
		head->disp_attribute = T_UNDERLINE;
	return (head);
}