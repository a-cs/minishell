/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:07:15 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/22 23:31:01 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
