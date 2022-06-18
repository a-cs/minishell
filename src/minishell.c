/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:44:21 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/18 18:32:16 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*prompt_str(void)
{
	char	*str;

	str = "\001\033[1;96m\002Minishell \001\033[1;92m\002>\001\033[0m\002 ";
	return (str);
}

static void	set_obj_data(t_data *obj)
{
	obj->error = 0;
	obj->args_num = 0;
	obj->exit_code = 0;
	obj->prompt = prompt_str();
	obj->input = NULL;
}

static void	check_eof(char *input, t_data *obj)
{
	if (input)
		return ;
	printf("exit\n");
	exit_prompt(obj);
}

static void	dup_envp(t_data *obj, char **envp)
{
	int		i;
	int		len;

	len = 0;
	while (envp[len])
		len++;
	obj->envp = ft_calloc(len + 1, sizeof(char *));
	i = 0;
	while (i < len)
	{
		obj->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	obj->envp[i] = NULL;
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	*obj;
	char	*temp;

	if (argc != 1 && argv)
		return (1);
	obj = malloc(sizeof(t_data));
	dup_envp(obj, envp);
	printf("Hello minishell\n");
	while (1)
	{
		set_obj_data(obj);
		signal(SIGINT, new_prompt);
		signal(SIGQUIT, SIG_IGN);
		temp = readline(obj->prompt);
		check_eof(temp, obj);
		obj->input = ft_strtrim(temp, " \t");
		check_input(obj);
		if (obj->input)
			free(obj->input);
	}
	return (0);
}
