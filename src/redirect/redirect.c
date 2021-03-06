/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:20:18 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/29 17:15:04 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	especial_case_fd(char *file, char *redirect)
{
	int	fd;

	if (ft_memcmp(redirect, "<<>", 3) == 0 || ft_memcmp(redirect, "><", 2) == 0)
	{
		g_obj.error = TRUE;
		g_obj.exit_code = 2;
		change_fd(g_obj.initial_fd);
		ft_putendl_fd("Redirect: syntax error near unexpected token `<'",
			STDERR_FILENO);
	}
	else if (ft_memcmp(redirect, "<>>", 3) == 0)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
		close(fd);
		change_input(file, O_RDONLY);
	}
	else if (ft_memcmp(redirect, "<>", 2) == 0)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		close(fd);
		change_input(file, O_RDONLY);
	}
}

static void	do_redirect(char *redirect, char *file)
{
	if (ft_memcmp(redirect, "<<>", 3) == 0
		|| ft_memcmp(redirect, "<>>", 3) == 0
		|| ft_memcmp(redirect, "<>", 2) == 0
		|| ft_memcmp(redirect, "><", 2) == 0)
		especial_case_fd(file, redirect);
	else if (ft_memcmp(redirect, ">>", 2) == 0)
		change_output(file, O_WRONLY | O_CREAT | O_APPEND);
	else if (ft_memcmp(redirect, "<<", 2) == 0)
		here_doc(file);
	else if (ft_memcmp(redirect, ">", 1) == 0)
		change_output(file, O_WRONLY | O_CREAT | O_TRUNC);
	else if (ft_memcmp(redirect, "<", 1) == 0)
		change_input(file, O_RDONLY);
}

static int	is_valid_redirection(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_chrqty(args[i], '>') > 0 || ft_chrqty(args[i], '<') > 0)
		{
			if ((args[i][0] == '>' || args[i][0] == '<') &&
				((ft_chrqty(args[i], '>') > 2 || ft_chrqty(args[i], '<') > 2)
				|| (!args[i + 1] || ft_chrqty(args[i + 1], '>') > 0
					|| ft_chrqty(args[i + 1], '<') > 0)))
			{
				g_obj.exit_code = 2;
				return (FALSE);
			}
		}
		i++;
	}
	return (TRUE);
}

void	redirect(char **input)
{
	int		i;
	char	**args;

	args = redirect_args(replace_env_var(tokenizer(*input)));
	if (!is_valid_redirection(args))
	{
		g_obj.error = TRUE;
		ft_putendl_fd("Redirect: syntax error", STDERR_FILENO);
	}
	else
	{
		i = 0;
		while (args[i] && args[i + 1])
		{
			do_redirect(args[i], args[i + 1]);
			i++;
		}
		clean_redirect_input(args, input);
	}
	ft_free_matrix(args);
}
