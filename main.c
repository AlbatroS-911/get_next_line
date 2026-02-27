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
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("%d: %s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	printf("Final count: %d\n", count);
	return (0);
}
