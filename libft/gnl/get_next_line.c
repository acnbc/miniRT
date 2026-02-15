/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:07:56 by jesda-si          #+#    #+#             */
/*   Updated: 2026/02/15 04:47:26 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*read;
	char		*line;
	ssize_t		len_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len_read = 1;
	line = NULL;
	read = NULL;
	while (len_read > 0 && !ft_strchr((char const *)buffer[fd], '\n'))
	{
		read = read_fd(fd, &len_read);
		if (len_read < 0)
			return (free_str(buffer[fd]));
		if (ft_linelen(read, 0) == 0)
			break ;
		buffer[fd] = ft_join_buffer(buffer[fd], read);
		if (!buffer[fd])
			return (NULL);
	}
	line = div_buffer(&buffer[fd]);
	return (line);
}

char	*div_buffer(char **buffer)
{
	char	*cpy;
	char	*line;
	char	*new_line;

	cpy = NULL;
	line = NULL;
	new_line = ft_strchr((char const *)*buffer, '\n');
	if (new_line && *new_line && new_line[1])
	{
		line = ft_subline(*buffer, 1);
		cpy = ft_subline(&new_line[1], 0);
		*buffer = free_str(*buffer);
		*buffer = cpy;
	}
	else
	{
		line = ft_subline(*buffer, 0);
		cpy = free_str(cpy);
		*buffer = free_str(*buffer);
	}
	if (!ft_linelen(line, 0))
		return (free_str(line));
	return (line);
}

char	*read_fd(int fd, ssize_t *len)
{
	char	*buffer;
	ssize_t	i;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		*len = -1;
		return (NULL);
	}
	i = 0;
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = '\0';
	*len = read(fd, buffer, BUFFER_SIZE);
	if (*len < 0)
	{
		buffer = free_str(buffer);
		*len = -1;
	}
	else if (*len == 0)
	{
		buffer = free_str(buffer);
		*len = 0;
	}
	return (buffer);
}

char	*free_str(char *str)
{
	if (!str)
		return (NULL);
	free(str);
	return (NULL);
}
