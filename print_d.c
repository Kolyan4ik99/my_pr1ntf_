/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:01:49 by cclock            #+#    #+#             */
/*   Updated: 2021/01/06 04:12:24 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int				count_zer(t_struct *list, int *len, int sign)
{
	int			zero;

	zero = 0;
	if (list->flag == '0' && list->precision != -1 && list->precision >= 0)
		list->flag = ' ';
	if (list->flag == '0' && list->width > *len && list->precision != -1)
	{
		zero += list->width - *len;
		*len += zero;
		return (zero);
	}
	if (list->pos | FL_PRE && list->precision > (*len - sign))
	{
		zero = list->precision - *len + sign;
		*len += zero;
		return (zero);
	}
	if (list->width && list->flag == '0' &&
		(!list->precision || list->precision == -1) && list->width > *len)
	{
		zero = list->width - *len;
		*len += zero;
	}
	return (zero);
}

int				count_space(t_struct *list, int *len)
{
	int			space;

	space = 0;
	if (list->width && list->width > *len
		&& ((list->flag == ' ' || list->flag == '-')
		|| (list->flag == '0' && (!list->precision || list->precision == -1))))
	{
		space = list->width - *len;
		*len += space;
	}
	return (space);
}

int				print_d(t_struct *list, va_list *arg)
{
	int			num;
	int			len;
	int			space;
	int			zero;

	num = va_arg(*arg, int);
	len = ft_numlen(num);
	zero = count_zer(list, &len, (num < 0));
	space = count_space(list, &len);
	if (list->precision == 0 && !(list->pos & FL_WID) && num == 0)
		return (0);
	(list->flag == ' ') ? print_sym(' ', space, list) : 0;
	num < 0 ? print_sym('-', 1, list) : 0;
	print_sym('0', zero, list);
	if (!(!num && list->precision != -1 && !list->precision))
		ft_putnbr_s(((num < 0) ? -num : num), 0, list);
	else if (list->width && list->width != -1 && list->pos & FL_WID)
		print_sym(' ', 1, list);
	else
		len--;
	(list->flag == '-') ? print_sym(' ', space, list) : 0;
	return (0);
}
