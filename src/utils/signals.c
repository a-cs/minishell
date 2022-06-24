/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:20:55 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/24 20:33:39 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	here_doc_stop(int signal)
{
	(void)signal;
	g_obj.exit_code = 130;
	g_obj.stop = 1;
}

void	new_prompt(int signal)
{
	(void)signal;
	g_obj.exit_code = 130;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	new_line(int signal)
{
	(void)signal;
	printf("\n");
}
