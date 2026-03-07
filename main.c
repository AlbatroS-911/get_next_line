/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 09:22:17 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/07 09:22:31 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf("\nFinal count: %d\n", count);
	return (0);
}
