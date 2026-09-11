/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:25:40 by schoinsk          #+#    #+#             */
/*   Updated: 2026/06/26 12:12:47 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const unsigned char	*bigstring;
	const unsigned char	*littlestring;
	size_t				i;
	size_t				j;

	bigstring = (const unsigned char *)big;
	littlestring = (const unsigned char *)little;
	i = 0;
	if (*littlestring == '\0')
		return ((char *)bigstring);
	while (bigstring[i] != '\0' && i < len)
	{
		j = 0;
		while (bigstring[i + j] == littlestring[j] && i + j < len)
		{
			if (littlestring[j + 1] == '\0')
				return ((char *)(bigstring + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
