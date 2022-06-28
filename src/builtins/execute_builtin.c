/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:19:21 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/27 22:44:19 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_builtin(char **args, int code)
{
	if (code == 1)
	{
		ft_free_matrix(args);
		exit_prompt();
	}
	if (code == 2)
		pwd_prompt();
	if (code == 3)
		echo_prompt(args);
	if (code == 4)
		env_prompt();
	if (code == 5)
		export_prompt(args);
	if (code == 6)
		unset_prompt(args);
	if (code == 7)
		cd_prompt(args);
}
