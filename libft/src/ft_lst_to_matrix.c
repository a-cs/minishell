/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:44:27 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/18 00:51:04 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_lst_to_matrix(t_list *lst)
{
	int		i;
	char	**matrix;

	i = ft_lstsize(lst);
	matrix = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (lst)
	{
		matrix[i] = ft_strdup((char *)lst->content);
		lst = lst->next;
		i++;
	}
	return (matrix);
}
