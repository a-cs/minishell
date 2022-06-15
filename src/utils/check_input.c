/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:27:40 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/14 23:26:53 by rfelipe-         ###   ########.fr       */
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

static int	check_envp(t_data *obj, char **args)
{
	int	fd[2];
	int	pid;
	int	response;

	response = 0;
	pipe(fd);
	pid = fork();
	signal(SIGINT, new_line);
	if (pid == 0)
	{
		if (ft_chrpos(args[0], '/') != -1)
			response = execve(args[0], args, obj->envp);
		else
			response = execve(get_path(args[0], obj->envp), args, obj->envp);
	}
	waitpid(pid, NULL, 0);
	close(fd[0]);
	close(fd[1]);
	if (response == -1)
		return (0);
	return (1);
}

static int	check_builtin(t_data *obj, char **args)
{
	if (obj->error == 0)
	{
		if (ft_memcmp(args[0], "exit", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "exit", 4) == 0)
		{
			ft_free_matrix(args);
			exit_prompt(obj);
		}
		if (ft_memcmp(args[0], "pwd", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "pwd", 3) == 0)
			return (pwd_prompt());
		if (ft_memcmp(args[0], "echo", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "echo", 4) == 0)
			return (echo_prompt(args, obj));
	}
	return (0);
}

static char	*try_path(t_data *obj, char	**args)
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
		path = get_path(args[0], obj->envp);
	return (path);
}

void	check_input(t_data *obj)
{
	char	**args;
	char	*path;

	if (!obj->input || ft_strlen(obj->input) == 0)
		return ;
	args = clean_quotes(obj, replace_env_var(obj, tokenizer(obj)));
	if (obj->error == 0 && args && !check_builtin(obj, args))
	{
		path = try_path(obj, args);
		if (path)
		{
			free(path);
			if (!check_envp(obj, args))
				printf("Error -> Command not found: %s\n", args[0]);
		}
		else
			printf("Command not found: %s\n", args[0]);
	}
	ft_free_matrix(args);
}
