/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:54:12 by dylmarti          #+#    #+#             */
/*   Updated: 2023/10/24 20:09:18 by dydado13         ###   ########.fr       */
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
}

static char	*beforenewline(char *stash)
{
	char	*str;
	
	str = ft_calloc(sizeof(char), ft_strlen(stash));
	while (*stash - 1 != '\n')
	{
		*str = *stash;
		str++;
		stash++;
	}
	return (str);
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
	int		j;

	j = 0;
	printf("%i\n", BUFFER_SIZE);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	{
		i = read(fd, buffer, BUFFER_SIZE);
		stash = ft_strjoin(stash, buffer); // erreur stash == rien
		printf("%s\n", stash);
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
}
