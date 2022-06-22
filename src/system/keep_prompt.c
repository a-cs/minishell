/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:10:42 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/21 22:44:19 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	execute_args(void)
{
	int		code;
	char	**args;

	args = clean_quotes(replace_env_var(tokenizer()));
	if (g_obj.error == 0 && args[0])
	{
		code = is_builtin(args);
		if (code != 0)
			execute_builtin(args, code);
		else
			execute_cmd(args);
	}
	ft_free_matrix(args);
}

static void	check_eof(char *input)
{
	if (input)
		return ;
	printf("exit\n");
	exit_prompt();
}

void	keep_prompt(char **envp)
{
	char	*temp;

	g_obj.envp = dup_envp(envp);
	g_obj.exit_code = 0;
	while (1)
	{
		reset_obj_data();
		signal(SIGINT, new_prompt);
		signal(SIGQUIT, SIG_IGN);
		temp = readline(g_obj.prompt);
		check_eof(temp);
		g_obj.input = ft_strtrim(temp, " \t");
		execute_args();
		if (g_obj.input)
			free(g_obj.input);
	}
}
