/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:35:04 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/29 17:22:08 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_valid_history(char *str)
{
	if (str && *str)
	{
		if (str[0] == '\t' || str[0] == '\v' || str[0] == '\r' || str[0] == ' ')
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}
