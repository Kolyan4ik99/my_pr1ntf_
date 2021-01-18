/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 06:16:57 by cclock            #+#    #+#             */
/*   Updated: 2021/01/06 03:52:58 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int					ft_numlen_un(unsigned int num)
{
	int				i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		++i;
	}
	return (i);
}

int					print_un(t_struct *list, va_list *arg)
{
	unsigned int	num;
	int				len;
	int				zero;
	int				space;

	num = va_arg(*arg, unsigned int);
	len = ft_numlen_un(num);
	zero = count_zer(list, &len, 0);
	space = count_space(list, &len);
	if (list->precision == 0 && !(list->pos & FL_WID) && num == 0)
		return (0);
	(list->flag == ' ') ? print_sym(' ', space, list) : 0;
	print_sym('0', zero, list);
	if (!(!num && list->precision != -1 && !list->precision))
		ft_putunbr_s(((num < 0) ? -num : num), list);
	else if (list->width && list->width != -1)
		print_sym(' ', 1, list);
	else
		len--;
	(list->flag == '-') ? print_sym(' ', space, list) : 0;
	return (0);
}
