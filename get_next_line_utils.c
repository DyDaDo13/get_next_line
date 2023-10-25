/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:55:28 by dylmarti          #+#    #+#             */
/*   Updated: 2023/10/25 12:42:11 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	tab = malloc(size * nmemb);
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, 0, size * nmemb);
	return (tab);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (str);
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	j;

	j = 0;
	while (s[j])
		j++;
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		r;

	i = 0;
	r = 0;
	str = malloc(sizeof(char) * ft_strlen((char *)s1) + \
	ft_strlen((char *)s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[r])
	{
		str[i] = s2[r];
		i++;
		r++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (n == 0)
		return ;
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return ;
}