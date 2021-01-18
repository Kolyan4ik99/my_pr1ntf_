/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_print_sec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:56:12 by cclock            #+#    #+#             */
/*   Updated: 2021/01/06 04:11:40 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		print_sym(char c, int i, t_struct *list)
{
	while (i > 0)
	{
		--i;
		write(1, &c, 1);
		++list->len;
	}
}

int			print_char(t_struct *list, va_list *arg)
{
	char	var_arg;

	if (list->type == '%')
		var_arg = '%';
	else
		var_arg = va_arg(*arg, int);
	if (list->width)
	{
		if (list->flag == '0' && list->type == '%')
			print_sym('0', list->width - 1, list);
		if (list->flag == ' ')
			print_sym(' ', list->width - 1, list);
		print_sym(var_arg, 1, list);
		if (list->flag == '-')
			print_sym(' ', list->width - 1, list);
	}
	else
		print_sym(var_arg, 1, list);
	return (0);
}

void		prt_str(char *str, int len, t_struct *list)
{
	while (len-- > 0 && *str)
	{
		write(1, &*str, 1);
		++list->len;
		++str;
	}
}

int			print_str(t_struct *list, va_list *arg)
{
	char	*var_arg;
	int		len;
	char	*nul;

	nul = "(null)";
	var_arg = va_arg(*arg, char *);
	if (var_arg == NULL)
		var_arg = nul;
	list->precision = (list->precision < 0)
		? ft_strlen(var_arg) : list->precision;
	len = (ft_strlen(var_arg) > list->precision)
		? list->precision : ft_strlen(var_arg);
	len = (len != -1) ? len : ft_strlen(var_arg);
	if (list->width)
	{
		if (list->flag == ' ')
			print_sym(' ', list->width - len, list);
		prt_str(var_arg, len, list);
		if (list->flag == '-')
			print_sym(' ', list->width - len, list);
	}
	else
		prt_str(var_arg, len, list);
	return (0);
}
