# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:25:32 by rkultaev          #+#    #+#              #
#    Updated: 2022/08/15 16:03:36 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC				=			pipex
EXEC_BONUS			=			pipex_bonus
CC					=			gcc
CFLAGS				=			-Wall -Werror -Wextra -g
RM					=			rm -rf



HEADER_SRCS			= 			pipex.h pipex_bonus.h
HEADER_DIRECTORY	=			includes/
HEADER				=			$(addprefix $(HEADER_DIR), $(HEADER_SRCS))


SRCS_MANDATORY		= 			pipex.c find_path_env.c error.c \
								free.c  first_child_process.c \
								second_child_process.c main.c
PATH_DIRECTORY_M	=			src/
PATH_MANDATORY		=			$(addprefix $(PATH_DIRECTORY_M), $(SRCS))
OBJS_MANDATORY		=			$(PATH_MANDATORY:%.c=%.o)

SRCS_BONUS			=			child_bonus.c error_bonus.c process_files_bonus.c \
								here_doc_bonus.c pipex_bonus.c \
PATH_DIRECTORY_B	=			bonus/
PATH_BONUS			=			$(addprefix $(PATH_DIRECTORY_B), $(SRCS_BONUS))
OBJS_BONUS			=			$(PATH_BONUS:%.c=%.o)



LIBFTA = libft42_pipex/libft.a

%.o: %.c $(HEADER) Makefile
		@(CC) $(CFLAGS) -c $< -o $@

all: $(EXEC)


$(EXEC) : $(OBJS_MANDATORY)
		@make bonus -C libft42_pipex/
		@$(CC) $(OBJS_MANDATORY) $(LIBFTA) -o $(EXEC)
		@echo "$(B_GREEN) COMPILATION OF MANDATORY PART: DONE $(NC)"

bonus:	$(EXEC_BONUS)

$(EXEC_BONUS) : $(OBJS_BONUS)
		@make bonus -C libft42_pipex/
		@$(CC) $(OBJS_BONUS) $(OBJ) $(LIBFTA) -o $(EXEC)
		@echo "$(B_BLUE) COMPILATION OF BONUS PART: DONE $(NC)"

clean:
		@$(RM) $(OBJS)
		@$(RM) $(OBJS_BONUS)
		@make clean -C libft42_pipex/
		@echo "$(YELLOW) OBJECT FILES ARE REMOVED! $(NC) $(OBJS)"

fclean: clean
		@$(RM) $(EXEC)
		@make fclean -C libft42_pipex/
		@echo "$(RED) ALL FILES ARE DELETED! $(NC)"

re : fclean all

re_bonus : fclean bonus

.PHONY : all clean fclean re bonus


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