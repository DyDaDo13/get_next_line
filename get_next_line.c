/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:54:12 by dylmarti          #+#    #+#             */
/*   Updated: 2023/10/25 13:31:28 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#define BUFFER_SIZE 5

static char	*rmthings(char *stash)
{
	char *stash2;
	
	stash2 = ft_calloc(sizeof(char), ft_strlen(stash));
	while (*stash != '\0')
	{
		if (*stash == '\n')
		{
			while (*stash)
			{
				*stash2 = *stash;
				stash++;
				stash2++;
			}
			return (stash2);
		}
		stash++;
	}
	return (stash);
}

static char	*beforenewline(char *line, char *stash)
{	
	int	i;

	i = 0;
	while (stash[i] - 1 != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	while (*stash - 1 != '\n')
	{
		*line = *stash;
		line++;
		stash++;
	}
	return (line);
}

static int	newline(char *stash)
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

	stash = "";
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	i = read(fd, buffer, BUFFER_SIZE);
	while (i != 0)
	{
		stash = ft_strjoin(stash, buffer);
		// if (newline(stash) == 1)
		// {
		// 	return (0);
		// 	beforenewline(line, stash);
		// 	stash = rmthings(stash);
		// 	free (buffer);
		// 	printf("%s\n", stash);
		// 	printf("%s\n", line);
		// 	return (line);
		// }
		printf("i : %i\n", i);
		printf("BUFFER_SIZE %i\n", BUFFER_SIZE);
		printf("buffer : %s\n", buffer);
		printf("%s\n", stash);
		printf("\n");
		ft_bzero(buffer, BUFFER_SIZE);
		i = read(fd, buffer, BUFFER_SIZE);
	}

	
	// i = read(fd, buffer, i);
	// printf("i : %i\n", i);
	// printf("buffer : %s\n", buffer);
	// stash = ft_strjoin("bonjo", "ur");
	// printf("%s", stash);
	// printf("%s\n", stash);
	// printf("%i\n", i);
	return (0);
}
/*
		return (0);
// 		printf("%s", stash);
// 		return (0);
// //		if (newline(stash) == 1)
// 		while (*buffer)
// 		{
// 			*stash = *buffer;
// 			stash++;
// 			buffer++;
// 		}
		printf("hola");
		return (0);
	}
	printf("hey");
	return (0);
}*/
