/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:09:04 by fsousa            #+#    #+#             */
/*   Updated: 2025/08/26 09:09:26 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *buffer)
{
	ssize_t	b_read;
	char	*tmp_buffer;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(tmp_buffer);
			free(buffer);
			return (NULL);
		}
		tmp_buffer[b_read] = '\0';
		buffer = join_and_free(buffer, tmp_buffer);
		if (ft_strchr(tmp_buffer, '\n'))
			break ;
	}
	free(tmp_buffer);
	return (buffer);
}

static char	*create_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

static char	*sanitize_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer) - i), sizeof(char));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = create_line(buffer[fd]);
	buffer[fd] = sanitize_buffer(buffer[fd]);
	return (line);
}
