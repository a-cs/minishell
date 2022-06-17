/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:25:21 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/17 19:18:58 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd_prompt(t_data *obj)
{
	char	*buffer;
	char	*pwd;

	buffer = NULL;
	pwd = getcwd(buffer, 0);
	printf("%s\n", pwd);
	free(pwd);
	obj->exit_code = 0;
	return (1);
}
