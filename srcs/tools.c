#include "../includes/ft_select.h"

int				arrondi(float val)
{
	FT_INIT(int, val2, val < 1 ? 1 : val);
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