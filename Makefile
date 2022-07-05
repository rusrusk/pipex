# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:25:32 by rkultaev          #+#    #+#              #
#    Updated: 2022/07/05 11:33:54 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADER = pipex.h

LIBFTA = libft_pipex/libft.a

SRCS = pipex.c find_path_env.c error.c free.c  first_child_process.c \
		second_child_process.c

OBJ = $(SRCS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g


$(NAME) : $(OBJ) $(HEADER)
		make bonus -C libft_pipex/
		$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -o $(NAME) 
		
all: $(NAME)

clean:
		rm -f $(OBJ)
		make clean -C libft_pipex/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft_pipex/

re : fclean all

.PHONY : all clean fclean re