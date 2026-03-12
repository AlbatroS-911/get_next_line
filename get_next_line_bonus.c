/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:39:41 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/12 16:30:13 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	line_length(char *str)
{
	int	loop;

	loop = 0;
	while (str[loop] && str[loop] != '\n')
		loop++;
	if (str[loop] == '\n')
		loop++;
	return (loop);
}

static char	*get_line(char *str)
{
	char	*fresh_line;
	int		k;

	if (!str || !*str)
		return (NULL);
	k = line_length(str);
	fresh_line = malloc((k + 1) * sizeof(char));
	if (!fresh_line)
		return (NULL);
	k = 0;
	while (str[k] && str[k] != '\n')
	{
		fresh_line[k] = str[k];
		k++;
	}
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

static char	*read_and_store(int fd, char *temp)
{
	char	*buffer;
	char	*updated_temp;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!temp)
			temp = ft_strdup("");
		updated_temp = ft_strjoin(temp, buffer);
		free(temp);
		temp = updated_temp;
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = read_and_store(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = get_line(temp[fd]);
	clear_temp(&temp[fd]);
	return (line);
}
