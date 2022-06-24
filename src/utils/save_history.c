/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:35:04 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/24 00:43:31 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_valid_history(char *str)
{
	if (str && *str)
	{
		if (str[0] == '\t' || str[0] == '\v' || str[0] == '\r' || str[0] == ' ')
			return (0);
		return (1);
	}
	return (0);
}

void	save_history(char *str)
{
	if (is_valid_history(str))
		add_history(str);
}
