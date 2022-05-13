/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:27:40 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/13 00:04:34 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_path(char *command, char **envp)
{
	char	**env_path;
	char	*temp_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	env_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (env_path[i])
	{
		temp_path = ft_strjoin(env_path[i], "/");
		path = ft_strjoin(temp_path, command);
		free(temp_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

static int	check_envp(t_data *obj)
{
	int	fd[2];
	int	pid;
	int	response;

	response = 0;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		response = execve(get_path(obj->input, obj->envp),
				&obj->input, obj->envp);
	}
	waitpid(pid, NULL, 0);
	if (pid > 0)
		kill(pid, SIGKILL);
	close(fd[0]);
	close(fd[1]);
	if (response == -1)
		return (0);
	return (1);
}

static int	check_builtin(t_data *obj)
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
		if (!check_envp(obj))
			printf("Command not found: %s\n", obj->input);
	}
}
