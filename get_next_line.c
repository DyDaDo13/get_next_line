/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:37:37 by dydado13          #+#    #+#             */
/*   Updated: 2023/11/01 14:25:58 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// lise la ligne buffer par buffer si \n trouver retourner la ligne et garder
// les valeur dans une stash

char	*after_newline(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i - 1] != '\n')
		i++;
	str = malloc(sizeof(char) * ft_strlen(stash) - i + 1);
	if (!str)
		return (NULL);
	while (stash[i])
	{
		str[j] = stash[i];
		j++;
		i++;
	}
	free(stash);
	str[j] = '\0';
	return (str);
}

char	*before_newline(char *stash)
{
	char	*str;
	int		i;

	i = 0;
	if (!stash[i])
		return NULL;
	while (stash[i] && stash[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while(stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_and_save(int fd, char *stash)
{
	char	*buffer;
	int		i;

	if (!stash)
		stash = "";
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	i = 1;
	while (i > 0 && !ft_strchr(stash, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	
	if (fd == -1 || BUFFER_SIZE == 0)
		return (NULL);
	stash = read_and_save(fd, stash);
	line = before_newline(stash);
	stash = after_newline(stash);
	return (line);
	return (line);
}