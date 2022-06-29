/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:17:14 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/29 17:19:53 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	throw_unclosed_quotes_error(void)
{
	g_obj.error = TRUE;
	g_obj.exit_code = 22;
	g_obj.invalid_input = TRUE;
	ft_putendl_fd("Unclosed quotes", STDERR_FILENO);
}

static void	update_save(char **save, t_list *char_list)
{
	char	*temp;

	temp = ft_strjoin(*save, char_list->content);
	free(*save);
	*save = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	ft_memcpy(*save, temp, ft_strlen(temp));
	free(temp);
}

char	*join_list(t_list *char_list)
{
	char	*save;
	int		i;

	if (char_list)
	{
		save = ft_calloc(ft_strlen(char_list->content) + 1, sizeof(char));
		i = 0;
		while (char_list)
		{
			if (i == 0)
				ft_memcpy(save, char_list->content,
					ft_strlen(char_list->content));
			else
				update_save(&save, char_list);
			char_list = char_list->next;
			i++;
		}
		return (save);
	}
	return (NULL);
}
