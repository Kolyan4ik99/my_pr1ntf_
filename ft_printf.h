/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:19:05 by cclock            #+#    #+#             */
/*   Updated: 2021/01/06 04:17:08 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

# define FL_NON 0b000
# define FL_HAV 0b001
# define FL_PRE 0b010
# define FL_WID 0b100

typedef struct	s_struct
{
	char		flag;
	int			width;
	int			precision;
	char		type;
	int			len;
	char		pos;
}				t_struct;

int				parse_print(t_struct *list, const char **main_str,
				va_list *arg);
void			fill_type(const char **main_str, t_struct *list);
void			fill_arg(const char **main_str, t_struct *list, va_list *arg,
				char what_type);
int				fill_precision(const char **main_str, t_struct *list,
				va_list *arg);
int				fill_width(const char **main_str, t_struct *list, va_list *arg);
int				fill_flag_width(const char **main_str, t_struct *list,
				va_list *arg);
int				fill_flag_width_sec(const char **main_str, t_struct *list,
				va_list *arg);
int				fill_list(const char **main_str, t_struct *list, va_list *arg);
void			print_sym(char c, int i, t_struct *list);
int				print_char(t_struct *list, va_list *arg);
int				print_str(t_struct *list, va_list *arg);
int				print_d(t_struct *list, va_list *arg);
int				print_p(t_struct *list, va_list *arg);
void			prt_str(char *str, int len, t_struct *list);
int				fill_lstr(t_struct *list, va_list *arg);
int				print_x(t_struct *list, va_list *arg);
int				size_x_uns(unsigned int num);
int				print_un(t_struct *list, va_list *arg);
int				ft_printf(const char *main_str, ...);
void			ft_print_without_proc(const char **main_str, int *lent);

#endif
