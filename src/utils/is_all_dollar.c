/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:03:31 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/29 19:17:19 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_all_dollar(char *str)
{
	int	i;

	if (!str)
		return (FALSE);
	i = 0;
	while (str[i])
	{
		if (!(str[i] == DOLLAR_SIGN))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
