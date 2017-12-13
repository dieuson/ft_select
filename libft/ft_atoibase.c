/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <dvirgile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by dvirgile          #+#    #+#             */
/*   Updated: 2017/02/24 18:34:43 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	check(char current, int base)
{
	int check;

	if (current >= '0' && current <= '9')
		check = current - '0';
	else if (current >= 'a' && current <= 'z')
		check = current - 'a';
	else if (current >= 'A' && current <= 'Z')
		check = current - 'A';
	else
		check = -1;
	if (check < base && check != -1)
		return (check);
	else
		return (-1);
}

static int	nb_length(char *nb, int base)
{
	int length;

	length = 0;
	while (nb[length])
	{
		if (check(nb[length], base) == -1)
			break ;
		length++;
	}
	return (length);
}

int			ft_atoibase(char *nb, int base)
{
	int resultat;
	int length;
	int i;

	i = 0;
	if (base == 10)
		return (ft_atoi(nb));
	while (nb[i] == ' ' || nb[i] == '\t' || nb[i] == '\f' || nb[i] == '\n'
	|| nb[i] == '\v' || nb[i] == '\r')
		i++;
	resultat = 0;
	length = nb_length(nb, base) - 1;
	while (nb[i] && length >= 0 && check(nb[i], base) != -1)
	{
		resultat += check(nb[i], base) * ft_recursive_pow(base, length);
		i++;
		length--;
	}
	return (resultat);
}
