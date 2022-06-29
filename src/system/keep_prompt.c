/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:10:42 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/29 16:34:53 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(char **input)
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
			execute_cmd(redirect_args(clean_quotes(
						replace_env_var(tokenizer(*input)))));
	}
	ft_free_matrix(args);
}

static void	execute_args(void)
{
	if (!is_exit_cmd())
	{
		save_fd(g_obj.initial_fd);
		g_obj.old_pipe_in = 0;
		pipe_checker();
		change_fd(g_obj.initial_fd);
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

static int	is_valid_input(char *input)
{
	char	*aux;
	char	**temp;

	check_eof(input);
	if (input[0] == '\0')
		return (0);
	if (ft_is_all_blank(input))
		return (0);
	aux = ft_strtrim(input, " \t");
	temp = clean_quotes(tokenizer(aux));
	free(aux);
	ft_free_matrix(temp);
	if (g_obj.invalid_input != 0)
		return (0);
	return (1);
}

void	keep_prompt(char **envp)
{
	char	*temp;

	g_obj.envp = dup_envp(envp);
	g_obj.exit_code = 0;
	start_msg();
	while (1)
	{
		reset_obj_data();
		signal(SIGINT, new_prompt);
		signal(SIGQUIT, SIG_IGN);
		temp = readline(g_obj.prompt);
		if (is_valid_input(temp))
		{
			g_obj.input = ft_strtrim(temp, " \t");
			execute_args();
		}
		if (g_obj.input)
			free(g_obj.input);
		free(temp);
		free(g_obj.prompt);
	}
}
