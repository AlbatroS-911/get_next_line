/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:39:41 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/04 13:54:04 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

static char	*get_line(char *str)
{
	char	*fresh_line;
	int		k;

	k = 0;
	if (!str || !*str)
		return (NULL);
	while (str[k] && str[k] != '\n')
		k++;
	if (str[k] == '\n')
		k++;
	fresh_line = malloc((k + 1) * sizeof(char));
	if (!fresh_line)
		return(NULL);
	k = 0;
	while (str[k] && str[k] != '\n')
	{
		fresh_line[k] = str[k];
		k++;
	}
	printf("k = %d\n", k);
	if (str[k] == '\n')
	{
		fresh_line[k] = '\n';
		k++;
	}
	fresh_line[k] = '\0';
	return (fresh_line);
}

static void	clear_temp(char **temp)
{
	char	*new_temp;
	char	*nl_pos;

	if (!temp || !*temp)
		return ;
	nl_pos = ft_strchr(*temp, '\n');
	if (!nl_pos)
	{
		free(*temp);
		*temp = NULL;
		return ;
	}
	new_temp = ft_strdup(nl_pos + 1);
	free(*temp);
	*temp = new_temp;
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*updated_temp;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		updated_temp = ft_strjoin(temp, buffer);
		if (!temp)
			temp = ft_strdup("");
		free(temp);
		temp = updated_temp;
	}
	line = get_line(temp);
	clear_temp(&temp);
	return (line);
}
