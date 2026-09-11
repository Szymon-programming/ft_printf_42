/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:32:57 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/08 16:57:36 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_value(char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == '%')
	{
		ft_putchar('%');
		count = 1;
	}
	else if (spec == 'c')
		count = print_single_char(args);
	else if (spec == 's')
		count = print_string(args);
	else if (spec == 'p')
		count = print_void(args, "0123456789abcdef");
	else if (spec == 'd' || spec == 'i')
		count = print_decimal_or_int(args);
	else if (spec == 'u')
		count = print_unsigned_decimal(args);
	else if (spec == 'x')
		count = print_hex(args, "0123456789abcdef");
	else if (spec == 'X')
		count = print_hex(args, "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			break ;
		if (str[i] == '%')
			count += check_value(str[i++ + 1], args);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
