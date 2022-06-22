/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:20:18 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/22 02:58:06 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_file_name(char *input)
{
	int		pos;
	char	*file_name;
	char	*temp;

	pos = ft_chrpos(input, '>');
	if (pos != -1)
	{
		file_name = ft_strtrim(ft_substr(input, pos + 1,
					ft_strlen(input) - pos), " \t");
		temp = ft_strtrim(ft_substr(g_obj.input, 0, pos), " \t");
		free(g_obj.input);
		g_obj.input = ft_strdup(temp);
		free(temp);
	}
	else
		file_name = NULL;
	return (file_name);
}

void	redirect(char *input, int fd[])
{
	int		file;
	char	*file_name;

	file_name = get_file_name(input);
	if (g_obj.error == 0 && file_name)
	{
		file = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (file == -1)
		{
			printf("Unable to open file %s\n", file_name);
			g_obj.exit_code = 9;
			g_obj.error = 1;
		}
		else
		{
			dup2(fd[0], STDIN_FILENO);
			dup2(file, STDOUT_FILENO);
			close(fd[1]);
		}
		free(file_name);
	}
}
