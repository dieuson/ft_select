
#include "../includes/ft_select.h"

char 					*str_error(char *type, char *name)
{
	ft_printf("Error %s :%s\n", type, name);
	return (NULL);
}

int 					int_error(char *type, char *name)
{
	ft_printf("Error %s :%s\n", type, name);
	return (0);
}

t_var 					*var_error(char *type, char *name)
{
	ft_printf("Error %s :%s\n", type, name);
	return (NULL);
}