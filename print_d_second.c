/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_second.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 07:15:57 by cclock            #+#    #+#             */
/*   Updated: 2021/01/05 08:49:24 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		ft_putnbr_s(int n, int flag, t_struct *list)
{
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		list->len += 10;
	}
	else if (n == 0)
	{
		print_sym('0', 1, list);
	}
	else if (n < 0)
	{
		print_sym('-', 1, list);
		ft_putnbr_s(n, flag, list);
	}
	else if (n >= 10)
	{
		ft_putnbr_s(n / 10, flag, list);
		print_sym((n % 10) + '0', 1, list);
	}
	else
		print_sym((n % 10) + '0', 1, list);
}

void		ft_putunbr_s(unsigned int n, t_struct *list)
{
	if (n == 0)
	{
		print_sym('0', 1, list);
	}
	else if (n >= 10)
	{
		ft_putunbr_s(n / 10, list);
		print_sym((n % 10) + '0', 1, list);
	}
	else
		print_sym((n % 10) + '0', 1, list);
}

int			ft_numlen(int num)
{
	int		i;

	i = 0;
	if (num < 0)
		++i;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		++i;
	}
	return (i);
}
