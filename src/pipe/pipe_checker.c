/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:49:46 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/29 17:06:16 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	new_pipe(int do_output)
{
	int	new_pipe[2];

	dup2(g_obj.old_pipe_in, STDIN_FILENO);
	if (g_obj.old_pipe_in != 0)
		close(g_obj.old_pipe_in);
	if (!do_output)
		return ;
	pipe(new_pipe);
	dup2(new_pipe[OUT], STDOUT_FILENO);
	close(new_pipe[OUT]);
	g_obj.old_pipe_in = dup(new_pipe[IN]);
	close(new_pipe[IN]);
}

static void	save_actual_fd(void)
{
	g_obj.actual_fd[IN] = dup(STDIN_FILENO);
	g_obj.actual_fd[OUT] = dup(STDOUT_FILENO);
}

static void	save_history(char **args)
{
	char	*input;

	if (is_valid_history(g_obj.input))
	{
		input = ft_matrix_to_str(args);
		add_history(input);
		free(input);
	}
}

void	pipe_checker(void)
{
	int		i;
	char	**args;

	i = 0;
	args = pipe_args();
	save_history(args);
	while (args[i] && !g_obj.invalid_input)
	{
		if (args[i + 1] && args[i + 1][0] == '|')
		{
			save_actual_fd();
			new_pipe(TRUE);
		}
		else
		{
			new_pipe(FALSE);
			g_obj.close_code = TRUE;
		}
		execute(&args[i]);
		change_fd(g_obj.actual_fd);
		if (args[++i] && args[i][0] == '|')
			i++;
	}
	ft_free_matrix(args);
}
