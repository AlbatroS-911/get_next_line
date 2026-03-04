#include "fcntl.h"
#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d: %s", ++count, line);
		free(line);
	}
	close(fd);
	printf("Final count: %d\n", count);
	return (0);
}

