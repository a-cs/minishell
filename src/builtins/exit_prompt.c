/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:39:43 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/12 22:25:25 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_prompt(t_data *obj)
{
	if (obj->input)
		free(obj->input);
    if (obj->envp)
        ft_free_matrix(obj->envp);
	if (obj)
		free(obj);
	exit(0);
}
