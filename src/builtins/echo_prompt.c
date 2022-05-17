/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:52:02 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/16 22:59:23 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo_prompt(char **args)
{
	int	i;
	int	has_flag;

	has_flag = ft_memcmp(args[1], "-n", ft_strlen(args[1]));
	if (has_flag == 0)
		i = 2;
	else
		i = 1;
	while (args[i])
	{
		if (args[i + 1])
			printf("%s ", args[i]);
		else
			printf("%s", args[i]);
		i++;
	}
	if (has_flag != 0)
		printf("\n");
	return (1);
}
