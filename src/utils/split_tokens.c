/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:16:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/26 02:16:15 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	split_token_with_quotes(t_data *obj, char *args, int pos, int c)
{
	int	init;

	init = pos;
	pos++;
	while (obj->input[pos] && obj->input[pos] != c)
		pos++;
	ft_memcpy(args, ft_substr(obj->input, init, pos - init + 1),
		pos - init + 2);
	return (pos);
}

static int	split_token_without_quotes(t_data *obj, char *args, int pos)
{
	int	init;

	init = pos;
	while (obj->input[pos] && (obj->input[pos] != SPACE_VALUE
			&& obj->input[pos] != SINGLE_QUOTES
			&& obj->input[pos] != DOUBLE_QUOTES))
		pos++;
	if (obj->input[pos] == SPACE_VALUE)
		ft_memcpy(args, ft_substr(obj->input, init, pos - init + 1),
			pos - init + 1);
	else
	{
		ft_memcpy(args, ft_substr(obj->input, init, pos - init), pos - init);
		pos--;
	}
	return (pos);
}

static int	split_first_token(t_data *obj, char *args, int pos)
{
	while (obj->input[pos] && obj->input[pos] != SPACE_VALUE)
		pos++;
	ft_memcpy(args, ft_substr(obj->input, 0, pos), pos + 1);
	return (pos);
}

void	split_token(t_data *obj, char **args)
{
	int		i;
	int		pos;
	char	*temp;

	i = 0;
	pos = 0;
	while (pos < ft_strlen(obj->input) && i < obj->args_num)
	{
		temp = ft_calloc(ft_strlen(obj->input), sizeof(char));
		if (pos == 0)
			pos = split_first_token(obj, temp, pos);
		else if (obj->input[pos] == SINGLE_QUOTES)
			pos = split_token_with_quotes(obj, temp, pos, SINGLE_QUOTES);
		else if (obj->input[pos] == DOUBLE_QUOTES)
			pos = split_token_with_quotes(obj, temp, pos, DOUBLE_QUOTES);
		else
			pos = split_token_without_quotes(obj, temp, pos);
		args[i] = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
		ft_memcpy(args[i], temp, ft_strlen(temp));
		pos++;
		i++;
		free(temp);
	}
	args[i] = NULL;
}
