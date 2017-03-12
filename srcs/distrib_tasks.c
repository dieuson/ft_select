#include "../includes/ft_select.h"

void 					set_style_move(int index, t_var *files)
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
	FT_INIT(t_var*,prev, NULL);
	if (!s_select.files)
		return ;
	index = go_to_position(s_select.pos_x, s_select.pos_y, K_SPACE);
	prev = delete_index(index);
	if (prev && prev->next && prev->prev)
		index = prev->next->index;
	else if (prev && !prev->next && prev->prev)
	{
		index = prev->prev->index;
		s_select.pos_x = prev->prev->pos_x;
		s_select.pos_y = prev->prev->pos_y - 1;
	}
	else if (prev && prev->next && !prev->prev)
	{
		index = prev->index;
		s_select.pos_x = prev->pos_x - 1;
		s_select.pos_y = prev->pos_y - 1;
	}
	else
		FT_MULTI4(index, s_select.pos_x, s_select.pos_y, 1);
	set_style_move(index, s_select.files);
}

void 			select_element(void)
{
	FT_INIT(int, index, 0);
	if (!s_select.files)
		return ;
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
	if (!s_select.files)
		return ;
	index = go_to_position(s_select.pos_x, s_select.pos_y, key);
	set_style_move(index, s_select.files);
}