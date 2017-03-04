#include "../includes/ft_select.h"

static t_var 					*create_cell(char *name)
{
	FT_INIT(t_var*, cell, NULL);
	if (!(cell = (t_var*)malloc(sizeof(t_var))))
		return (var_error("malloc", "create_cell"));	
	cell->name = ft_strdup(name);
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
		if (!files)
			MULTI(head, files, create_cell(argv[i]));
		else
		{
			files->next = create_cell(argv[i]);
			files->prev = files;
			files = files->next;
		}
		max_len = max_len > (int)ft_strlen(files->name)
				? max_len : (int)ft_strlen(files->name);
		files->index = i;
		i++;
	}
	s_select.len_str = max_len;
	s_select.nb_elem = i;
	return (head);
}