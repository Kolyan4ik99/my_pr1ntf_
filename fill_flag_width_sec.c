/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_width_sec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 07:55:00 by cclock            #+#    #+#             */
/*   Updated: 2021/01/06 04:09:34 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		fill_flag_width_sec(const char **main_str, t_struct *list, va_list *arg)
{
	if (list->type)
		return (0);
	if (fill_width(main_str, list, arg) == -1)
		return (-1);
	if (**main_str == '.')
		if (fill_precision(main_str, list, arg) == -1)
			return (-1);
	return (0);
}

int		fill_flag_width(const char **main_str, t_struct *list, va_list *arg)
{
	if (**main_str != '.' && !list->flag && !list->type)
	{
		list->flag = '0';
		if (**main_str == '-' || **main_str == '0')
			while (**main_str == '-' || **main_str == '0')
			{
				if (**main_str == '-')
					list->flag = '-';
				++(*main_str);
				list->pos = list->pos | FL_HAV;
			}
		else
			list->flag = ' ';
		fill_type(main_str, list);
	}
	return (fill_flag_width_sec(main_str, list, arg));
}
