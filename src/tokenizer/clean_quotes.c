/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:10:11 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/29 16:35:59 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	populate_list(char *temp, t_list **char_list, int i)
{
	int	j;

	if (temp[0] == SINGLE_QUOTES)
	{
		j = ft_chrpos(temp + 1, SINGLE_QUOTES);
		if (j == -1)
			throw_unclosed_quotes_error();
		else
			ft_lstadd_back(char_list, ft_lstnew(ft_substr(temp, 1, j)));
		i += j + 2;
	}
	else
	{
		j = i;
		while (temp[j] != DOUBLE_QUOTES && temp[j] != SINGLE_QUOTES
			&& temp[j] != '\0')
			j++;
		ft_lstadd_back(char_list, ft_lstnew(ft_substr(temp, 0, j)));
		i += j;
	}
	return (i);
}

static int	iterate_and_clean(char *temp, t_list **char_list)
{
	int	i;
	int	j;

	i = 0;
	if (g_obj.error != 0)
		return (ft_strlen(temp));
	while (g_obj.error == 0 && temp[i] != '\0')
	{
		if (temp[0] == DOUBLE_QUOTES)
		{
			j = ft_chrpos(temp + 1, DOUBLE_QUOTES);
			if (j == -1)
				throw_unclosed_quotes_error();
			else
				ft_lstadd_back(char_list, ft_lstnew(ft_substr(temp, 1, j)));
			i += j + 2;
		}
		else
			i = populate_list(temp, char_list, i);
		i += iterate_and_clean(temp + i, char_list);
	}
	return (i);
}

char	**clean_quotes(char **temp)
{
	int		i;
	char	**args;
	t_list	*char_list;

	args = ft_calloc(g_obj.args_num + 1, sizeof(char *));
	i = 0;
	while (i < g_obj.args_num)
	{
		char_list = NULL;
		iterate_and_clean(temp[i], &char_list);
		args[i] = join_list(char_list);
		ft_lstclear(&char_list, free);
		i++;
	}
	args[i] = NULL;
	ft_free_matrix(temp);
	return (args);
}
