/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:54:12 by dylmarti          #+#    #+#             */
/*   Updated: 2023/10/20 16:17:05 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcat(char *dest, const char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
}

int	newline(char *stash)
{
	while (*stash != '\n')
	{
		if ((*stash - 1) == '\n')
			return (1);
		stash++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*buffer;
	char	*line;
	int		i;
	
	i = 0;
	stash = ft_calloc(sizeof(char) * BUFFER_SIZE);
	line = ft_calloc(sizeof(char) * BUFFER_SIZE);
	while (i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		ft_strcat(stash, buffer);
		






		fill line = fin du program
	}
}
