/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:15:19 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/23 00:55:51 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	define_var(char *var)
{
	int		i;
	int		len;
	char	**aux;

	len = 0;
	while (g_obj.envp[len])
		len++;
	aux = ft_calloc(len + 2, sizeof(char *));
	i = 0;
	while (i < len)
	{
		aux[i] = ft_strdup(g_obj.envp[i]);
		i++;
	}
	aux[i] = ft_strdup(var);
	ft_free_matrix(g_obj.envp);
	g_obj.envp = ft_calloc(len + 2, sizeof(char *));
	i = 0;
	while (i < (len + 1))
	{
		g_obj.envp[i] = ft_strdup(aux[i]);
		i++;
	}
	ft_free_matrix(aux);
	g_obj.exit_code = 0;
}

static void	update_var(char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_chrpos(var, '=');
	while (g_obj.envp[i])
	{
		if (ft_memcmp(var, g_obj.envp[i], len) == 0
			&& g_obj.envp[i][len] == '=')
		{
			free(g_obj.envp[i]);
			g_obj.envp[i] = ft_strdup(var);
			break ;
		}
		i++;
	}
	g_obj.exit_code = 0;
}

static int	already_has_env_var(char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_chrpos(var, '=');
	while (g_obj.envp[i])
	{
		if (ft_memcmp(var, g_obj.envp[i], len) == 0
			&& g_obj.envp[i][len] == '=')
			return (1);
		i++;
	}
	return (0);
}

static int	is_valid_attribution(char *arg, char *next)
{
	int	i;
	int	j;

	i = 0;
	j = ft_chrpos(arg, '=');
	if (j == -1)
		return (0);
	while (i <= j)
	{
		if (j == 0 || !(ft_isalpha(arg[i]) || ft_isdigit(arg[i]))
			|| ft_is_all_digit(arg, j))
		{
			printf("export '%s': not a valid identifier\n", arg);
			g_obj.exit_code = 1;
			return (0);
		}
		i++;
	}
	if (!arg[j + 1] && next)
	{
		printf("export '%s': not a valid identifier\n", next);
		g_obj.exit_code = 1;
		return (-1);
	}
	return (1);
}

void	export_prompt(char **args)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (args[i])
	{
		temp = ft_strtrim(args[i], " \t");
		j = is_valid_attribution(temp, args[i + 1]);
		if (j == 1 || j == -1)
		{
			if (already_has_env_var(temp))
				update_var(temp);
			else
				define_var(temp);
			if (j == -1)
				i++;
		}
		free(temp);
		i++;
	}
}
