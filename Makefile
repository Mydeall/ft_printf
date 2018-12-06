# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccepre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 15:43:12 by ccepre            #+#    #+#              #
#    Updated: 2018/12/06 18:04:25 by ccepre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

PATH = libft/

SRCS = $(PATH)ft_itoa.c\
	   $(PATH)ft_memchr.c\
	   $(PATH)ft_putendl_fd.c\
	   $(PATH)ft_strcpy.c\
	   $(PATH)ft_strmap.c\
	   $(PATH)ft_strsplit.c\
	   $(PATH)ft_lstadd.c\
	   $(PATH)ft_memcmp.c\
	   $(PATH)ft_putnbr.c\
	   $(PATH)ft_strdel.c\
	   $(PATH)ft_strmapi.c\
	   $(PATH)ft_strstr.c\
	   $(PATH)ft_atoi.c\
	   $(PATH)ft_lstdel.c\
	   $(PATH)ft_memcpy.c\
	   $(PATH)ft_putnbr_fd.c\
	   $(PATH)ft_strdup.c\
	   $(PATH)ft_strncat.c\
	   $(PATH)ft_strsub.c\
	   $(PATH)ft_bzero.c\
	   $(PATH)ft_lstdelone.c\
	   $(PATH)ft_memdel.c\
	   $(PATH)ft_putstr.c\
	   $(PATH)ft_strequ.c\
	   $(PATH)ft_strncmp.c\
	   $(PATH)ft_strtrim.c\
	   $(PATH)ft_isalnum.c\
	   $(PATH)ft_lstiter.c\
	   $(PATH)ft_memmove.c\
	   $(PATH)ft_putstr_fd.c\
	   $(PATH)ft_striter.c\
	   $(PATH)ft_strncpy.c\
	   $(PATH)ft_strtrimchar.c\
	   $(PATH)ft_isalpha.c\
	   $(PATH)ft_lstmap.c\
	   $(PATH)ft_memset.c\
	   $(PATH)ft_strcat.c\
	   $(PATH)ft_striteri.c\
	   $(PATH)ft_strnequ.c\
	   $(PATH)ft_tolower.c\
	   $(PATH)ft_isascii.c\
	   $(PATH)ft_lstnew.c\
	   $(PATH)ft_putchar.c\
	   $(PATH)ft_strchr.c\
	   $(PATH)ft_strjoin.c\
	   $(PATH)ft_strnew.c\
	   $(PATH)ft_toupper.c\
	   $(PATH)ft_isdigit.c\
	   $(PATH)ft_memalloc.c\
	   $(PATH)ft_putchar_fd.c\
	   $(PATH)ft_strclr.c\
	   $(PATH)ft_strlcat.c\
	   $(PATH)ft_strnstr.c\
	   $(PATH)ft_isprint.c\
	   $(PATH)ft_memccpy.c\
	   $(PATH)ft_putendl.c\
	   $(PATH)ft_strcmp.c\
	   $(PATH)ft_strlen.c\
	   $(PATH)ft_strrchr.c\
	   $(PATH)ft_strtrimchar.c\
	   $(PATH)ft_putstrtab.c\
	   $(PATH)ft_putinttab.c\
	   $(PATH)ft_strjointab.c\
	   $(PATH)ft_lstlen.c\
	   $(PATH)ft_lstradd.c\
	   $(PATH)ft_putlst_str.c\
	   $(PATH)ft_pow.c\
	   $(PATH)ft_itoa_base.c\
	   $(PATH)ft_itoa_base_signed.c \
	   $(PATH)ft_dputnbr.c \
	   $(PATH)ft_dtoa.c \
	   srcs/ft_printf.c \
	   srcs/lst_functions.c \
	   srcs/stack_applier.c \
	   srcs/ft_format.c \
	   srcs/ft_modifier.c \
	   srcs/ft_conversion.c \
	   srcs/ft_precision.c \
	   srcs/ft_attributs.c

HEADERS = .

OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	gcc $(FLAGS) -c $< -o $@

.PHONY : clean fclean re

$(NAME) : $(OBJS) $(HEADERS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
