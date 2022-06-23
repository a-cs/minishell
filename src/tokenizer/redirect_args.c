/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:38:13 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/23 00:03:34 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	split_redirect_args(char *str, t_list **lst)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str) && str[i])
	{
		i = ft_chrpos(str, '>');
		if (i == -1)
			i = ft_chrpos(str, '<');
		if (i == -1)
		{
			ft_lstadd_back(lst, ft_lstnew(ft_strtrim(str, " \t")));
			return (ft_strlen(str));
		}
		else if (i == 0)
		{
			while (str[i] && (str[i] == '>' || str[i] == '<'))
				i++;
			ft_lstadd_back(lst, ft_lstnew(ft_substr(str, 0, i)));
		}
		else
			ft_lstadd_back(lst, ft_lstnew(ft_strtrim(
						ft_substr(str, 0, i), " \t")));
		i += split_redirect_args(str + i, lst);
	}
	return (i);
}

char	**redirect_args(char **temp)
{
	int		i;
	char	**args;
	t_list	*redirect_args_lst;

	redirect_args_lst = NULL;
	i = 0;
	while (temp[i])
	{
		split_redirect_args(temp[i], &redirect_args_lst);
		i++;
	}
	args = ft_lst_to_matrix(redirect_args_lst);
	ft_lstclear(&redirect_args_lst, free);
	ft_free_matrix(temp);
	return (args);
}
