/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:44:21 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/12 23:25:27 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_builtin(t_data *obj)
{
	if (ft_memcmp(obj->input, "exit", ft_strlen(obj->input)) == 0)
		exit_prompt(obj);
	if (ft_memcmp(obj->input, "pwd", ft_strlen(obj->input)) == 0)
		return (pwd_prompt());
	return (0);
}

void	check_input(t_data *obj)
{
	if (!check_builtin(obj))
	{
		printf("Command not found: %s\n", obj->input);
	}
}

char	*prompt_str(void)
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
		printf("Input => %s\n", obj->input);
		check_input(obj);
	}
	return (0);
}
