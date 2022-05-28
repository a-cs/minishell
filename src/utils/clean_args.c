/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:10:44 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/28 19:07:05 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	save_args(char *aux, char *args)
{
	if (aux[0] == '\"' && aux[ft_strlen(aux) - 1] == '\"')
		ft_memcpy(args, ft_substr(aux, 1, ft_strlen(aux) - 2),
			ft_strlen(aux) - 2);
	else
		ft_memcpy(args, aux, ft_strlen(aux));
}

static int	find_end(int end, char *temp)
{
	while (ft_isalpha(temp[end]) || ft_isdigit(temp[end]))
		end++;
	return (end);
}

static void	replace_var(char *temp, char *args, char *value)
{
	int		start;
	int		end;
	char	*aux;

	start = ft_chrpos(temp, DOLLAR_SIGN);
	end = find_end(start + 1, temp);
	aux = ft_strjoin(ft_strjoin(ft_substr(temp, 0, start), value),
			ft_substr(temp, end, ft_strlen(temp) - end));
	ft_memcpy(args, aux, ft_strlen(aux));
}

static void	find_env_variable(t_data *obj, char *temp, char *args)
{
	int		i;
	int		start;
	int		end;
	char	*aux;

	start = ft_chrpos(temp, DOLLAR_SIGN);
	end = find_end(start + 1, temp);
	i = 0;
	while (obj->envp[i] && ft_memcmp(ft_substr(temp, start + 1,
				end - start), obj->envp[i], end - start - 1) != 0)
		i++;
	if (!obj->envp[i])
		aux = ft_calloc(1, sizeof(char));
	else
		aux = ft_calloc(ft_strlen(obj->envp[i]) + 1, sizeof(char));
	if (obj->envp[i])
		replace_var(temp, aux, ft_substr(obj->envp[i], ft_chrpos(obj->envp[i],
					'=') + 1, ft_strlen(obj->envp[i]) - start - 1));
	else
		replace_var(temp, aux, "");
	if (ft_chrpos(aux, DOLLAR_SIGN) != -1)
		find_env_variable(obj, aux, args);
	else
		save_args(aux, args);
	free(aux);
}

char	**clean_args(t_data *obj, char **temp)
{
	int		i;
	int		len;
	char	**args;

	i = 0;
	args = malloc((obj->args_num + 1) * sizeof(char *));
	while (i < obj->args_num)
	{
		len = ft_strlen(temp[i]);
		args[i] = ft_calloc(len + 1, sizeof(char));
		if ((temp[i][0] == '\'' && temp[i][len - 1] == '\'')
			|| ((temp[i][0] == '\"' && temp[i][len - 1] == '\"')
				&& ft_chrpos(temp[i], '$') == -1))
			ft_memcpy(args[i], ft_substr(temp[i], 1, len - 2), len - 2);
		else if (!(temp[i][0] == '\'' && temp[i][len - 1] == '\'')
			&& ft_chrpos(temp[i], '$') != -1)
			find_env_variable(obj, temp[i], args[i]);
		else
			ft_memcpy(args[i], temp[i], len);
		i++;
	}
	free(temp);
	args[i] = NULL;
	return (args);
}
