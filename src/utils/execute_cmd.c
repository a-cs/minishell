/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:41:20 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/22 01:49:26 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_path(char *command)
{
	char	**env_path;
	char	*temp_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(g_obj.envp[i], "PATH", 4) == 0)
		i++;
	env_path = ft_split(g_obj.envp[i] + 5, ':');
	i = 0;
	while (env_path[i])
	{
		temp_path = ft_strjoin(env_path[i], "/");
		path = ft_strjoin(temp_path, command);
		free(temp_path);
		if (access(path, F_OK) == 0)
		{
			ft_free_matrix(env_path);
			return (path);
		}
		i++;
		free(path);
	}
	ft_free_matrix(env_path);
	return (0);
}

static int	check_envp(char **args)
{
	if (ft_chrpos(args[0], '/') != -1)
		g_obj.exit_code = execve(args[0], args, g_obj.envp);
	else
		g_obj.exit_code = execve(get_path(args[0]), args, g_obj.envp);
	if (g_obj.exit_code == -1)
		return (0);
	return (1);
}

static char	*try_path(char	**args)
{
	char	*path;

	if (ft_chrpos(args[0], '/') != -1)
	{
		if (access(args[0], F_OK) == 0)
			path = ft_strjoin(args[0], "");
		else
			path = NULL;
	}
	else
		path = get_path(args[0]);
	return (path);
}

void	execute_cmd(char **args)
{
	char	*path;

	path = try_path(args);
	if (path)
	{
		free(path);
		if (!check_envp(args))
			printf("Error -> Command not found: %s\n", args[0]);
	}
	else
	{
		printf("Command not found: %s\n", args[0]);
		g_obj.exit_code = 127;
	}
}
