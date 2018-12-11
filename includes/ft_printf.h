/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:22:35 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/11 16:41:07 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include <stdio.h>
# include "libft.h"
# include <stdarg.h>
# define BUFF_SIZE 10000

typedef unsigned long long int ULLI;

typedef struct		s_stack
{
	char			*attributs;
	int				width;
	int				precision;
	char			*modifier;
	char			format;
}					t_stack;

int					ft_printf(const char * restrict format, ...);
void    			concat_buff(char (*buff)[BUFF_SIZE], char *str, int i, int *len);
int					ft_format_parser(const char * restrict format, t_stack *new);
int					get_attributs(t_stack *new, const char * restrict format, int *i);
int					get_width(t_stack *new, const char * restrict format, int *i);
int					get_precision(t_stack *new, const char * restrict format, int *i);
int					get_modifier(t_stack *new, const char * restrict format, int *i);
void				print_node(t_stack *current);
void				node_reset(t_stack *lst);
int					stack_applier(t_stack *stack, va_list ap, char (*buff)[BUFF_SIZE], int *len);
char    			*int_format(ULLI arg, t_stack *stack);
int					char_format(int arg, t_stack *stack);
char    			*precision(char *result, t_stack *stack);
long long int		int_modifier(ULLI arg, t_stack *stack);
ULLI				unsigned_modifier(ULLI arg, t_stack *stack);
char    			*unsigned_conversion(ULLI arg, t_stack *stack);
char			    *ft_width(char *result, t_stack *stack, int len);
char			    *ft_hashtag(char *result, t_stack *stack);
char				*ft_plus(char *result, t_stack *stack);
char				*ft_space(char *result, t_stack *stack);
char				*str_format(char *arg, t_stack *stack);
char				*f_format(long double arg, t_stack *stack);
long double			f_modifier(long double arg, t_stack *stack);

typedef struct		s_attributs
{
	char			attr;
	char			*(*f)(char*, t_stack*);
}					t_attributs;

typedef struct		s_get_format
{
	char			*format;
	int				(*f)(t_stack*, const char * restrict, int*);
}					t_get_format;

#endif
