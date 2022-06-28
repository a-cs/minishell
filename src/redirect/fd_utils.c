/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:07:15 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/27 22:06:12 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_a_valid_file(char *file, int flags)
{
	if (access(file, F_OK) == -1)
	{
		g_obj.error = 1;
		g_obj.exit_code = 1;
		change_fd(g_obj.initial_fd);
		printf("%s: No such file or directory\n", file);
		return (0);
	}
	if (access(file, flags) == -1)
	{
		g_obj.error = 1;
		g_obj.exit_code = 1;
		change_fd(g_obj.initial_fd);
		printf("%s: Permission denied\n", file);
		return (0);
	}
	return (1);
}

void	change_input(char *file, int flags)
{
	int	file_id;

	if (!file[0])
	{
		g_obj.error = 1;
		g_obj.exit_code = 2;
		printf("Redirect: sintax error\n");
		return ;
	}
	file_id = open(file, flags);
	if (!is_a_valid_file(file, R_OK))
		return ;
	dup2(file_id, STDIN_FILENO);
	close(file_id);
}

void	change_output(char *file, int flags)
{
	int	file_id;

	if (!file[0])
	{
		g_obj.error = 1;
		g_obj.exit_code = 2;
		printf("Redirect: sintax error\n");
		return ;
	}
	file_id = open(file, flags, 0777);
	if (file_id == -1)
	{
		g_obj.error = 1;
		g_obj.exit_code = 9;
		printf("%s: Bad file descriptor\n", file);
	}
	else
	{
		dup2(file_id, STDOUT_FILENO);
		close(file_id);
	}
}

void	change_fd(int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	if (fd[0] != g_obj.initial_fd[0])
		close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (fd[1] != g_obj.initial_fd[1])
		close(fd[1]);
}

void	save_fd(int *fd)
{
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
}
