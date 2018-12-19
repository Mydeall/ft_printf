# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccepre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 15:43:12 by ccepre            #+#    #+#              #
#    Updated: 2018/12/18 18:13:05 by ccepre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIB_PATH = ./libft
SRC_PATH = ./srcs
INC_PATH = ./includes
MAIN_PATH = ./..

LIB_NAME = ft_itoa.c\
		   ft_strcpy.c\
		   ft_putnbr.c\
		   ft_strdel.c\
		   ft_atoi.c\
		   ft_strdup.c\
		   ft_strsub.c\
		   ft_strcat.c\
		   ft_strchr.c\
		   ft_strjoin.c\
		   ft_strnew.c\
		   ft_strcmp.c\
		   ft_strlen.c\
		   ft_bzero.c\
		   ft_memalloc.c\
		   ft_memset.c\
		   ft_putchar.c\
		   ft_putendl.c\
		   ft_putstr.c\
		   ft_itoa_base.c\
		   ft_itoa_base_signed.c \
		   ft_dputnbr.c \
		   ft_dtoa.c \
		   ft_pow.c

SRC_NAME = ft_printf.c \
		   lst_functions.c \
		   ft_stack_applier.c \
		   ft_format.c \
		   ft_modifier.c \
		   ft_conversion.c \
		   ft_precision.c \
		   ft_attributs.c \
		   ft_width.c \
		   ft_parser.c \
		   ft_parser_fct.c

INC_NAME = ft_printf.h

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

OBJ_SRC= $(SRC:.c=.o)
OBJ_LIB= $(LIB:.c=.o)

all : $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_PATH) 

.PHONY : sani exec clean fclean re

$(NAME) : $(OBJ_SRC) $(OBJ_LIB) $(INC)
	ar rc $(NAME) $(OBJ_SRC) $(OBJ_LIB)
	ranlib $(NAME)

clean :
	rm -f $(OBJ_SRC)
	rm -f $(OBJ_LIB)

fclean : clean
	rm -f $(NAME)

re : fclean all

exec : $(NAME)
	@gcc $(NAME) $(MAIN_PATH)/main.c -I $(INC_PATH)
	@./a.out

sani: $(NAME)
	gcc -g3 -fsanitize=address $(NAME) $(MAIN_PATH)/main.c -I $(INC_PATH)
	./a.out

valgrind : $(NAME)
	@gcc $(NAME) $(MAIN_PATH)/main.c -I $(INC_PATH)
	@valgrind --leak-check=yes --track-origins=yes ./a.out
