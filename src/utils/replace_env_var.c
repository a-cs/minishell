/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:12 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/28 23:44:26 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_value(t_data *obj, char *var)
{
	int	i;

	i = 0;
	while (obj->envp[i] && ft_memcmp(obj->envp[i], var, ft_strlen(var)) != 0)
		i++;
	if (!obj->envp[i])
		return (ft_strjoin("", ""));
	else
		return (ft_substr(obj->envp[i], ft_chrpos(obj->envp[i], '=') + 1,
				ft_strlen(obj->envp[i] + ft_chrpos(obj->envp[i], '=') + 1)));
}

static char	*replace_var(t_data *obj, char *temp, int start)
{
	int		end;
	char	*var;
	char	*value;
	char	*aux;

	end = start + 1;
	while (ft_isdigit(temp[end]) || ft_isalpha(temp[end]))
		end++;
	var = ft_substr(temp, start + 1, end - start - 1);
	value = get_value(obj, var);
	aux = ft_strjoin(ft_strjoin(ft_substr(temp, 0, start), value),
			ft_substr(temp, end, ft_strlen(temp + end)));
	free(var);
	free(value);
	return (aux);
}

char	**replace_env_var(t_data *obj, char **temp)
{
	int		i;
	int		pos;
	char	**args;

	i = 0;
	args = malloc((obj->args_num + 1) * sizeof(char));
	while (temp[i])
	{
		pos = 0;
		while (temp[i][pos])
		{
			if (temp[i][pos] == DOLLAR_SIGN)
			{
				temp[i] = replace_var(obj, temp[i], pos);
				pos = -1;
			}
			pos++;
		}
		args[i] = ft_calloc(ft_strlen(temp[i]) + 1, sizeof(char));
		ft_memcpy(args[i], temp[i], ft_strlen(temp[i]));
		i++;
	}
	args[i] = NULL;
	free(temp);
	return (args);
}
