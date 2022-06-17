/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:48:26 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/17 19:18:33 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_prompt(t_data *obj)
{
	int	i;

	i = 0;
	while (obj->envp[i])
	{
		printf("%s\n", obj->envp[i]);
		i++;
	}
	obj->exit_code = 0;
	return (1);
}
