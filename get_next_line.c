/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:54:12 by dylmarti          #+#    #+#             */
/*   Updated: 2023/10/25 23:41:20 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = ft_calloc(sizeof(char), i);
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*rmthings(char *stash)
{
	char	*stash2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i - 1] != '\n')
		i++;
	stash2 = ft_calloc(sizeof(char), ft_strlen(stash) - i);
	while (stash[i])
		stash2[j++] = stash[i++];
	return (stash2);
}

static char	*beforenewline(char *line, char *stash)
{
	int	i;

	i = 0;
	while (stash[i - 1] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (stash[i - 1] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

static int	newline(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if ((stash[i]) == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash;
	int			i;

	if (stash == NULL)
		stash = "";
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	i = read(fd, buffer, BUFFER_SIZE);
	while (i != 0)
	{
		stash = ft_strjoin(stash, buffer);
		if (newline(stash) == 1)
		{
			line = beforenewline(line, stash);
			stash = rmthings(stash);
			free (buffer);
			return (line);
		}
		ft_memset(buffer, '\0', BUFFER_SIZE);
		i = read(fd, buffer, BUFFER_SIZE);
	}
	line = ft_strdup(stash);
	free (stash);
	return (line);
}
