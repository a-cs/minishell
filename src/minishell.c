/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:44:21 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/01 00:05:33 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*prompt_str(void)
{
	char	*str;

	str = "\001\033[1;96m\002Minishell \001\033[1;92m\002>\001\033[0m\002 ";
	return (str);
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
		obj->input = temp;
		check_input(obj);
	}
	return (0);
}
