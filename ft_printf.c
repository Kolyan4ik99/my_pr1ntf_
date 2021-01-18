/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:42:48 by cclock            #+#    #+#             */
/*   Updated: 2021/01/05 19:59:29 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void				ft_print_without_proc(const char **main_str, int *lent)
{
	ft_putchar_fd(**main_str, 1);
	++(*lent);
	++(*main_str);
}

int					ft_printf(const char *main_str, ...)
{
	va_list			arg;
	int				lent;
	t_struct		list;

	lent = 0;
	va_start(arg, main_str);
	while (*main_str)
	{
		if (*main_str == '%')
		{
			++main_str;
			if (parse_print(&list, &main_str, &arg) == -1)
			{
				va_end(arg);
				return (-1);
			}
			lent += list.len;
		}
		else
			ft_print_without_proc(&main_str, &lent);
	}
	va_end(arg);
	return (lent);
}
