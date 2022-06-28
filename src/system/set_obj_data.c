/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:47:43 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/28 01:52:38 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*prompt_str(void)
{
	char	*str;
	char	*buffer;
	char	*pwd;
	char	*aux;
	char	*temp;

	buffer = NULL;
	pwd = getcwd(buffer, 0);
	temp = ft_strjoin("\e[1;36mMi-Shell\e[0m>\e[1;34m", pwd);
	aux = ft_strjoin(temp, "\e[0m");
	str = ft_strjoin(aux, "\e[1;32m$\e[0m ");
	free(pwd);
	free(temp);
	free(aux);
	return (str);
}

void	reset_obj_data(void)
{
	g_obj.error = 0;
	g_obj.args_num = 0;
	g_obj.close_code = 0;
	g_obj.invalid_input = 0;
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
