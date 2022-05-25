/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:52:02 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/25 01:59:49 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	trim_quotes(char **args, char *temp, int i, int *has_flag)
{
	char	*temp_2;

	temp_2 = ft_calloc(ft_strlen(args[i]) + 1, sizeof(char));
	if (i == 2 && (has_flag[0] != 0 && ((has_flag[1] == 0
					|| has_flag[2] == 0) && args[i][0] == SPACE)))
		ft_memcpy(temp_2, args[i] + 1, ft_strlen(args[i]));
	else
		ft_memcpy(temp_2, args[i], ft_strlen(args[i]) + 1);
	if (temp_2[0] == DOUBLE_QUOTES)
		ft_memcpy(temp, ft_strtrim(temp_2, "\""), ft_strlen(temp_2) - 1);
	else if (temp_2[0] == SINGLE_QUOTES)
		ft_memcpy(temp, ft_strtrim(temp_2, "\'"), ft_strlen(temp_2) - 1);
	else if (temp_2[0] == SPACE && temp_2[1] == DOUBLE_QUOTES)
		ft_memcpy(temp, ft_strjoin(" ", ft_strtrim(temp_2 + 1, "\"")),
			ft_strlen(temp_2) - 1);
	else if (temp_2[0] == SPACE && temp_2[1] == SINGLE_QUOTES)
		ft_memcpy(temp, ft_strjoin(" ", ft_strtrim(temp_2 + 1, "\'")),
			ft_strlen(temp_2) - 1);
	else
		ft_memcpy(temp, temp_2, ft_strlen(temp_2) + 1);
	free(temp_2);
}

static void	get_flag(t_data *obj, char **args, int *has_flag)
{
	if (obj->args_num > 1)
	{
		has_flag[0] = ft_memcmp(args[1], "-n ", ft_strlen(args[1]));
		has_flag[1] = ft_memcmp(args[1], "\"-n\"", ft_strlen(args[1]));
		has_flag[2] = ft_memcmp(args[1], "\'-n\'", ft_strlen(args[1]));
	}
	else
	{
		has_flag[0] = 1;
		has_flag[1] = 1;
		has_flag[2] = 1;
	}
}

int	echo_prompt(char **args, t_data *obj)
{
	int		i;
	int		*has_flag;
	char	*temp;

	has_flag = ft_calloc(3, sizeof(int));
	get_flag(obj, args, has_flag);
	if (has_flag[0] == 0 || ((has_flag[1] == 0 || has_flag[2] == 0)
			&& args[2][0] == SPACE))
		i = 2;
	else
		i = 1;
	while (obj->args_num > 1 && args[i])
	{
		temp = malloc(ft_strlen(args[i]) * sizeof(char));
		trim_quotes(args, temp, i, has_flag);
		printf("%s", temp);
		i++;
		free(temp);
	}
	if (obj->args_num > 1 && !(has_flag[0] == 0 || ((has_flag[1] == 0
					|| has_flag[2] == 0) && args[2][0] == SPACE)))
		printf("\n");
	free(has_flag);
	return (1);
}
