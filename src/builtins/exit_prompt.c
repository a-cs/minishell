/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:39:43 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/12 22:12:01 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_prompt(t_data *obj)
{
	if (obj->envp)
		free(obj->envp);
	if (obj->input)
		free(obj->input);
	if (obj->prompt)
		free(obj->prompt);
	exit(0);
}
