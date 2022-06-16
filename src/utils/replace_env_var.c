/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:27:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/16 00:35:20 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	save_var(t_data *obj, char *str, t_list **char_list)
{
	int		i;
	int		len;
	char	*var;

	i = 0;
	while (str[i] || (ft_isalpha(str[i]) || ft_isdigit(str[i])))
		i++;
	var = ft_substr(str, 0, i);
	len = ft_strlen(var);
	i = 0;
	while (obj->envp[i])
	{
		if (ft_memcmp(var, obj->envp[i], len) == 0 && obj->envp[i][len] == '=')
		{
			ft_lstadd_back(char_list, ft_lstnew(ft_substr(obj->envp[i],
						len + 1, ft_strlen(obj->envp[i]) - len - 1)));
			break ;
		}
		i++;
	}
	if (obj->envp[i] == NULL)
		ft_lstadd_back(char_list, ft_lstnew(""));
	free(var);
}

static int	iterate_and_replace(t_data *obj, char *str, t_list **char_list)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str) && str[i])
	{
		i = ft_chrpos(str, DOLLAR_SIGN);
		if (i == -1)
		{
			ft_lstadd_back(char_list, ft_lstnew(ft_strdup(str)));
			return (ft_strlen(str));
		}
		else if (i == 0)
		{
			save_var(obj, str + 1, char_list);
			i++;
			while (str[i] || (ft_isalpha(str[i]) || ft_isdigit(str[i])))
				i++;
		}
		else
			ft_lstadd_back(char_list, ft_lstnew(ft_substr(str, 0, i)));
		i += iterate_and_replace(obj, str + i, char_list);
	}
	return (i);
}

char	**replace_env_var(t_data *obj, char **temp)
{
	int		i;
	char	**args;
	t_list	*char_list;

	args = ft_calloc(obj->args_num + 1, sizeof(char *));
	i = 0;
	while (i < obj->args_num)
	{
		char_list = NULL;
		if (((temp[i][0] == SINGLE_QUOTES || (temp[i][0] == SPACE_VALUE
				&& temp[i][1] == SINGLE_QUOTES)) && temp[i][ft_strlen(temp[i])
				- 1] == SINGLE_QUOTES) || ft_chrpos(temp[i], DOLLAR_SIGN) == -1)
			ft_lstadd_back(&char_list, ft_lstnew(ft_strdup(temp[i])));
		else
			iterate_and_replace(obj, temp[i], &char_list);
		args[i] = join_list(char_list);
		ft_lstclear(&char_list, free);
		i++;
	}
	args[i] = NULL;
	ft_free_matrix(temp);
	return (args);
}
