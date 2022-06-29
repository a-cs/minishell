/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:41:20 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/29 17:21:24 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*join_path(char *env_path, char *command)
{
	char	*temp_path;
	char	*path;

	temp_path = ft_strjoin(env_path, "/");
	path = ft_strjoin(temp_path, command);
	free(temp_path);
	return (path);
}

static char	*get_path(char *command)
{
	char	**env_path;
	char	*path;
	int		i;

	i = 0;
	while (g_obj.envp[i] && ft_strnstr(g_obj.envp[i], "PATH", 4) == 0)
		i++;
	if (!g_obj.envp[i])
		return (NULL);
	env_path = ft_split(g_obj.envp[i] + 5, ':');
	i = 0;
	while (env_path[i])
	{
		path = join_path(env_path[i], command);
		if (access(path, F_OK) == 0)
		{
			ft_free_matrix(env_path);
			return (path);
		}
		i++;
		free(path);
	}
	ft_free_matrix(env_path);
	return (NULL);
}

static int	try_execute(char **args)
{
	int	pid;
	int	status;

	pid = fork();
	signal(SIGINT, new_line);
	signal(SIGQUIT, quit_exec);
	if (pid == 0)
	{
		if (ft_chrpos(args[0], '/') != -1)
			execve(args[0], args, g_obj.envp);
		else
			execve(get_path(args[0]), args, g_obj.envp);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_obj.exit_code = WEXITSTATUS(status);
	if (g_obj.exit_code == -1)
		return (FALSE);
	return (TRUE);
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
		if (!try_execute(args))
		{
			ft_putstr_fd("Error -> Command not found: ", STDERR_FILENO);
			ft_putendl_fd(args[0], STDERR_FILENO);
		}
	}
	else
	{
		change_fd(g_obj.initial_fd);
		ft_putstr_fd("Command not found: ", STDERR_FILENO);
		ft_putendl_fd(args[0], STDERR_FILENO);
		g_obj.exit_code = 127;
	}
	ft_free_matrix(args);
}
