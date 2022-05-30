/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:12 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/29 23:10:25 by rfelipe-         ###   ########.fr       */
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

static char	*replace_var(t_data *obj, char *temp)
{
	int		start;
	int		end;
	char	*var;
	char	*value;
	char	*aux;

	start = ft_chrpos(temp, DOLLAR_SIGN);
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

static char	*replace_multi_var(t_data *obj, char *temp)
{
	char	*aux;
	char	*arg;

	while (ft_chrpos(temp, DOLLAR_SIGN) != -1)
	{
		aux = replace_var(obj, temp);
		free(temp);
		temp = aux;
	}
	arg = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	ft_memcpy(arg, temp, ft_strlen(temp));
	free(aux);
	return (arg);
}

char	**replace_env_var(t_data *obj, char **temp)
{
	int		i;
	char	**args;

	i = 0;
	args = malloc((obj->args_num + 1) * sizeof(char));
	while (temp[i])
	{
		if (ft_chrqty(temp[i], DOLLAR_SIGN) > 1)
			args[i] = replace_multi_var(obj, temp[i]);
		else if (ft_chrqty(temp[i], DOLLAR_SIGN) == 1)
			args[i] = replace_var(obj, temp[i]);
		else
		{
			args[i] = ft_calloc(ft_strlen(temp[i]) + 1, sizeof(char));
			ft_memcpy(args[i], temp[i], ft_strlen(temp[i]));
		}
		i++;
	}
	args[i] = NULL;
	free(temp);
	return (args);
}
