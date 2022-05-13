/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:44:21 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/12 22:09:46 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*prompt_str(void)
{
	char	*str;

	str = "\001\033[1;96m\002Minishell \001\033[1;92m\002>\001\033[0m\002 ";
	return (str);
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	obj;

	if (argc != 1 && argv)
		return (1);
	obj.envp = envp;
	printf("Hello minishell\n");
	while (1)
	{
		obj.prompt = prompt_str();
		obj.input = readline(obj.prompt);
		printf("Input => %s\n", obj.input);
		if (ft_memcmp(obj.input, "exit", 4) == 0)
			exit_prompt(&obj);
		if (ft_memcmp(obj.input, "pwd", 4) == 0)
			pwd_prompt();
	}
	return (0);
}
