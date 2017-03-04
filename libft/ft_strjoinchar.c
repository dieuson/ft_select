/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:33:27 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinchar(char const *s1, char const *s2, char c)
{
	int		length;
	char	*str;
	int		i;
	int		j;

	length = (s2) ? ft_strlen(s1) + ft_strlen(s2) + 1 : ft_strlen(s1) + 1;
	if (!(str = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	if (*(s1 + ft_strlen(s1) - 1) != c)
	{
		str[i] = c;
		i++;
	}
	j = -1;
	while (s2 && s2[++j] != '\0')
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}
