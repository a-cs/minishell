/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:02:17 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/29 17:06:53 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	throw_add_pipe_error(t_list **lst)
{
	if (!g_obj.invalid_input)
	{
		g_obj.error = TRUE;
		g_obj.exit_code = 2;
		g_obj.invalid_input = TRUE;
		ft_putendl_fd("syntax error: unexpected end of file", STDERR_FILENO);
		if (lst)
			ft_lstclear(lst, free);
		exit_prompt();
	}
}

void	cotinue_add_pipe_arg(t_list **lst)
{
	char	*input;
	char	*aux;

	input = readline("> ");
	if (!input)
		throw_add_pipe_error(lst);
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
