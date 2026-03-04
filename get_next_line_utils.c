/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:40:05 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/04 13:10:33 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		counter;
	size_t	str_length;

	counter = 0;
	str_length = ft_strlen(str);
	if (!str)
		return (NULL);
	dest = (char *)malloc((str_length + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (str[counter] != '\0')
	{
		dest[counter] = str[counter];
		counter++;
	}
	dest[counter] = '\0';
	return (dest);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";
	new_str = malloc((ft_strlen(str1) + ft_strlen(str2)) * sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		new_str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
		new_str[i++] = str2[j++];
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	int		count;

	if (!s)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count++;
	}
	if (s[count] == (char)c)
		return ((char *)&s[count]);
	return (NULL);
}
