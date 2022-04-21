/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:22:45 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/21 16:16:09 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_linelen(const char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	if (i < BUFFER_SIZE && str[i] == '\n')
		i++;
	return (i);
}

static char	*line_cat(char *line, char *buffer, char *stc_line)
{
	int		i;
	char	*new_line;

	i = ft_linelen(buffer);
	new_line = malloc(sizeof(char) * (i + ft_strlen_gnl(line) + 1));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy_gnl(new_line, line, ft_strlen_gnl(line) + 1);
	ft_strlcpy_gnl(new_line + ft_strlen_gnl(line), buffer, i + 1);
	if (i < BUFFER_SIZE && i > 0 && buffer[i - 1] == '\n')
	{
		ft_bzero_gnl(stc_line, BUFFER_SIZE);
		ft_strlcpy_gnl(stc_line, buffer + i, BUFFER_SIZE - i + 1);
	}
	free(line);
	return (new_line);
}

static int	read_next_line(int fd, char *buffer, char *stc_line, char **line)
{
	int	n;

	if (*stc_line)
	{
		ft_strlcpy_gnl(buffer, stc_line, BUFFER_SIZE);
		ft_bzero_gnl(stc_line, BUFFER_SIZE);
		n = 1;
	}
	else
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < BUFFER_SIZE && n > 0)
			buffer[n] = '\0';
	}
	if (n > 0)
		*line = line_cat(*line, buffer, stc_line);
	if (!*line)
		return (0);
	return (n);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*line;
	static char	stc_line[BUFFER_SIZE] = "";
	int			n;

	if (fd < 0)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	*line = '\0';
	n = 1;
	while (n > 0 && (ft_strlen_gnl(line) == 0
			|| line[ft_strlen_gnl(line) - 1] != '\n'))
		n = read_next_line(fd, buffer, stc_line, &line);
	if (!line)
		return (NULL);
	if (*line)
		return (line);
	else
	{
		free (line);
		return (NULL);
	}
}
