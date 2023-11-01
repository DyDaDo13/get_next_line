#include "get_next_line.h"

int	main(void)
{
	int		file;
	char	*str;

	file = open("readme.txt", O_RDONLY);
	str = get_next_line(file);
	printf("%s", str);
	//printf("dad");
	// str = get_next_line(file);
	// printf("%s", str);
	free (str);
	return (0);
}