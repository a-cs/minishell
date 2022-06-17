/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:05:24 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/17 18:42:01 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	clear_var(t_data *obj, char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var);
	while (obj->envp[i])
	{
		if (ft_memcmp(var, obj->envp[i], len) == 0 && obj->envp[i][len] == '=')
			ft_bzero(obj->envp[i], ft_strlen(obj->envp[i]));
		i++;
	}
}

static int	is_valid_unset(char *var)
{
	int	i;
	int	error;

	i = 0;
	error = 1;
	if (ft_chrpos(var, '=') != -1)
		error = 0;
	while (var[i] && error == 1)
	{
		if (!(ft_isalpha(var[i]) || ft_isdigit(var[i]))
			|| ft_is_all_digit(var, ft_strlen(var)))
			error = 0;
		i++;
	}
	if (error == 0)
		printf("unset: '%s': not a valid identifier\n", var);
	return (error);
}

int	unset_prompt(t_data *obj, char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (is_valid_unset(args[i]))
			clear_var(obj, args[i]);
		i++;
	}
	return (1);
}
