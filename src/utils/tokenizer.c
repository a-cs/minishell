/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:45 by acarneir          #+#    #+#             */
/*   Updated: 2022/05/25 02:46:18 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_phrase(t_data *obj, int pos, char *args, int c)
{
	int		j;
	int		aux;
	char	*temp;

	if ((obj->input + pos)[0] == c || pos == 0)
		aux = 1;
	else
		aux = 0;
	j = ft_chrpos(obj->input + pos + aux, c);
	if (j == -1 && c == SPACE)
		j = ft_strlen(obj->input + pos + aux);
	if (j == -1)
	{
		printf("Error: unclosed quotes\n");
		obj->error = 1;
		return (ft_strlen(obj->input));
	}
	temp = ft_strjoin(ft_substr(obj->input, pos, j + 2 - aux), "");
	ft_memcpy(args, temp, ft_strlen(temp) + 1 - aux);
	printf("args: __%s__\n", args);
	free(temp);
	return (j + 1);
}

static int	get_closest(t_data *obj, int pos, char *temp)
{
	int	aux;

	aux = get_phrase(obj, pos, temp, SPACE);
	if (ft_chrpos(obj->input + pos + 1, SINGLE_QUOTES) != -1)
		if (pos > 0 && get_phrase(obj, pos, temp, SINGLE_QUOTES) < aux)
			aux = get_phrase(obj, pos, temp, SINGLE_QUOTES);
	if (ft_chrpos(obj->input + pos + 1, DOUBLE_QUOTES) != -1)
		if (pos > 0 && get_phrase(obj, pos, temp, DOUBLE_QUOTES) < aux)
			aux = get_phrase(obj, pos, temp, DOUBLE_QUOTES);
	if (pos > 0)
		return (aux - 1);
	return (aux);
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
			pos += get_closest(obj, pos, temp);
		args[i] = malloc((ft_strlen(temp) + 1) * sizeof(char));
		ft_memcpy(args[i], temp, ft_strlen(temp) + 1);
		i++;
		pos++;
		free(temp);
	}
	args[i] = NULL;
}

static void	count_tokens(t_data *obj)
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
			pos += get_closest(obj, pos, temp);
		i++;
		pos++;
		free(temp);
	}
	obj->args_num = i;
}

char	**tokenizer(t_data *obj)
{
	char	**args;

	count_tokens(obj);
	args = malloc((obj->args_num + 1) * sizeof(char *));
	if (obj->error == 0)
		split_token(args, obj);
	return (args);
}
