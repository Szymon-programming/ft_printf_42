/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_cspdi.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:36:28 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/07 11:48:16 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_single_char(va_list args)
{
	char	znak;
	int		count;

	znak = (char)va_arg(args, int);
	count = ft_putchar(znak);
	return (count);
}

int	print_string(va_list args)
{
	char	*str;
	int		count;

	str = (char *)va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	count = ft_putstr(str);
	return (count);
}

int	print_void(va_list args, char *base)
{
	void				*ptr;
	unsigned long long	adress;
	int					count;
	char				buff[17];
	int					i;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	adress = (unsigned long long)ptr;
	i = 0;
	if (adress == 0)
		buff[i++] = base[0];
	while (adress > 0)
	{
		buff[i++] = base[adress % 16];
		adress /= 16;
	}
	count = ft_putstr("0x");
	while (i > 0)
		count += ft_putchar(buff[--i]);
	return (count);
}

int	print_decimal_or_int(va_list args)
{
	int	count;
	int	value;

	value = (int)va_arg(args, int);
	count = ft_putnbr(value);
	return (count);
}
