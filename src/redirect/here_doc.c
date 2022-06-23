/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:44:44 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/23 18:51:47 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	get_input(int temp_file, char *eof)
{
	char	*input;

	signal(SIGINT, new_line);
	while (1)
	{
		input = readline("> ");
		if (input[0] == '\0')
		{
			free(input);
			ft_putendl_fd("", temp_file);
			continue ;
		}
		if (ft_memcmp(input, eof, ft_strlen(input)))
			ft_putendl_fd(input, temp_file);
		else
		{
			close(temp_file);
			free(input);
			break ;
		}
		free(input);
	}
	g_obj.exit_code = 0;
}

void	here_doc(char *eof)
{
	int	temp_file;

	temp_file = open("temp_file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (temp_file == -1)
	{
		g_obj.error = 1;
		g_obj.exit_code = 9;
		return ;
	}
	get_input(temp_file, eof);
	change_input("temp_file", O_RDONLY);
	unlink("temp_file");
}
