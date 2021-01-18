/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:48:34 by cclock            #+#    #+#             */
/*   Updated: 2021/01/06 04:20:57 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int							print_p(t_struct *list, va_list *arg)
{
	char					*hex_num;
	unsigned long long int	numb;
	int						len;
	int						zero;
	int						space;

	numb = va_arg(*arg, long long int);
	if (!(hex_num = convert_x(numb)))
		return (-1);
	len = ft_strlen(hex_num);
	if (list->precision != -1 && !list->precision && !numb)
		--len;
	len += 2;
	zero = count_zer(list, &len, 0);
	space = count_space(list, &len);
	(list->flag == ' ') ? print_sym(' ', space, list) : 0;
	prt_str("0x", 2, list);
	print_sym('0', zero, list);
	if (!(list->flag != 1 && !numb && !list->precision))
		prt_str(hex_num, ft_strlen(hex_num), list);
	(list->flag == '-') ? print_sym(' ', space, list) : 0;
	free(hex_num);
	return (0);
}

int							print_x(t_struct *list, va_list *arg)
{
	unsigned int			num;
	char					*hex_num;
	int						zero;
	int						space;
	int						len;

	num = va_arg(*arg, unsigned int);
	if (!(hex_num = convert_x_uns(num)))
		return (-1);
	len = ft_strlen(hex_num);
	(list->type == 'X') ? ft_toupper(hex_num) : 0;
	zero = count_zer(list, &len, 0);
	space = count_space(list, &len);
	(list->flag == ' ') ? print_sym(' ', space, list) : 0;
	print_sym('0', zero, list);
	if (!(!num && list->precision != -1 && !list->precision))
		prt_str(hex_num, ft_strlen(hex_num), list);
	else if (list->width && list->width != -1 && list->pos & FL_WID)
		print_sym(' ', 1, list);
	else
		--len;
	(list->flag == '-') ? print_sym(' ', space, list) : 0;
	free(hex_num);
	return (0);
}
