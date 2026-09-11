/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:25:45 by schoinsk          #+#    #+#             */
/*   Updated: 2026/06/26 12:12:47 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char		wanted;
	const unsigned char	*source;
	int					i;

	wanted = (unsigned char)c;
	source = (const unsigned char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (*(source + i) == wanted)
		{
			return ((char *)(source + i));
		}
		i--;
	}
	return (NULL);
}
