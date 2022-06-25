/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:51:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/25 15:53:32 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cotinue_add_pipe_arg(t_list **lst)
{
	char	*input;
	char	*aux;

	input = readline("> ");
	if (!input)
	{
		g_obj.error = 1;
		g_obj.exit_code = 258;
		g_obj.invalid_input = 1;
		printf("syntax error: unexpected end of file\n");
	}
	else
	{
		aux = ft_strtrim(input, " \t");
		if (aux[ft_strlen(aux) - 1] == '|')
		{
			ft_lstadd_back(lst, ft_lstnew(ft_substr(aux, 0,
						ft_chrpos(aux, '|') - 1)));
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("|")));
			cotinue_add_pipe_arg(lst);
		}
        else
            ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
		free(aux);
		free(input);
	}
}

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

static void	iterate_pipe_args(char *str, t_list **lst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(str) && str[i] && g_obj.invalid_input == 0)
	{
		i = increment_pipe_str(str, i);
		if (str[i] == '|')
		{
			ft_lstadd_back(lst, ft_lstnew(ft_strtrim(
						ft_substr(str, j, i - j), " \t")));
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("|")));
			j = i + 1;
		}
		i++;
	}
	if (str[j])
		ft_lstadd_back(lst, ft_lstnew(ft_strtrim(ft_substr(str, j, i - j), " \t")));
	else
	{
		signal(SIGINT, pipe_stop);
		cotinue_add_pipe_arg(lst);
	}
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
