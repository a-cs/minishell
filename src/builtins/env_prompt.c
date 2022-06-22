/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:48:26 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/21 22:25:28 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_prompt(void)
{
	int	i;

	i = 0;
	while (g_obj.envp[i])
	{
		printf("%s\n", g_obj.envp[i]);
		i++;
	}
	g_obj.exit_code = 0;
}
