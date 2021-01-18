/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 04:18:20 by cclock            #+#    #+#             */
/*   Updated: 2021/01/06 04:19:29 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int				size_x(unsigned long long int num)
{
	int			i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		++i;
		num /= 16;
	}
	return (i);
}

int				size_x_uns(unsigned int num)
{
	int			i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		++i;
		num /= 16;
	}
	return (i);
}

char			*convert_x_uns(unsigned int num)
{
	int			i;
	char		*hex_num;
	char		*hex_str;

	i = size_x_uns(num);
	hex_str = "0123456789abcdef";
	if (!(hex_num = malloc(i + 1)))
		return (NULL);
	if (num == 0)
		hex_num[0] = '0';
	hex_num[i] = '\0';
	while (num)
	{
		hex_num[i - 1] = hex_str[num % 16];
		num /= 16;
		--i;
	}
	return (hex_num);
}

char			*convert_x(unsigned long long int num)
{
	int			i;
	char		*hex_num;
	char		*hex_str;

	i = size_x(num);
	hex_str = "0123456789abcdef";
	if (!(hex_num = malloc(i + 1)))
		return (NULL);
	if (num == 0)
		hex_num[0] = '0';
	hex_num[i] = '\0';
	while (num)
	{
		hex_num[i - 1] = hex_str[num % 16];
		num /= 16;
		--i;
	}
	return (hex_num);
}
