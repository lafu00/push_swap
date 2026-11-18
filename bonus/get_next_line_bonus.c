/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:04:18 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/18 17:22:25 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_free(char *line, char *temp)
{
	char	*new_line;

	if (!line)
	{
		line = (char *) malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	if (!temp)
		return (line);
	new_line = ft_strjoinb(line, temp);
	free(line);
	return (new_line);
}

char	*fill_line(int fd, char *line)
{
	int		buffer;
	char	*temp;
	char	c;

	c = '\n';
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buffer = 1;
	while (!line || (!ft_strchrb(line, c) && buffer > 0))
	{
		buffer = read(fd, temp, BUFFER_SIZE);
		if (buffer == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[buffer] = '\0';
		line = ft_strjoin_free(line, temp);
	}
	free(temp);
	return (line);
}

char	*to_print(char *line)
{
	char	*out;
	int		i;
	char	c;

	c = '\n';
	if (!line || !line[0])
		return (NULL);
	i = 0;
	while (line[i] && line[i] != c)
		i++;
	if (line[i] == c)
		out = malloc(sizeof(char) * (i + 2));
	else
		out = malloc(sizeof(char) * (i + 1));
	if (!out)
		return (NULL);
	i = -1;
	while (line[++i] && line[i] != c)
		out[i] = line[i];
	if (line[i] == c)
		out[i++] = c;
	out[i] = '\0';
	return (out);
}

char	*to_free(char *line)
{
	char	*new_line;
	size_t	i;
	char	c;

	c = '\n';
	i = 0;
	while (line[i] && line[i] != c)
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	if (line[i + 1] == '\0')
	{
		free(line);
		return (NULL);
	}
	new_line = ft_substrb(line, i + 1, ft_strlenb(line) - (i + 1));
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*out;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	out = fill_line(fd, line[fd]);
	if (!out)
	{
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	line[fd] = out;
	out = to_print(line[fd]);
	line[fd] = to_free(line[fd]);
	return (out);
}
