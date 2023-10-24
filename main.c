#include "get_next_line.h"

int	main(void)
{
	int	file;

	file = open("readme.txt", O_RDONLY);
	// if (!file)
	// {
	// 	printf("fail fd");
	// 	return (0);
	// }
	get_next_line(file);
	return (0);
}