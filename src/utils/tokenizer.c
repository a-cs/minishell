/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:45 by acarneir          #+#    #+#             */
/*   Updated: 2022/05/24 02:11:44 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_phrase(t_data *obj, int pos, char *args, int c)
{
	int		j;
	char	*temp;
	char	*temp_2;

	j = ft_chrpos(obj->input + pos + 1, c);
	if (j == -1 && c == SPACE)
		j = ft_strlen(obj->input + pos + 1);
	if (j == -1)
	{
		printf("Error: unclosed quotes\n");
		obj->error = 1;
		return (ft_strlen(obj->input));
	}
	temp = ft_strtrim(ft_strjoin(
				ft_substr(obj->input + pos, 0, j + 1), ""), " \t");
	temp_2 = malloc(ft_strlen(temp) * sizeof(char));
	if (c == DOUBLE_QUOTES)
		ft_memcpy(temp_2, ft_strtrim(temp, "\""), ft_strlen(temp) - 1);
	else if (c == SINGLE_QUOTES)
		ft_memcpy(temp_2, ft_strtrim(temp, "\'"), ft_strlen(temp) - 1);
	if (c == DOUBLE_QUOTES || c == SINGLE_QUOTES)
		ft_memcpy(args, temp_2, ft_strlen(temp_2) + 1);
	else
		ft_memcpy(args, temp, ft_strlen(temp) + 1);
	free(temp);
	free(temp_2);
	return (j);
}

static void	split_token(char **args, t_data *obj)
{
	int		i;
	int		pos;
	char	*temp;

	i = 0;
	pos = 0;
	while (pos < ft_strlen(obj->input))
	{
		temp = malloc((ft_strlen(obj->input) + 1) * sizeof(char));
		if ((obj->input + pos)[0] == SINGLE_QUOTES)
			pos += get_phrase(obj, pos, temp, SINGLE_QUOTES);
		else if ((obj->input + pos)[0] == DOUBLE_QUOTES)
			pos += get_phrase(obj, pos, temp, DOUBLE_QUOTES);
		else
			pos += get_phrase(obj, pos, temp, SPACE);
		args[i] = malloc((ft_strlen(temp) + 1) * sizeof(char));
		ft_memcpy(args[i], temp, ft_strlen(temp) + 1);
		i++;
		pos++;
		free(temp);
	}
	args[i] = NULL;
}

static int	count_tokens(t_data *obj)
{
	int		i;
	int		pos;
	char	*temp;

	i = 0;
	pos = 0;
	while (pos < ft_strlen(obj->input))
	{
		temp = ft_calloc(ft_strlen(obj->input) + 1, sizeof(char));
		if ((obj->input + pos)[0] == SINGLE_QUOTES)
			pos += get_phrase(obj, pos, temp, SINGLE_QUOTES);
		else if ((obj->input + pos)[0] == DOUBLE_QUOTES)
			pos += get_phrase(obj, pos, temp, DOUBLE_QUOTES);
		else
			pos += get_phrase(obj, pos, temp, SPACE);
		i++;
		pos++;
		free(temp);
	}
	return (i);
}

char	**tokenizer(t_data *obj)
{
	char	**args;

	if (!check_string(obj))
		return (NULL);
	args = malloc((count_tokens(obj) + 1) * sizeof(char *));
	split_token(args, obj);
	return (args);
}
