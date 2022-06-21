/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:10:42 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/21 17:12:04 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*prompt_str(void)
{
	char	*str;

	str = "\001\033[1;96m\002Minishell \001\033[1;92m\002>\001\033[0m\002 ";
	return (str);
}

static void	check_eof(char *input)
{
	if (input)
		return ;
	printf("exit\n");
	exit_prompt();
}

static char	**dup_envp(char **envp)
{
	int		i;
	int		len;
	char	**temp;

	len = 0;
	while (envp[len])
		len++;
	temp = ft_calloc(len + 1, sizeof(char *));
	i = 0;
	while (i < len)
	{
		temp[i] = ft_strdup(envp[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

void	keep_prompt(char **envp)
{
	char	*temp;

	g_obj.envp = dup_envp(envp);
	g_obj.exit_code = 0;
	while (1)
	{
		g_obj.error = 0;
		g_obj.args_num = 0;
		g_obj.prompt = prompt_str();
		g_obj.input = NULL;
		signal(SIGINT, new_prompt);
		signal(SIGQUIT, SIG_IGN);
		temp = readline(g_obj.prompt);
		check_eof(temp);
		g_obj.input = ft_strtrim(temp, " \t");
		check_input();
		if (g_obj.input)
			free(g_obj.input);
	}
}
