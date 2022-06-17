/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:52:02 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/17 19:18:24 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_flag(t_data *obj, char **args)
{
	int	has_flag;

	if (obj->args_num > 1)
	{
		has_flag = ft_memcmp(args[1], "-n", ft_strlen(args[1]))
			+ ft_memcmp(args[1], "-n", 2);
		if (has_flag != 0)
			has_flag = ft_memcmp(args[1], "-n ", ft_strlen(args[1]))
				+ ft_memcmp(args[1], "-n ", 2);
		if (has_flag == 0 && obj->args_num > 2
			&& !(args[1][2] == SPACE_VALUE || args[2][0] == SPACE_VALUE))
			has_flag = 1;
	}
	else
		has_flag = 1;
	return (has_flag);
}

int	echo_prompt(char **args, t_data *obj)
{
	int		i;
	int		has_flag;

	has_flag = get_flag(obj, args);
	if (has_flag == 0)
		i = 2;
	else
		i = 1;
	while (obj->args_num > 1 && args[i])
	{
		if (i == 2 && has_flag == 0 && obj->args_num > 2
			&& args[2][0] == SPACE_VALUE)
			printf("%s", args[i] + 1);
		else
			printf("%s", args[i]);
		i++;
	}
	if (obj->args_num > 1 && has_flag != 0)
		printf("\n");
	obj->exit_code = 0;
	return (1);
}
