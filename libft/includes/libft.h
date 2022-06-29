/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:36:32 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/29 00:36:20 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_atoi(char *str);
int		ft_chrpos(char *s, int c);
int		ft_chrqty(char *s, int c);
int		ft_is_all_blank(char *str);
int		ft_is_all_digit(char *c, int len);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_lstsize(t_list *lst);
int		ft_memcmp(void *s1, void *s2, size_t n);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_matrix_to_str(char **matrix);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_lst_to_matrix(t_list *lst);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, size_t n);
void	ft_free_matrix(char **matrix);
void	ft_free_ptr(void **ptr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *str, int fd);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, void *src, size_t n);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);

#endif
