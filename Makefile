# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 19:12:20 by anrzepec          #+#    #+#              #
#    Updated: 2018/12/03 16:17:22 by ccepre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= ft_printf 

SRC 	=  main.c \
		   ft_printf.c \
		   lst_functions.c

OBJS	=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	+=	-Werror -Wall -Wextra

RM		=	rm -f

LIB		=	libft/libft.a

all:		$(NAME)

%.o:		%.c	
			$(CC) $(CFLAGS) -c $< -o $@

$(LIB):	
			make -C libft/

$(NAME):	$(LIB) $(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB)

fcleanlib:  cleanlib
			make fclean -C libft/

cleanlib:
			make clean -C libft/

clean:		cleanlib
			$(RM) $(OBJS)

fclean:		fcleanlib clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: re all fclean clean
