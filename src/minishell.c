/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:44:21 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/07 23:24:45 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*prompt_str(void)
{
	char	*str;

	str = "\001\033[1;96m\002Minishell \001\033[1;92m\002>\001\033[0m\002 ";
	return (str);
}

static void	check_eof(char *input, t_data *obj)
{
	if (input)
		return ;
	printf("exit\n");
	exit_prompt(obj);
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	*obj;
	char	*temp;

	if (argc != 1 && argv)
		return (1);
	obj = malloc(sizeof(t_data));
	obj->envp = envp;
	printf("Hello minishell\n");
	while (1)
	{
		obj->error = 0;
		obj->args_num = 0;
		obj->prompt = prompt_str();
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
