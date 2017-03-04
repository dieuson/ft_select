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
}

void			free_lst_lst(t_completion *lst_lst)
{
	FT_INIT(t_completion*, tmp_lst, NULL);
	while (lst_lst->next)
	{
		tmp_lst = lst_lst;
		lst_lst = lst_lst->next;
		free(tmp_lst);
	}
	free(lst_lst);
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
}

void			free_auto_tab(char **table)
{
	int		colonne;

	colonne = 0;
	while ((table) && (table)[colonne])
	{
		free((table)[colonne]);
		(table)[colonne] = NULL;
		colonne++;
	}
	free(table);
}
