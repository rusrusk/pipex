# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 20:52:02 by rkultaev          #+#    #+#              #
#    Updated: 2022/08/17 09:39:50 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC				=			pipex
EXEC_BONUS			=			bonus/pipex_bonus
LIBFT				=			libft42_pipex/libft.a
CC					=			gcc
CFLAGS				=			-Wall -Werror -Wextra
RM					=			rm -f
# HEADER				=			-Iincludes


HEADER_SRCS			= 			pipex.h pipex_bonus.h
HEADER_DIRECTORY	=			includes/
HEADER_PATH				=			$(addprefix $(HEADER_DIRECTORY), $(HEADER_SRCS))


MPATH_SRCS			= 			pipex.c find_path_env.c error.c \
								free.c  first_child_process.c \
								second_child_process.c main.c
MPATH_DIR			=			src/
MPATH				=			$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJS_MANDATORY		=			$(MPATH:.c=.o)

BPATH_SRCS			=			child_bonus.c error_bonus.c process_files_bonus.c \
								here_doc_bonus.c main.c ../src/find_path_env.c \
								../src/free.c
BPATH_DIR			=			./bonus/
BPATH				=			$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJS_BONUS			=			$(BPATH:.c=.o)



all: $(EXEC) #$(LIBFT_EXEC)

bonus: $(EXEC_BONUS) #$(LIBFT_EXEC)

%.o : %.c $(HEADER) Makefile
					@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# $(LIBFT_EXEC) : 
# 				@make $(NO_PRINT) $(LIBFT_DIR)

$(EXEC) : $(OBJS_MANDATORY)
				@make re -C libft42_pipex/
				@$(CC) $(OBJS_MANDATORY) $(LIBFT) -o $(EXEC)
				@echo "$(B_GREEN) COMPILATION OF MANDATORY PART: DONE $(NC)"

$(EXEC_BONUS) : $(OBJS_BONUS) $(HEADER)
					@make re -C libft42_pipex/
					@$(CC) $(OBJS_BONUS) $(LIBFT) -o $(EXEC_BONUS)
					@echo "$(B_BLUE)$(EXEC) COMPILATION OF BONUS PART: DONE $(NC)"


clean:
		@$(RM) $(OBJS_BONUS) $(OBJS_MANDATORY)
		@make clean -C libft42_pipex/
		@echo "$(YELLOW) OBJECT FILES ARE REMOVED! $(NC)"

fclean: clean
		@$(RM) $(EXEC)
		@make fclean -C libft42_pipex/
		@echo "$(RED) ALL FILES ARE DELETED! $(NC)"

re : fclean all

re_bonus : fclean bonus


.PHONY : all clean fclean re re_bonus bonus

NC			:= \033[0m
B_RED		:= \033[1;31m
RED 		:= \033[0;31m
B_GREEN		:= \033[1;32m
GREEN 		:= \033[0;32m
B_BLUE 		:= \033[1;34m
BLUE 		:= \033[0;34m
PURPLE		:= \033[0;35m
YELLOW 		:= \033[1;33m
B_PURPLE	:= \033[1;35m