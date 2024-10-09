/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elallema <elallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:07:46 by elallema          #+#    #+#             */
/*   Updated: 2023/03/19 18:12:30 by elallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_linebreak(const char *buffer)
{
	int	i;

	if (!buffer)
		return (0);
	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			return (1);
	}
	return (0);
}

char	*keep_to_line(char *keep, char *buff)
{
	char	*line;
	int		i;

	i = 0;
	while (keep[i] && keep[i] != '\n')
		i++;
	if (keep[i] == '\n')
		i++;
	line = ft_substr(keep, 0, i);
	ft_memcpy(buff, keep + i, ft_strlen(keep) - i + 1);
	return (line);
}

char	*buff_to_keep(char *keep, char *buff)
{
	char	*dest;

	if (!keep)
	{
		return (ft_strdup(buff));
	}
	dest = ft_strjoin(keep, buff);
	free(keep);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*keep;
	char		*line;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	keep = NULL;
	keep = buff_to_keep(keep, buff);
	read_size = BUFFER_SIZE;
	while (read_size == BUFFER_SIZE && !has_linebreak(buff))
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
			return (free(keep), NULL);
		buff[read_size] = '\0';
		if (read_size == 0 && !keep[0])
			return (free(keep), NULL);
		keep = buff_to_keep(keep, buff);
	}
	line = keep_to_line(keep, buff);
	free(keep);
	return (line);
}
