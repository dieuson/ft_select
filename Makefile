# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinho <apinho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 18:13:29 by apinho            #+#    #+#              #
#    Updated: 2017/02/24 18:20:39 by apinho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	ft_select

INCLUDE_DIR			=	./includes

SELECT_DIR 			=	./srcs/

LIBFT_DIR			=	./libft
LIBFT_NAME			=	$(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/includes

COMPILER			=	gcc
C_FLAGS				=	-Wall -Wextra -Werror
LFLAGS				=	-L$(LIBFT_DIR) -l$(LIBFT)


################# 		COMPLETION EDITION PART 		#######################

FILES_SELECT		=	main.c init.c init_termios.c free_term.c signal.c \
						catch_key.c errors.c build_files_list.c \
						display_completion.c set_sentence.c build_list.c \
						free_auto_completion.c tools.c display_tools.c \
						move_list.c distrib_tasks.c delete_element.c

SRC_SELECT	=	$(addprefix $(SELECT_DIR), $(FILES_SELECT))
BIN_SELECT	= 	$(FILES_SELECT:.c=.o)

################# 		END COMPLETION EDITION PART 	#######################

INCLUDES 	= -I$(LIBFT_INCLUDE_DIR) -I$(INCLUDE_DIR)
ALL_SRCS 	= $(SRC_SELECT)
ALL_BINS 	= $(BIN_SELECT)
EXTENSIONS 	= $(LIBFT_DIR)/libft.a $(LIBFT_DIR)/libftprintf.a

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(C_FLAGS) -g $(INCLUDES) $(ALL_SRCS) -Incurses -c
	gcc $(C_FLAGS) -g $(ALL_BINS) $(EXTENSIONS) -ltermcap -o $(NAME)
	mkdir bin_folder
	mv $(ALL_BINS) bin_folder

clean_lib:
#	make -C $(LIBFT_DIR) clean

clean: clean_lib
	rm -rf bin_folder

fclean_lib: clean_lib
#	make -C $(LIBFT_DIR) fclean

fclean: clean fclean_lib
	rm -rf $(NAME)

re: fclean all

re_lib: fclean_lib lib