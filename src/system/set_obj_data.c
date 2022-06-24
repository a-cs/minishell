/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:47:43 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/24 12:53:47 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*prompt_str(void)
{
	char	*str;

	str = "\001\033[1;96m\002Mi-Shell\001\033[1;92m\002$\001\033[0m\002 ";
	return (str);
}

void	reset_obj_data(void)
{
	g_obj.error = 0;
	g_obj.args_num = 0;
	g_obj.close_code = 0;
	g_obj.prompt = prompt_str();
	g_obj.input = NULL;
}

char	**dup_envp(char **envp)
{
	int		i;
	int		len;
	char	**temp;

	len = 0;
	while (envp[len])
		len++;
	temp = ft_calloc(len + 1, sizeof(char *));
	i = 0;
	while (i < len)
	{
		temp[i] = ft_strdup(envp[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}
