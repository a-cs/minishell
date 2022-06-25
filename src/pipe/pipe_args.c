/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:51:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/25 02:01:50 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	iterate_pipe_args(char *str, t_list **lst)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_strlen(str) && str[i] && g_obj.invalid_input == 0)
	{
		if (ft_chrpos(str, '|') == -1)
		{
			ft_lstadd_back(lst, ft_lstnew(ft_strtrim(ft_strdup(str), " \t")));
			return (ft_strlen(str));
		}
		if (str[i] == DOUBLE_QUOTES)
		{
			j = ft_chrpos(str + i + 1, DOUBLE_QUOTES);
			if (j != -1)
				i += j + 1;
			else
				g_obj.invalid_input = 1;
		}
		if (str[i] == '|')
		{
			ft_lstadd_back(lst, ft_lstnew(ft_strtrim(ft_substr(str, 0, i), " \t")));
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("|")));
			i += iterate_pipe_args(str + i + 1, lst);
		}
		i++;
	}
	return (i);
}

char	**pipe_args(void)
{
	char	**args;
	t_list	*lst;

	lst = NULL;
	iterate_pipe_args(g_obj.input, &lst);
	if (lst == NULL || g_obj.invalid_input != 0)
	{
		args = ft_calloc(2, sizeof(char *));
		args[0] = ft_strdup(g_obj.input);
	}
	else
		args = ft_lst_to_matrix(lst);
	return (args);
}
