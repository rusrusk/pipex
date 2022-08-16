# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 14:27:16 by rkultaev          #+#    #+#              #
#    Updated: 2022/08/16 21:39:40 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c ft_isalnum.c	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c	\
ft_memmove.c	ft_memset.c \
ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_toupper.c \
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_putchar_fd.c \
ft_putstr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putendl_fd.c \
ft_putnbr_fd.c get_next_line_utils.c get_next_line.c ft_printf_chars_utilities.c \
ft_printf_nbrs_utilities.c ft_printf.c 

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

HEADER = libft.h

OBJ	= $(SRCS:%.c=%.o)

bonus_objects = $(BONUS:%.c=%.o)

CC = gcc


CFLAGS = -Wall -Wextra -Werror -I $(HEADER)



$(NAME) : $(OBJ) $(HEADER)
	@ar rcs $(NAME) $(OBJ)

bonus : $(OBJ) $(bonus_objects) $(HEADER)
	@ar rcs $(NAME) $(OBJ) $(bonus_objects)

all : $(NAME)

clean :
	@rm -f $(OBJ) $(bonus_objects)

fclean : clean
	@rm -f $(NAME)

re:	fclean all

.PHONY	:	all clean fclean re bonus
