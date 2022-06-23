/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:07:15 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/23 16:14:09 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_a_valid_file(char *file, int flags)
{
	if (access(file, F_OK) == -1)
	{
		g_obj.error = 1;
		g_obj.exit_code = 1;
		reestore_initial_fd(g_obj.initial_fd);
		printf("%s: No such file or directory\n", file);
		return (0);
	}
	if (access(file, flags) == -1)
	{
		g_obj.error = 1;
		g_obj.exit_code = 1;
		reestore_initial_fd(g_obj.initial_fd);
		printf("%s: Permission denied\n", file);
		return (0);
	}
	return (1);
}

void	change_input(char *file, int flags)
{
	int	file_id;

	file_id = open(file, flags);
	if (!is_a_valid_file(file, R_OK))
		return ;
	dup2(file_id, STDIN_FILENO);
	close(file_id);
}

void	change_output(char *file, int flags)
{
	int	file_id;

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

void	reestore_initial_fd(int *initial_fd)
{
	dup2(initial_fd[0], STDIN_FILENO);
	dup2(initial_fd[1], STDOUT_FILENO);
}

void	save_initial_fd(int *initial_fd)
{
	initial_fd[0] = dup(STDIN_FILENO);
	initial_fd[1] = dup(STDOUT_FILENO);
}
