/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:10:11 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/09 00:43:56 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*iterate_and_clean(t_data *obj, char *temp, t_list *char_list)
{
	int		i;
	int		j;

	i = 0;
	if (obj->error != 0)
		return (NULL);
	while (temp[i] != '\0' && obj->error == 0)
	{
		printf("temp = |%s|\n", temp);
		if (temp[0] == DOUBLE_QUOTES)
		{
			j = ft_chrpos(temp + 1, DOUBLE_QUOTES);
			if (j == -1)
			{
				obj->error++;
				printf("Unclosed quotes\n");
			}
			else
			{
				// printf("j = %d\n", j);
				ft_lstadd_back(&char_list, ft_lstnew(ft_substr(temp, 1, j)));
				i += j + 2;
			}
		}
		else if (temp[0] == SINGLE_QUOTES)
		{
			j = ft_chrpos(temp + 1, SINGLE_QUOTES);obj->error != 0
			if (j == -1)
			{
				obj->error++;
				printf("Unclosed quotes\n");
			}
			else
			{
				ft_lstadd_back(&char_list, ft_lstnew(ft_substr(temp, 1, j)));
				i += j + 2;
			}
		}
		else
		{
			j = i;
			while (temp[j] != DOUBLE_QUOTES && temp[j] != SINGLE_QUOTES
				&& temp[j] != '\0')
				j++;
			ft_lstadd_back(&char_list, ft_lstnew(ft_substr(temp, 0, j)));
			i += j;
		}
		printf("list = |%s|\n", (char *)char_list->content);
		iterate_and_clean(obj, temp + i, char_list);
	}
	return (ft_strjoin(temp,""));
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
		args[i] = iterate_and_clean(obj, temp[i], char_list);
		ft_lstclear(&char_list, free);
		i++;
	}
	args[i] = NULL;
	ft_free_matrix(temp);
	return (args);
}
