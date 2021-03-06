/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:18:18 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/24 00:48:08 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	start_msg(void)
{
	char	**cmd;

	cmd = ft_split("clear", ' ');
	execute_cmd(cmd);
	cmd = ft_calloc(3, sizeof(char *));
	cmd[0] = ft_strdup("cat");
	cmd[1] = ft_strdup("./assets/mi-shell.txt");
	execute_cmd(cmd);
}
