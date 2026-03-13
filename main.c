/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 09:22:17 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/13 09:22:57 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	int		count;
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;

	count = 0;
	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (1);
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%d: %s", ++count, line);
		free(line);
	}
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%d: %s", ++count, line);
		free(line);
	}
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("%d: %s", ++count, line);
		free(line);
	}
	//free(line);
	
	close(fd1);
	close(fd2);
	close(fd3);
	
	printf("\nFinal count: %d\n", count);
	return (0);
}
