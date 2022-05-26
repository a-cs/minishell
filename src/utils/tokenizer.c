/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:45 by acarneir          #+#    #+#             */
/*   Updated: 2022/05/25 22:15:18 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	split_token(t_data *obj, char **args)
{
    int i;
    int init;
    int	pos;

    i = 0;
    pos = 0;
    while (pos < ft_strlen(obj->input) && i < obj->args_num) {
        if (pos == 0)
        {
            while (obj->input[pos] && obj->input[pos] != SPACE_VALUE)
                pos++;
            args[i] = malloc((pos + 1) * sizeof(char));
            ft_memcpy(args[i], ft_strjoin(ft_substr(obj->input, 0, pos), ""), pos + 1);
        }
        else if (obj->input[pos] == SINGLE_QUOTES)
        {
            init = pos;
            pos++;
            while (obj->input[pos] && obj->input[pos] != SINGLE_QUOTES)
                pos++;
            args[i] = malloc((pos - init + 2) * sizeof(char));
            ft_memcpy(args[i], ft_strjoin(ft_substr(obj->input, init, pos - init + 1), ""), pos - init + 2);
        }
        else if (obj->input[pos] == DOUBLE_QUOTES)
        {
            init = pos;
            pos++;
            while (obj->input[pos] && obj->input[pos] != DOUBLE_QUOTES)
                pos++;
            args[i] = malloc((pos - init + 2) * sizeof(char));
            ft_memcpy(args[i], ft_strjoin(ft_substr(obj->input, init, pos - init + 1), ""), pos - init + 2);
        }
        else
        {
            init = pos;
            while (obj->input[pos] && (obj->input[pos] != SPACE_VALUE
                                       && obj->input[pos] != SINGLE_QUOTES
                                       && obj->input[pos] != DOUBLE_QUOTES))
                pos++;
            if (obj->input[pos] == SPACE_VALUE)
            {
                args[i] = malloc((pos - init + 1) * sizeof(char));
                ft_memcpy(args[i], ft_strjoin(ft_substr(obj->input, init, pos - init + 1), ""), pos - init + 1);
            }
            else
            {
                args[i] = malloc((pos - init) * sizeof(char));
                ft_memcpy(args[i], ft_strjoin(ft_substr(obj->input, init, pos - init), ""), pos - init);
                pos--;
            }
        }
        pos++;
        i++;
    }
    args[i] = NULL;
}

static void	count_tokens(t_data *obj)
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
			while (obj->input[pos] && (obj->input[pos] != SPACE_VALUE
					&& obj->input[pos] != SINGLE_QUOTES
					&& obj->input[pos] != DOUBLE_QUOTES))
				pos++;
        pos++;
		obj->args_num++;
	}
}

static void check_unclosed_quotes(t_data *obj)
{
    int	pos;

    pos = 0;
    while (pos < ft_strlen(obj->input))
    {
        if (obj->input[pos] == SINGLE_QUOTES)
        {
            pos++;
            while (obj->input[pos] && obj->input[pos] != SINGLE_QUOTES)
                pos++;
            if (obj->input[pos] != SINGLE_QUOTES)
            {
                obj->error = 1;
                printf("Error: unclosed quotes\n");
                break ;
            }
        }
        else if (obj->input[pos] == DOUBLE_QUOTES)
        {
            pos++;
            while (obj->input[pos] && obj->input[pos] != DOUBLE_QUOTES)
                pos++;
            if (obj->input[pos] != DOUBLE_QUOTES)
            {
                obj->error = 1;
                printf("Error: unclosed quotes\n");
                break ;
            }
        }
        pos++;
    }
}

char	**tokenizer(t_data *obj) {
    char **args;

    check_unclosed_quotes(obj);
    if (obj->error == 0)
    {
        count_tokens(obj);
        args = malloc((obj->args_num + 1) * sizeof(char *));
        split_token(obj, args);
        return (args);
    }
    else
        return (NULL);
}
