#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <errno.h>

# ifndef LIBFT_H
#  include "../libft/includes/libft.h"
# endif

# define T_NORMAL   		1
# define T_REVERSE  		2
# define T_UNDERLINE   		3
# define T_UNDERREVERSE		4
# define IS_DIR 			5
# define IS_FILE 			6

# define K_ESCAPE  			7
# define K_UP      			8
# define K_DOWN    			9
# define K_RIGHT   			10
# define K_LEFT    			11
# define K_DEL	   			12
# define K_BACKSP  			13
# define K_RETURN  			14
# define K_UNKNOWN			15

typedef struct				s_var
{
	char					*name;
	int 					index;
	struct s_var			*next;
	struct s_var			*prev;
}							t_var;

typedef struct				s_completion
{
	struct s_var			*elem;
	struct s_completion		*next;
}							t_completion;

typedef struct				s_select
{
	int 					cursor;
	int						nb_rows;
	int 					len_str;
	int 					nb_elem;
	char 					*c;
	struct winsize			*win;
	struct termios			my_termios;
	struct termios			t_back;
	t_var 					*files;
}							t_select;

t_select 					s_select;

int					init_all(void);
int					init_termios(struct termios my_termios);
void				ft_reset_termios(struct termios t_back);
char				*set_sentence(char *str, int len_str, char *name);
int					arrondi(float val);
t_completion		*build_lst_lst(t_var *match_files, int nb_elem, int nb_col);
int					ft_nb_elem_lst(int nb_elem, int nb_col);
void				display_completion(t_var *match_files);

void				ft_signal(void);
t_var 				*get_files(char **argv);
void				free_files_list(t_var *files);
int					readkey(void);

char 				*str_error(char *type, char *name);
t_var 				*var_error(char *type, char *name);
int 				int_error(char *type, char *name);

void				free_lists(t_var *match_files);
void				free_lst_lst(t_completion *lst_lst);


int					readkey(void);


#endif