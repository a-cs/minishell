/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:15:58 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/28 23:19:25 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**trim_args(t_data *obj, char **temp)
{
	int		i;
	int		len;
	char	**args;

	i = 0;
	args = malloc((obj->args_num + 1) * sizeof(char *));
	while (i < obj->args_num)
	{
		len = ft_strlen(temp[i]);
		if (temp[i][0] == SINGLE_QUOTES && temp[i][len - 1] == SINGLE_QUOTES)
			args[i] = ft_strtrim(temp[i], "\'");
		else if (temp[i][0] == DOUBLE_QUOTES
			&& temp[i][len - 1] == DOUBLE_QUOTES)
			args[i] = ft_strtrim(temp[i], "\"");
		else
		{
			args[i] = ft_calloc(len + 1, sizeof(char));
			ft_memcpy(args[i], temp[i], len);
		}
		i++;
	}
	args[i] = NULL;
	free(temp);
	return (args);
}
