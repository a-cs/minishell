/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:52:02 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/29 16:58:04 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_flag(char **args)
{
	int	has_flag;

	if (g_obj.args_num > 1 && args[1])
	{
		has_flag = ft_memcmp(args[1], "-n", ft_strlen(args[1]))
			+ ft_memcmp(args[1], "-n", 2);
		if (has_flag)
			has_flag = ft_memcmp(args[1], "-n ", ft_strlen(args[1]))
				+ ft_memcmp(args[1], "-n ", 2);
		if (!has_flag && g_obj.args_num > 2
			&& !(args[1][2] == SPACE_VALUE || args[2][0] == SPACE_VALUE))
			has_flag = TRUE;
	}
	else
		has_flag = TRUE;
	return (has_flag);
}

void	echo_prompt(char **args)
{
	int		i;
	int		has_flag;

	has_flag = get_flag(args);
	if (!has_flag)
		i = 2;
	else
		i = 1;
	while (g_obj.args_num > 1 && args[i])
	{
		if (i == 2 && !has_flag && g_obj.args_num > 2
			&& args[2][0] == SPACE_VALUE)
			printf("%s", args[i] + 1);
		else
			printf("%s", args[i]);
		i++;
	}
	if (g_obj.args_num >= 1 && has_flag)
		printf("\n");
	g_obj.exit_code = 0;
}
