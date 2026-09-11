/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:25:50 by schoinsk          #+#    #+#             */
/*   Updated: 2026/06/26 12:12:47 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_string(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_substr(s1, 0, 0));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0')
	{
		if (is_in_string(s1[i], set) == 0)
			break ;
		i++;
	}
	if (s1[i] == '\0')
		return (ft_substr(s1, i, 0));
	while (j > 0)
	{
		if (is_in_string(s1[j], set) == 0)
			break ;
		j--;
	}
	return (ft_substr(s1, i, (j - i + 1)));
}
