/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:32:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 20:36:48 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *s);
char	*ft_strdup_gnl(char *s);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);

#endif
