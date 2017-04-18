/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_auto_completion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:35:45 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void			free_lists(t_var *match_files)
{
	FT_INIT(t_var*, tmp, NULL);
	if (!match_files)
		return ;
	while (match_files)
	{
		ft_strdel(&(match_files->name));
		tmp = match_files;
		match_files = match_files->next;
		free(tmp);
	}
	free(match_files);
}

void			free_files(t_var **files_list)
{
	FT_INIT(t_var*, tmp, NULL);
	if (!(*files_list))
		return ;
	while ((*files_list))
	{
		ft_strdel(&((*files_list)->name));
		tmp = (*files_list);
		(*files_list) = (*files_list)->next;
		free(tmp);
	}
	free(*files_list);
}

void			free_lst_lst(t_completion *lst_lst)
{
	FT_INIT(t_completion*, tmp_lst, NULL);
	if (!lst_lst)
		return ;
	FT_INIT(t_var*, tmp_var, NULL);
	FT_INIT(t_var*, var, NULL);
	while (lst_lst)
	{
		tmp_lst = lst_lst;
		var = tmp_lst->elem;
		while (var)
		{
			tmp_var = var;
			ft_strdel(&tmp_var->name);
			var = var->next;
			ft_memdel((void*)&tmp_var);
		}
		ft_memdel((void*)&var);
		lst_lst = lst_lst->next;
		ft_memdel((void*)&tmp_lst);
	}
	ft_memdel((void*)&lst_lst);
	return ;
}
