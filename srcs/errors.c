/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:32:29 by dvirgile          #+#    #+#             */
/*   Updated: 2017/12/13 15:32:31 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

char					*str_error(char *type, char *name)
{
	ft_putstr_fd("ft_select ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" :", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

int						int_error(char *type, char *name)
{
	ft_putstr_fd("ft_select ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" :", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

void					void_error(char *type, char *name)
{
	ft_putstr_fd("ft_select ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" :", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	return ;
}

t_var					*var_error(char *type, char *name)
{
	ft_putstr_fd("ft_select ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" :", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

t_completion			*completion_error(char *type, char *name)
{
	ft_putstr_fd("ft_select ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" :", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}
