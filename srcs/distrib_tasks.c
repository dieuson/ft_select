#include "../includes/ft_select.h"

static void 			set_style_move(int index, t_var *files)
{
	while (index != -1 && files)
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

static void 			set_style_space(int index, t_var *files)
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


void 			delete_element(void)
{
	FT_INIT(int, index, 0);
	FT_INIT(t_var*, files, s_select.files);
	FT_INIT(t_var*, tmp, files);
	index = go_to_position(s_select.pos_x, s_select.pos_y, K_SPACE);
	while (index != -1 && files)
	{
		if (files->index == index)
		{
			ft_strdel(&files->name);
			if (files->next)
			{
				tmp->next = files->next;
				files->next->prev = tmp;
			}
			else
				tmp->next = NULL;
			free(files);
			files = tmp;
			set_style_move(tmp->next ? tmp->next->index : tmp->index, s_select.files);
		}
		tmp = files;
		files = files->next;
	}
}

void 			select_element(void)
{
	FT_INIT(int, index, 0);
	index = go_to_position(s_select.pos_x, s_select.pos_y, K_SPACE);
	set_style_space(index, s_select.files);
}

void			move_list(int key)
{
	if (key == K_RIGHT)
		s_select.pos_x += 1;
	else if (key == K_LEFT)
		s_select.pos_x -= 1;
	else if (key == K_UP)
		s_select.pos_y -= 1;
	else if (key == K_DOWN)
		s_select.pos_y += 1;
	FT_INIT(int, index, 0);
	index = go_to_position(s_select.pos_x, s_select.pos_y, key);
	set_style_move(index, s_select.files);
}