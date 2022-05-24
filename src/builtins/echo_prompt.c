/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:52:02 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/24 04:06:45 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	trim_quotes(char **args, char *temp, int i)
{
	if (args[i][0] == DOUBLE_QUOTES)
		ft_memcpy(temp, ft_strtrim(args[i], "\""), ft_strlen(args[i]) - 1);
	else if (args[i][0] == SINGLE_QUOTES)
		ft_memcpy(temp, ft_strtrim(args[i], "\'"), ft_strlen(args[i]) - 1);
	else
		ft_memcpy(temp, args[i], ft_strlen(args[i]) + 1);
}

int	echo_prompt(char **args)
{
	int		i;
	int		has_flag;
	char	*temp;

	has_flag = ft_memcmp(args[1], "-n", ft_strlen(args[1]));
	if (has_flag == 0)
		i = 2;
	else
		i = 1;
	while (args[i])
	{
		temp = malloc(ft_strlen(args[i]) * sizeof(char));
		trim_quotes(args, temp, i);
		if (args[i + 1])
			printf("%s ", temp);
		else
			printf("%s", temp);
		i++;
		free(temp);
	}
	if (has_flag != 0)
		printf("\n");
	return (1);
}
