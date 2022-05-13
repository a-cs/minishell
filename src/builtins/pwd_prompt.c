/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:25:21 by acarneir          #+#    #+#             */
/*   Updated: 2022/05/12 23:17:13 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd_prompt(void)
{
	char	*buffer;
	char	*pwd;

	buffer = NULL;
	pwd = getcwd(buffer, 0);
	printf("%s\n", pwd);
	free(pwd);
	return (1);
}
