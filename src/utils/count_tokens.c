/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:39:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/26 02:16:13 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	count_tokens_without_quotes(t_data *obj, int pos)
{
	while (obj->input[pos] && (obj->input[pos] != SPACE_VALUE
			&& obj->input[pos] != SINGLE_QUOTES
			&& obj->input[pos] != DOUBLE_QUOTES))
		pos++;
	return (pos);
}

void	count_tokens(t_data *obj)
{
	int	pos;

	pos = 0;
	while (pos < ft_strlen(obj->input))
	{
		if (pos == 0)
			while (obj->input[pos] && obj->input[pos] != SPACE_VALUE)
				pos++;
		else if (obj->input[pos] == SINGLE_QUOTES)
		{
			pos++;
			while (obj->input[pos] && obj->input[pos] != SINGLE_QUOTES)
				pos++;
		}
		else if (obj->input[pos] == DOUBLE_QUOTES)
		{
			pos++;
			while (obj->input[pos] && obj->input[pos] != DOUBLE_QUOTES)
				pos++;
		}
		else
			pos = count_tokens_without_quotes(obj, pos);
		pos++;
		obj->args_num++;
	}
}
