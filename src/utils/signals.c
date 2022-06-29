/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:20:55 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/28 23:20:05 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pipe_stop(int signal)
{
	if (signal == SIGINT)
	{
		g_obj.exit_code = 130;
		g_obj.error = 1;
		g_obj.invalid_input = 1;
		ft_putendl_fd("", g_obj.initial_fd[1]);
		rl_replace_line("", 0);
		rl_done = 1;
		close(rl_instream->_fileno);
	}
	return ;
}

void	here_doc_stop(int signal)
{
	if (signal == SIGINT)
	{
		g_obj.exit_code = 130;
		g_obj.error = 1;
		g_obj.invalid_input = 1;
		ft_putendl_fd("", 1);
		rl_replace_line("", 0);
		rl_done = 1;
		close(rl_instream->_fileno);
	}
	return ;
}

void	quit_exec(int signal)
{
	(void)signal;
	g_obj.exit_code = 131;
	g_obj.error = 1;
	g_obj.invalid_input = 1;
	ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
}

void	new_prompt(int signal)
{
	(void)signal;
	g_obj.exit_code = 130;
	ft_putendl_fd("", g_obj.initial_fd[1]);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	new_line(int signal)
{
	(void)signal;
	g_obj.exit_code = 130;
	g_obj.invalid_input = 1;
	g_obj.error = 1;
	ft_putendl_fd("", g_obj.initial_fd[1]);
}
