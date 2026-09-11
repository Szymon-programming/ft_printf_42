/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:24:01 by schoinsk          #+#    #+#             */
/*   Updated: 2026/06/26 15:05:43 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		size = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	number;
	int		size;
	char	*string;

	number = n;
	size = get_size(number);
	string = malloc(size + 1);
	if (string == NULL)
		return (NULL);
	string[size] = '\0';
	if (number == 0)
		string[0] = '0';
	if (number < 0)
	{
		string[0] = '-';
		number = -number;
	}
	while (number > 0)
	{
		size--;
		string[size] = (number % 10) + '0';
		number /= 10;
	}
	return (string);
}
