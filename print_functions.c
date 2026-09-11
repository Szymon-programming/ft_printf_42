/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:16:03 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/07 11:57:07 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (0);
	count = ft_strlen(s);
	write(1, s, count);
	return (count);
}

int	ft_putnbr(int n)
{
	long	number;
	int		count;

	number = n;
	count = 0;
	if (number < 0)
	{
		count += ft_putchar('-');
		number = -number;
	}
	if (number >= 10)
		count += ft_putnbr(number / 10);
	count += ft_putchar((number % 10) + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	long	number;
	int		count;

	number = n;
	count = 0;
	if (number >= 10)
		count += ft_putnbr_unsigned(number / 10);
	count += ft_putchar((number % 10) + '0');
	return (count);
}
