/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:30:52 by cclock            #+#    #+#             */
/*   Updated: 2021/01/05 08:59:43 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			fill_lstr(t_struct *list, va_list *arg)
{
	if (list->type == 'c')
		return (print_char(list, arg));
	else if (list->type == 's')
		return (print_str(list, arg));
	else if (list->type == 'p')
		return (print_p(list, arg));
	else if (list->type == 'd')
		return (print_d(list, arg));
	else if (list->type == 'i')
		return (print_d(list, arg));
	else if (list->type == 'u')
		return (print_un(list, arg));
	else if (list->type == 'x')
		return (print_x(list, arg));
	else if (list->type == 'X')
		return (print_x(list, arg));
	else if (list->type == '%')
		return (print_char(list, arg));
	else
		return (-1);
}

void		check_zer(t_struct *list)
{
	if (list->width < 0 && list->width != -1)
	{
		list->flag = '-';
		list->width *= -1;
	}
	if (list->pos & FL_HAV && list->width == -1)
		list->width = 1;
}

int			fill_list(const char **main_str, t_struct *list, va_list *arg)
{
	list->width = -1;
	if (**main_str == '.')
		fill_precision(main_str, list, arg);
	else if (!list->type)
		fill_flag_width(main_str, list, arg);
	if (!list->type)
		fill_type(main_str, list);
	if (!list->type)
		return (-1);
	if (list->type)
		++(*main_str);
	check_zer(list);
	if (fill_lstr(list, arg) == -1)
		return (-1);
	return (1);
}

int			parse_print(t_struct *list, const char **main_str, va_list *arg)
{
	list->pos = FL_NON;
	list->len = 0;
	list->flag = '\0';
	list->type = '\0';
	list->precision = -1;
	if (fill_list(main_str, list, arg) == -1 || !list->type)
		return (-1);
	return (0);
}
