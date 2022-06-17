/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:10:11 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/17 19:34:07 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*join_list(t_list *char_list)
{
	char	*save;
	char	*temp;

	if (char_list)
	{
		save = ft_calloc(ft_strlen(char_list->content) + 1, sizeof(char));
		while (char_list)
		{
			if (!save[0])
				ft_memcpy(save, char_list->content,
					ft_strlen(char_list->content));
			else
			{
				temp = ft_strjoin(save, char_list->content);
				free(save);
				save = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
				ft_memcpy(save, temp, ft_strlen(temp));
				free(temp);
			}
			char_list = char_list->next;
		}
		return (save);
	}
	return (NULL);
}

static int	populate_list(t_data *obj, char *temp, t_list **char_list, int i)
{
	int	j;

	if (temp[0] == SINGLE_QUOTES)
	{
		j = ft_chrpos(temp + 1, SINGLE_QUOTES);
		if (j == -1)
		{
			obj->error++;
			obj->exit_code = 22;
			printf("Unclosed quotes\n");
		}
		else
			ft_lstadd_back(char_list, ft_lstnew(ft_substr(temp, 1, j)));
		i += j + 2;
	}
	else
	{
		j = i;
		while (temp[j] != DOUBLE_QUOTES && temp[j] != SINGLE_QUOTES
			&& temp[j] != '\0')
			j++;
		ft_lstadd_back(char_list, ft_lstnew(ft_substr(temp, 0, j)));
		i += j;
	}
	return (i);
}

static int	iterate_and_clean(t_data *obj, char *temp, t_list **char_list)
{
	int	i;
	int	j;

	i = 0;
	if (obj->error != 0)
		return (ft_strlen(temp));
	while (obj->error == 0 && obj->exit_code != 22 && temp[i] != '\0')
	{
		if (temp[0] == DOUBLE_QUOTES)
		{
			j = ft_chrpos(temp + 1, DOUBLE_QUOTES);
			if (j == -1)
			{
				obj->exit_code = 22;
				printf("Unclosed quotes\n");
			}
			else
				ft_lstadd_back(char_list, ft_lstnew(ft_substr(temp, 1, j)));
			i += j + 2;
		}
		else
			i = populate_list(obj, temp, char_list, i);
		i += iterate_and_clean(obj, temp + i, char_list);
	}
	return (i);
}

char	**clean_quotes(t_data *obj, char **temp)
{
	int		i;
	char	**args;
	t_list	*char_list;

	args = ft_calloc(obj->args_num + 1, sizeof(char *));
	i = 0;
	while (i < obj->args_num)
	{
		char_list = NULL;
		iterate_and_clean(obj, temp[i], &char_list);
		args[i] = join_list(char_list);
		ft_lstclear(&char_list, free);
		i++;
	}
	args[i] = NULL;
	ft_free_matrix(temp);
	return (args);
}
