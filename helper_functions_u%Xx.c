/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_u%Xx.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:20:35 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/06 19:35:11 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_decimal(va_list args)
{
	int				count;
	unsigned int	value;

	value = (unsigned int)va_arg(args, unsigned int);
	count = ft_putnbr_unsigned(value);
	return (count);
}

int	print_hex(va_list args, char *base)
{
	int				count;
	unsigned int	value;
	char			buff[9];
	int				i;

	count = 0;
	value = va_arg(args, unsigned int);
	i = 0;
	if (value == 0)
		return (ft_putchar(base[0]));
	while (value > 0)
	{
		buff[i] = base[value % 16];
		value = value / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		count += ft_putchar(buff[i]);
	}
	return (count);
}
