/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:15:21 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/23 01:21:42 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	throw_export_error(char *arg, int return_code)
{
	printf("export '%s': not a valid identifier\n", arg);
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
		return (throw_export_error(arg, 0));
	while (i < j)
	{
		if (!(ft_isalpha(arg[i]) || ft_isdigit(arg[i]))
			|| ft_is_all_digit(arg, j))
			return (throw_export_error(arg, 0));
		i++;
	}
	if (!arg[j + 1] && next)
		return (throw_export_error(next, -1));
	return (1);
}
