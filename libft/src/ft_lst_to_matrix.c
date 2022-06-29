/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:44:27 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/29 18:30:41 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_lst_to_matrix(t_list *lst)
{
	int		i;
	char	**matrix;

	if (lst == NULL)
		return (NULL);
	i = ft_lstsize(lst);
	matrix = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (lst)
	{
		matrix[i] = ft_strdup((char *)lst->content);
		lst = lst->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
