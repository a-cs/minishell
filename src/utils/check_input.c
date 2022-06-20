/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:27:40 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/20 15:50:02 by rfelipe-         ###   ########.fr       */
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
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	signal(SIGINT, new_line);
	if (pid == 0)
	{
		if (ft_chrpos(args[0], '/') != -1)
			g_obj.exit_code = execve(args[0], args, g_obj.envp);
		else
			g_obj.exit_code = execve(get_path(args[0]), args, g_obj.envp);
	}
	waitpid(pid, NULL, 0);
	close(fd[0]);
	close(fd[1]);
	if (g_obj.exit_code == -1)
		return (0);
	return (1);
}

static int	check_builtin(char **args)
{
	if (g_obj.error == 0 && args[0])
	{
		if (ft_memcmp(args[0], "exit", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "exit", 4) == 0)
		{
			ft_free_matrix(args);
			exit_prompt();
		}
		if (ft_memcmp(args[0], "pwd", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "pwd", 3) == 0)
			return (pwd_prompt());
		if (ft_memcmp(args[0], "echo", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "echo", 4) == 0)
			return (echo_prompt(args));
		if (ft_memcmp(args[0], "env", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "env", 4) == 0)
			return (env_prompt());
		if (ft_memcmp(args[0], "export", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "export", 4) == 0)
			return (export_prompt(args));
		if (ft_memcmp(args[0], "unset", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "unset", 4) == 0)
			return (unset_prompt(args));
	}
	return (0);
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

void	check_input(void)
{
	char	**args;
	char	*path;

	if (!g_obj.input || ft_strlen(g_obj.input) == 0)
		return ;
	args = clean_quotes(replace_env_var(tokenizer()));
	if (g_obj.error == 0 && args[0] && !check_builtin(args))
	{
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
	ft_free_matrix(args);
}
