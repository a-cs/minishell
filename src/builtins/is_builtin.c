/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:08:45 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/22 01:59:25 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_exit_cmd(void)
{
	int		result;
	char	**cmds;

	result = 0;
	cmds = ft_split(g_obj.input, ' ');
	if (cmds)
	{
		if (ft_memcmp(cmds[0], "exit", ft_strlen(cmds[0])) == 0
			&& ft_memcmp(cmds[0], "exit", 4) == 0)
			result = 1;
	}
	ft_free_matrix(cmds);
	return (result);
}

int	is_builtin(char **args)
{
	if (g_obj.error == 0 && args[0])
	{
		if (ft_memcmp(args[0], "exit", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "exit", 4) == 0)
			return (1);
		if (ft_memcmp(args[0], "pwd", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "pwd", 3) == 0)
			return (2);
		if (ft_memcmp(args[0], "echo", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "echo", 4) == 0)
			return (3);
		if (ft_memcmp(args[0], "env", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "env", 4) == 0)
			return (4);
		if (ft_memcmp(args[0], "export", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "export", 4) == 0)
			return (5);
		if (ft_memcmp(args[0], "unset", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "unset", 4) == 0)
			return (6);
	}
	return (0);
}
