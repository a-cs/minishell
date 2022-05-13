/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:44:21 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/13 00:05:25 by rfelipe-         ###   ########.fr       */
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

	if (argc != 1 && argv)
		return (1);
	obj = malloc(sizeof(t_data));
	obj->envp = envp;
	printf("Hello minishell\n");
	while (1)
	{
		obj->prompt = prompt_str();
		obj->input = readline(obj->prompt);
		check_input(obj);
	}
	return (0);
}
