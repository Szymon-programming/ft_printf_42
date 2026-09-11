/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:24:50 by schoinsk          #+#    #+#             */
/*   Updated: 2026/06/26 15:05:43 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(char const *s, char c)
{
	int		flag;
	int		i;
	size_t	count;

	flag = 0;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (count);
}

static char	**free_mem(char **s, size_t i)
{
	size_t	index;

	index = 0;
	while (index < i)
	{
		free(s[index]);
		index++;
	}
	free(s);
	return (NULL);
}

static char	*get_next_word(char const **s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = **s;
		(*s)++;
		i++;
	}
	word[i] = '\0';
	while (**s && **s == c)
		(*s)++;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words_count;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	words_count = word_counter(s, c);
	tab = malloc(sizeof(char *) * (words_count + 1));
	if (tab == NULL)
		return (NULL);
	while (i < words_count)
	{
		tab[i] = get_next_word(&s, c);
		if (tab[i] == NULL)
			return (free_mem(tab, i));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
