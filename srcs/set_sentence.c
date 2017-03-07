/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sentence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:35:41 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static char 		*set_style(char *start, char *end, char *str,
																int disp_style)
{
	FT_INIT(char*, tmp, NULL);
	FT_INIT(char*, style, NULL);
	if (disp_style == T_UNDERREVERSE)
	{
		style = ft_strjoin(tgetstr("mr", NULL), tgetstr("us", NULL));
		tmp = style;
		style = ft_strjoin(style, str);
		free(tmp);
		tmp = style;
		style = ft_strjoin(style, tgetstr("me", NULL));
		free(tmp);
		tmp = style;
		style = ft_strjoin(style, tgetstr("ue", NULL));
	}
	else
	{
		style = ft_strjoin(tgetstr(start, NULL), str);
		tmp = style;
		style = ft_strjoin(style, tgetstr(end, NULL));
	}
	free(tmp);
	return (style);
}

static char		*set_disp_atribute(char *str, int disp_style)
{
	FT_INIT(char*, start, "");
	FT_INIT(char*, end, "");
	FT_INIT(char*, style, NULL);
	if (!str)
		return (str_error("disp_attribute", "No attribute"));
	else if (disp_style == T_NORMAL)
		return (ft_strdup(str));
	start = disp_style == T_REVERSE ? "mr" : start;
	start = disp_style == T_UNDERLINE ? "us" : start;
	end = disp_style == T_REVERSE ? "me" : end;
	end = disp_style == T_UNDERLINE ? "ue" : end;
	style = set_style(start, end, str, disp_style);
	return (style);
}

static char 		*set_printf_prototype(int len_str, int disp_attribute)
{
	FT_INIT(char*, prototype, NULL);
	len_str = disp_attribute == T_REVERSE ? len_str + 8 : len_str;
	len_str = disp_attribute == T_UNDERLINE ? len_str + 9 : len_str;
	len_str = disp_attribute == T_UNDERREVERSE ? len_str + 17 : len_str;
	prototype = ft_itoa(len_str + 2);
	return (prototype);
}

char		*set_sentence(char *str, int len_str, t_var *cell)
{
	FT_INIT(char*, tmp, set_printf_prototype(len_str, cell->disp_attribute));
	FT_INIT(char*, attribute_name, set_disp_atribute(cell->name, cell->disp_attribute));
	str = ft_strcat(str, "%-");
	str = ft_strcat(str, tmp);
	str = ft_strcat(str, "s");
	ft_printf(str, attribute_name);
	ft_bzero(str, ft_strlen(str));
	ft_strdel(&tmp);
	ft_strdel(&attribute_name);
	return (str);
}
