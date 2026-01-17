/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:02:59 by akheiral          #+#    #+#             */
/*   Updated: 2026/01/17 12:38:35 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

char	*extract_leftover(char *leftover)
{
	int		i;
	char	*new_leftover;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	new_leftover = ft_substr(leftover, i + 1, ft_strlen(leftover) + 1);
	free(leftover);
	if (new_leftover && *new_leftover == '\0')
	{
		free(new_leftover);
		return (NULL);
	}
	return (new_leftover);
}

char	*extract_line(char *str)
{
	int		len;

	if (!str || !*str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		return (ft_substr(str, 0, len + 1));
	return (ft_substr(str, 0, len));
}

int	is_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *leftover)
{
	ssize_t	nchars;
	char	*tmp;
	char	*buffer;

	if (!leftover)
		leftover = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nchars = 1;
	while (!is_line(leftover) && nchars != 0)
	{
		nchars = read(fd, buffer, BUFFER_SIZE);
		if (nchars == -1)
		{
			return (free(buffer), free(leftover), NULL);
		}
		buffer[nchars] = '\0';
		tmp = leftover;
		leftover = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover[fd] = read_line(fd, leftover[fd]);
	if (!leftover[fd] || *leftover[fd] == '\0')
	{
		free(leftover[fd]);
		leftover[fd] = NULL;
		return (NULL);
	}
	line = extract_line(leftover[fd]);
	leftover[fd] = extract_leftover(leftover[fd]);
	return (line);
}
