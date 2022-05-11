/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:32:11 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/13 23:16:11 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int	ft_remove_nl(char **save, char **line)
{
	char	*temp;
	int		size;

	size = 0;
	while ((*save)[size] != '\0' && (*save)[size] != '\n')
		size++;
	if ((*save)[size] == '\0')
	{
		*line = ft_strdup_gnl(*save);
		if (*save != NULL)
		{
			free(*save);
			*save = NULL;
		}
		return (0);
	}
	*line = ft_substr_gnl(*save, 0, size);
	temp = ft_strdup_gnl((*save) + size + 1);
	free(*save);
	*save = temp;
	return (1);
}

static int	ft_result(char **save, char **line, ssize_t size)
{
	if (size == -1 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (*save == NULL && size == 0)
	{
		*line = ft_strdup_gnl("");
		return (0);
	}
	return (ft_remove_nl(save, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	char		*temp;
	ssize_t		size;

	buf = malloc(BUFFER_SIZE + 1);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = '\0';
		if (!save)
			save = ft_strdup_gnl(buf);
		else
		{
			temp = ft_strjoin_gnl(save, buf);
			free(save);
			save = temp;
		}
		if (ft_strchr_gnl(save))
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ft_result(&save, line, size));
}
