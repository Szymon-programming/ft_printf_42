/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:24:26 by schoinsk          #+#    #+#             */
/*   Updated: 2026/06/26 12:12:47 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tymczasowy;

	tymczasowy = (unsigned char *)s;
	while (n > 0)
	{
		*tymczasowy = (unsigned char)c;
		tymczasowy++;
		n--;
	}
	return (s);
}
