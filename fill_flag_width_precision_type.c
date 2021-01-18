/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_width_precision_type.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:27:53 by cclock            #+#    #+#             */
/*   Updated: 2021/01/05 07:52:43 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		fill_type(const char **main_str, t_struct *list)
{
	if (**main_str == 'c')
		list->type = 'c';
	else if (**main_str == 's')
		list->type = 's';
	else if (**main_str == 'p')
		list->type = 'p';
	else if (**main_str == 'd')
		list->type = 'd';
	else if (**main_str == 'i')
		list->type = 'i';
	else if (**main_str == 'u')
		list->type = 'u';
	else if (**main_str == 'x')
		list->type = 'x';
	else if (**main_str == 'X')
		list->type = 'X';
	else if (**main_str == '%')
		list->type = '%';
	else
		return ;
}

void		fill_arg(const char **main_str, t_struct *list,
			va_list *arg, char what_type)
{
	int		var_arg;

	var_arg = va_arg(*arg, int);
	if (what_type == 'w')
		list->width = var_arg;
	else if (what_type == 'p')
		list->precision = var_arg;
	list->pos = list->pos | FL_HAV;
	++(*main_str);
}

int			fill_precision(const char **main_str, t_struct *list, va_list *arg)
{
	list->precision = 0;
	list->pos = list->pos | FL_PRE;
	++(*main_str);
	if (**main_str == '*')
		fill_arg(main_str, list, arg, 'p');
	fill_type(main_str, list);
	if (!list->type && !list->precision)
	{
		list->precision = **main_str - '0';
		++(*main_str);
		fill_type(main_str, list);
		while (!list->type)
		{
			list->precision *= 10;
			list->precision += **main_str - '0';
			++(*main_str);
			fill_type(main_str, list);
		}
	}
	return (0);
}

int			fill_width(const char **main_str, t_struct *list, va_list *arg)
{
	list->width = 0;
	list->pos = list->pos | FL_WID;
	if (**main_str == '*')
	{
		fill_arg(main_str, list, arg, 'w');
		return (0);
	}
	if (**main_str != '.' && !list->type && !list->width)
	{
		list->width = **main_str - '0';
		++(*main_str);
		fill_type(main_str, list);
		while (**main_str != '.' && !list->type)
		{
			list->width *= 10;
			list->width += **main_str - '0';
			++(*main_str);
			fill_type(main_str, list);
		}
	}
	return (0);
}
