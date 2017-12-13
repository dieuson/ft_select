/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <dvirgile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by dvirgile          #+#    #+#             */
/*   Updated: 2017/02/24 18:33:23 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	int				size;
	unsigned int	i;

	i = 0;
	if (s)
	{
		size = ft_strlen(s);
		if (size > 0)
			string = (char *)malloc(sizeof(string) * (size + 1));
		if (f)
		{
			while (s[i])
			{
				string[i] = f(i, (char)s[i]);
				i++;
			}
			string[i] = '\0';
			return (string);
		}
	}
	return (NULL);
}
