/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:10:42 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/22 21:07:14 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	execute_children(char **input)
{
	int		code;
	char	**args;

	redirect(input);
	args = clean_quotes(replace_env_var(tokenizer(*input)));
	if (g_obj.error == 0 && args[0])
	{
		code = is_builtin(args);
		if (code != 0)
			execute_builtin(args, code);
		else
			execute_cmd(args);
	}
	ft_free_matrix(args);
	g_obj.close_code = 1;
}

static void	execute_args(void)
{
	int	fd[2];
	int	pid;

	if (!is_exit_cmd())
	{
		pipe(fd);
		pid = fork();
		signal(SIGINT, new_line);
		if (pid == 0)
			execute_children(&g_obj.input);
		waitpid(pid, NULL, 0);
		close(fd[0]);
		close(fd[1]);
	}
	else
		exit_prompt();
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
	g_obj.close_code = 0;
	while (g_obj.close_code == 0)
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
