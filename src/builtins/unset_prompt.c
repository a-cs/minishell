/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:05:24 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/18 01:04:07 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	clear_var(t_data *obj, char *var)
{
	int		i;
	int		j;
	int		len;
	char	**aux;

	i = 0;
	while (obj->envp[i])
		i++;
	aux = ft_calloc(i, sizeof(char *));
	i = 0;
	j = 0;
	len = ft_strlen(var);
	while (obj->envp[i])
	{
		if (ft_memcmp(var, obj->envp[i], len) == 0 && obj->envp[i][len] == '=')
			j--;
		else
			aux[j] = ft_strdup(obj->envp[i]);
		i++;
		j++;
	}
	aux[j] = NULL;
	ft_free_matrix(obj->envp);
	obj->envp = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (aux[i])
	{
		obj->envp[i] = ft_strdup(aux[i]);
		i++;
	}
	ft_free_matrix(aux);
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
