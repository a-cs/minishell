/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:45 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/07 01:19:27 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**tokenizer(t_data *obj)
{
	char	**args;

	args = ft_split(obj->input, ' ');
	while (args[obj->args_num])
		obj->args_num++;
	return (args);
}

// while (input[i])
// {
// 	if (input[i] == DOUBLE_QUOTES)
// 	{
// 		while (input[i+j])
// 		{
// 			if (input[i+j] == DOUBLE_QUOTES)
// 			return (i, j);
// 			j++;
// 		}
// 	}
// 	i++;
// }
