#include "get_next_line.h"

int	main(void)
{
	int	file;

	file = open("text.txt", O_WRONLY | O_RDONLY);
	get_next_line(file);
	return (0);
}