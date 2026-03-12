/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 09:22:17 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/12 17:01:27 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	int		fd1, fd2, fd3;
	int		count;
	char	*line;

	count = 0;
	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	// if (fd == -1)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	line = get_next_line(fd1);
	printf("%d: %s", ++count, line);
	line = get_next_line(fd2);
	printf("%d: %s", ++count, line);
	line = get_next_line(fd3);
	printf("%d: %s", ++count, line);
	free(line);

	close(fd1);
	close(fd2);
	close(fd3);
	printf("\nFinal count: %d\n", count);
	return (0);
}
