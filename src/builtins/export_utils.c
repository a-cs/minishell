/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:15:21 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/29 17:00:33 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	throw_export_error(char *arg, int return_code)
{
	ft_putstr_fd("export '", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	g_obj.exit_code = 1;
	return (return_code);
}

int	is_valid_attribution(char *arg, char *next)
{
	int	i;
	int	j;

	i = 0;
	j = ft_chrpos(arg, '=');
	if (j == -1)
		return (0);
	if (j == 0)
		return (throw_export_error(arg, FALSE));
	while (i < j)
	{
		if (!(ft_isalpha(arg[i]) || ft_isdigit(arg[i]))
			|| ft_is_all_digit(arg, j))
			return (throw_export_error(arg, FALSE));
		i++;
	}
	if (!arg[j + 1] && next)
		return (throw_export_error(next, -1));
	return (TRUE);
}
