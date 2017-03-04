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

int				arrondi(float val)
{
	FT_INIT(int, val2, val);
	FT_INIT(float, result, val - val2);
	if (result >= 0.5)
		return (val2);
	return (val2);
}

int				ft_nb_elem_lst(int nb_elem, int nb_col)
{
	FT_INIT(float, result, 0);
	while (result * nb_col < nb_elem)
		result++;
	return (result);
}


void		free_simple_tab(char ***tab_to_del)
{
	int		colonne;

	colonne = 0;
	while ((*tab_to_del) && (*tab_to_del)[colonne])
	{
		free((*tab_to_del)[colonne]);
		(*tab_to_del)[colonne] = NULL;
		colonne++;
	}
	free(*tab_to_del);
	*tab_to_del = NULL;
}

char		*set_sentence(char *str, int len_str, char *name)
{
	FT_INIT(char*, tmp, ft_itoa(len_str + 2));
	str = ft_strcat(str, "%-");
	str = ft_strcat(str, tmp);
	str = ft_strcat(str, "s");
	ft_printf(str, name);
	ft_bzero(str, ft_strlen(str));
	ft_strdel(&tmp);
	return (str);
}

char		*is_space(char *sentence, char *str)
{
	FT_INIT(char*, tmp, str);
	if (sentence[ft_strlen(sentence) - 1] == ' ')
	{
		str = ft_strjoin(str, " ");
		ft_strdel(&tmp);
	}
	ft_strdel(&sentence);
	return (str);
}

char		*default_sentence(char **sentence)
{
	FT_INIT(char **, path, NULL);
	FT_INIT(int, i, 0);
	FT_INIT(char*, tmp, NULL);
	FT_INIT(char*, str, NULL);
	if (!ft_strchr(*sentence, ' '))
		return (*sentence);
	str = ft_strdup("");
	path = ft_strsplit(*sentence, ' ');
	while (path && path[i])
	{
		tmp = str;
		str = ft_strjoin(str, path[i]);
		if (tmp)
			ft_strdel(&tmp);
		if (path[i + 1] && str && ft_strlen(str))
		{
			tmp = str;
			str = ft_strjoin(str, " ");
			ft_strdel(tmp ? &tmp : NULL);
		}
		i++;
	}
	free_simple_tab(&path);
	str = is_space(*sentence, str);
	return (str);
}
