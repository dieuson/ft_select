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
# define L_LAST 			5
# define L_FIRST 			6
# define K_ESCAPE  			7
# define K_UP      			8
# define K_DOWN    			9
# define K_RIGHT   			10
# define K_LEFT    			11
# define K_DEL	   			12
# define K_BACKSP  			13
# define K_RETURN  			14
# define K_UNKNOWN			15
# define K_SPACE  			16

typedef struct				s_var
{
	char					*name;
	int 					index;
	int 					index_init;
	int 					disp_attribute;
	int 					len_col;
	int 					pos_x;
	int 					pos_y;
	struct s_var			*next;
	struct s_var			*prev;
}							t_var;

typedef struct				s_completion
{
	struct s_var			*elem;
	int 					nb_col;
	int 					pos_y;
	struct s_completion		*next;
}							t_completion;

typedef struct				s_select
{
	int 					cursor;
	int						nb_rows;
	int 					len_str;
	int 					nb_elem;
	int 					len_current_col;
	int 					len_current_line;
	int 					pos_x;
	int 					pos_y;
	int 					index;
	int 					last_h_x;
	int 					last_h_y;
	int 					last_v_x;
	int 					last_v_y;
	bool					is_stop;
	int 					running;
	char 					*c;
	t_completion 			*lst_lst;
	struct winsize			*win;
	struct termios			my_termios;
	struct termios			t_back;
	t_var 					*files;
}							t_select;

t_select 					s_select;

int					init_all(void);
void 				set_style_move(int index, t_var *files);
int					init_termios(struct termios my_termios);
void				ft_reset_termios(struct termios t_back);
char				*set_sentence(char *str, int len_str, t_var *cell);
int					arrondi(float val);
t_completion		*build_lst_lst(t_var *match_files, int nb_elem, int nb_col);
t_var				*create_var_cell(char *name);
int					ft_nb_elem_lst(int nb_elem, int nb_col);
void				display_elements(t_var *match_files);
t_completion		*change_col(t_completion *all_col, t_completion *head,
						int *ref_col, int *nb_elem);
int					if_col(t_var *col, char *tmp,
						int len_str, t_completion *all_col);

void				ft_signal(void);
t_var 				*get_files(char **argv);
void				free_files_list(t_var *files);
int					readkey(void);
void				move_list(int key);
int 				go_to_position(int pos_x, int pos_y, int key);

char 				*str_error(char *type, char *name);
t_var 				*var_error(char *type, char *name);
int 				int_error(char *type, char *name);
void 				void_error(char *type, char *name);
t_completion		*completion_error(char *type, char *name);

void				free_lists(t_var *match_files);
void				free_lst_lst(t_completion *lst_lst);
void 				select_element(void);
void 				delete_element(void);
t_var			 	*delete_index(int index);
int					select_loop(void);

int					readkey(void);
int 				check_positions_h(int pos_x, int pos_y);
int 				check_positions_v(int pos_x, int pos_y, t_completion *lst_lst, int key);


#endif