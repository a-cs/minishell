/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:49:46 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/25 01:38:43 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static char	*pipe_cleaner(void)
// {
// 	int		pipe_pos;
// 	char	*before_pipe;
// 	char	*after_pipe;

// 	pipe_pos = ft_chrpos(g_obj.input, '|');
// 	before_pipe = ft_substr(g_obj.input, 0, pipe_pos);
// 	after_pipe = ft_substr(g_obj.input, pipe_pos + 1,
// 			ft_strlen(g_obj.input + pipe_pos + 1));
// 	free(g_obj.input);
// 	g_obj.input = ft_strdup(after_pipe);
// 	free(after_pipe);
// 	return (before_pipe);
// }

static void	new_pipe(int do_output)
{
	int	new_pipe[2];

	dup2(g_obj.old_pipe_in, STDIN_FILENO);
	if (g_obj.old_pipe_in != 0)
		close(g_obj.old_pipe_in);
	if (!do_output)
		return ;
	pipe(new_pipe);
	dup2(new_pipe[1], STDOUT_FILENO);
	close(new_pipe[1]);
	g_obj.old_pipe_in = dup(new_pipe[0]);
	close(new_pipe[0]);
}

static void	save_actual_fd(void)
{
	g_obj.actual_fd[0] = dup(STDIN_FILENO);
	g_obj.actual_fd[1] = dup(STDOUT_FILENO);
}

void	pipe_checker(void)
{
	int		i;
	char	**args;

	i = 0;
	args = pipe_args();
	while (args[i])
	{
		if (args[i + 1] && args[i + 1][0] == '|')
		{
			save_actual_fd();
			new_pipe(1);
		}
		else
		{
			new_pipe(0);
			g_obj.close_code = 1;
		}
		execute(&args[i]);
		change_fd(g_obj.actual_fd);
		if (args[i + 1] && args[i + 1][0] == '|')
			i++;
		i++;
	}
	ft_free_matrix(args);
}
