/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:51:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/25 17:10:41 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	increment_pipe_str(char *str, int i)
{
	if (str[i] && str[i] == DOUBLE_QUOTES)
	{
		if (ft_chrpos(str + i + 1, DOUBLE_QUOTES) != -1)
			i += ft_chrpos(str + i + 1, DOUBLE_QUOTES) + 1;
		else
			g_obj.invalid_input = 1;
	}
	if (str[i] && str[i] == SINGLE_QUOTES)
	{
		if (ft_chrpos(str + i + 1, SINGLE_QUOTES) != -1)
			i += ft_chrpos(str + i + 1, SINGLE_QUOTES) + 1;
		else
			g_obj.invalid_input = 1;
	}
	return (i);
}

static void	add_last_pipe_arg(t_list **lst, char *str, int i, int j)
{
	char	*temp;
	char	*aux;

	if (str[j])
	{
		temp = ft_substr(str, j, i - j);
		aux = ft_strtrim(temp, " \t");
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
		free(temp);
		free(aux);
	}
	else
	{
		signal(SIGINT, pipe_stop);
		cotinue_add_pipe_arg(lst);
	}
}

static void	iterate_pipe_args(char *str, t_list **lst)
{
	int		i;
	int		j;
	char	*temp;
	char	*aux;

	i = 0;
	j = 0;
	while (i < ft_strlen(str) && str[i] && g_obj.invalid_input == 0)
	{
		i = increment_pipe_str(str, i);
		if (str[i] == '|')
		{	
			temp = ft_substr(str, j, i - j);
			aux = ft_strtrim(temp, " \t");
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
			free(temp);
			free(aux);
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("|")));
			j = i + 1;
		}
		i++;
	}
	add_last_pipe_arg(lst, str, i, j);
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
	if (lst)
		ft_lstclear(&lst, free);
	return (args);
}
