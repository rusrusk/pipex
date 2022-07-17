# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:25:32 by rkultaev          #+#    #+#              #
#    Updated: 2022/07/17 17:47:39 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADER = pipex.h

NC			:= \033[0m
B_RED		:= \033[1;31m
RED 		:= \033[0;31m
B_GREEN		:= \033[1;32m
GREEN 		:= \033[0;32m
B_BLUE 		:= \033[1;34m
BLUE 		:= \033[0;34m
PURPLE		:= \033[0;35m
B_PURPLE	:= \033[1;35m

LIBFTA = libft42_pipex/libft.a

SRCS = pipex.c find_path_env.c error.c free.c  first_child_process.c \
		second_child_process.c main.c 

BONUS_SRCS = pipex_bonus.c

OBJ = $(SRCS:%.c=%.o)

BONUS_OBJECTS = $(BONUS_SRCS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra


$(NAME) : $(OBJ) $(HEADER)
		make bonus -C libft42_pipex/
		$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -o $(NAME)
		@echo "$(B_GREEN) COMPILATION OF MANDATORY PART: DONE $(NC)"

bonus : $(BONUS_OBJECTS) $(HEADER)
		make bonus -C libft42_pipex/
		$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(OBJ) $(LIBFTA) -o $(NAME)
		@echo "$(B_BLUE) COMPILATION OF BONUS PART: DONE $(NC)"

all: $(NAME)

$(BONUS_OBJECTS): $(SRCS) $(BONUS_SRCS)
	$(CC) -DIS_BONUS $(CFLAGS) -c $(SRCS) $(BONUS_SRCS)

clean:
		rm -f $(OBJ) $(BONUS_OBJECTS)
		make clean -C libft42_pipex/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft42_pipex/

re : fclean all

.PHONY : all clean fclean re bonus
