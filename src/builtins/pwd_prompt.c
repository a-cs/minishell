/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:25:21 by acarneir          #+#    #+#             */
/*   Updated: 2022/05/12 21:34:58 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_prompt(void)
{
	char	*buffer;
	char	*pwd;

	buffer = NULL;
	pwd = getcwd(buffer, 0);
	printf("%s\n", pwd);
	free(pwd);
}
