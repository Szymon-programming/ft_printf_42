/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:24:54 by schoinsk          #+#    #+#             */
/*   Updated: 2026/06/26 12:12:47 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		wanted;
	const unsigned char	*source;

	wanted = (unsigned char)c;
	source = (const unsigned char *)s;
	while (*source != '\0')
	{
		if (*source == wanted)
		{
			return ((char *)source);
		}
		source++;
	}
	if (wanted == '\0')
		return ((char *)source);
	return (NULL);
}
