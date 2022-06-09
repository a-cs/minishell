/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:45 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/09 01:55:44 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	increment_count(t_data *obj, int i, int c)
{
	i++;
	while (i < ft_strlen(obj->input) && obj->input[i] && obj->input[i] != c)
		i++;
	return (i);
}

static void	count_args(t_data *obj)
{
	int	i;

	i = 0;
	while (i < ft_strlen(obj->input) && obj->input[i])
	{
		if (obj->input[i] == DOUBLE_QUOTES)
			i = increment_count(obj, i, DOUBLE_QUOTES) + 1;
		else if (obj->input[i] == SINGLE_QUOTES)
			i = increment_count(obj, i, SINGLE_QUOTES) + 1;
		else if (obj->input[i] == SPACE_VALUE)
		{
			i++;
			obj->args_num++;
			while (obj->input[i] && obj->input[i] == SPACE_VALUE)
				i++;
		}
		else if (obj->input[i] != DOUBLE_QUOTES
			&& obj->input[i] != SINGLE_QUOTES && obj->input[i] != SPACE_VALUE)
			i = increment_count(obj, i, SPACE_VALUE);
		if (i > ft_strlen(obj->input) || obj->input[i] == '\0')
			obj->args_num++;
	}
}

char	**tokenizer(t_data *obj)
{
	char	**args;

	count_args(obj);
	args = ft_calloc(obj->args_num + 1, sizeof(char *));
	split_args(obj, args);
	return (args);
}
