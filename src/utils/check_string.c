/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:05:35 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/16 22:42:54 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_quotes(t_data *obj)
{
	if ((ft_chrqty(obj->input, DOUBLE_QUOTES) % 2 != 0)
		|| (ft_chrqty(obj->input, SINGLE_QUOTES) % 2 != 0))
	{
		printf("Error: unclosed quotes\n");
		return (0);
	}
	return (1);
}

int	check_string(t_data *obj)
{
	return (check_quotes(obj));
}
