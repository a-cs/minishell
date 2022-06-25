/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:35:04 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/25 16:20:26 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_valid_history(char *str)
{
	if (str && *str)
	{
		if (str[0] == '\t' || str[0] == '\v' || str[0] == '\r' || str[0] == ' ')
			return (0);
		return (1);
	}
	return (0);
}
