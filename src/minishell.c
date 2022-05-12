/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:44:21 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/11 22:42:13 by rfelipe-         ###   ########.fr       */
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
	char	*prompt;
	char	*input;

	(void)argv;
	(void)envp;
	if (argc != 1)
		return (1);
	printf("Hello minishell\n");
	while (1)
	{
		prompt = prompt_str();
		input = readline(prompt);
		printf("Input => %s\n", input);
		if (ft_memcmp(input, "exit", 4) == 0)
			exit_prompt(input);
	}
	return (0);
}
