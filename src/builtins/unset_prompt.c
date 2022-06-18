/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:05:24 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/18 02:31:29 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**copy_and_clear_env(t_data *obj, char *var, int i)
{
	char	**aux;
	int		j;
	int		len;

	aux = ft_calloc(i + 1, sizeof(char *));
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
	return (aux);
}

static void	clear_var(t_data *obj, char *var)
{
	int		i;
	char	**aux;

	i = 0;
	while (obj->envp[i])
		i++;
	aux = copy_and_clear_env(obj, var, i);
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
	int		i;
	char	*temp;

	i = 1;
	while (args[i])
	{
		temp = ft_strtrim(args[i], " \t");
		if (is_valid_unset(temp))
			clear_var(obj, temp);
		i++;
		free(temp);
	}
	return (1);
}
