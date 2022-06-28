/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:38:13 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/27 21:56:15 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	populate_redirect_lst(t_list **lst, char *str, int i, int j)
{
	char	*temp;
	char	*aux;

	if (str[i] == '>' || str[i] == '<')
	{
		if (i > 0 || j > 0)
		{
			temp = ft_substr(str, j, i - j);
			aux = ft_strtrim(temp, " \t");
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
			free(temp);
			free(aux);
			j = i;
		}
		while (str[i] == '>' || str[i] == '<')
			i++;
		temp = ft_substr(str, j, i - j);
		aux = ft_strtrim(temp, " \t");
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
		j = i;
		free(temp);
		free(aux);
	}
	return (i);
}

static void	split_redirect_args(char *str, t_list **lst)
{
	int		i;
	int		j;
	char	*temp;
	char	*aux;

	i = 0;
	j = 0;
	while (i < ft_strlen(str) && str[i] && g_obj.invalid_input == 0)
	{
		i = increment_all_str_quotes(str, i);
		if (str[i] == '>' || str[i] == '<')
		{
			i = populate_redirect_lst(lst, str, i, j);
			j = i;
		}
		i++;
	}
	if (str[j])
	{
		temp = ft_substr(str, j, i - j);
		aux = ft_strtrim(temp, " \t");
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
		free(temp);
		free(aux);
	}
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
