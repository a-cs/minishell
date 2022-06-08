/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:45 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/07 22:41:25 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_args(t_data *obj)
{
	int	i;

	i = 0;
	while (obj->input[i])
	{
		if (obj->input[i] == DOUBLE_QUOTES)
			while (obj->input[i] && obj->input[i] != DOUBLE_QUOTES)
				i++;
		else if (obj->input[i] == SINGLE_QUOTES)
			while (obj->input[i] && obj->input[i] != SINGLE_QUOTES)
				i++;
		else if (obj->input[i] == SPACE_VALUE)
			while (obj->input[i] && obj->input[i] == SPACE_VALUE)
				i++;
		else if (ft_isalpha(obj->input[i]))
		{
			obj->args_num++;
			while (obj->input[i] && obj->input[i] != SPACE_VALUE)
				i++;
		}
		else
			i++;
		// printf("i = %d\n", i);
	}
}

char	**tokenizer(t_data *obj)
{
	char	**args;

	count_args(obj);
	// printf("args_num: %d\n", obj->args_num);
	// args = ft_calloc(obj->args_num + 1, sizeof(char *));
	// split_args(obj, args);
	args = ft_split(obj->input, ' ');
	// while (args[obj->args_num])
	// 	obj->args_num++;
	return (args);
}


