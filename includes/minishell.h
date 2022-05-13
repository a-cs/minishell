/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:40:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/12 23:17:25 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDES
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

// DEFINE
# define HASHTABLE_SIZE 2

// STRUCTS
typedef struct s_data
{
	char	**envp;
	char	*prompt;
	char	*input;
}	t_data;

// FUNCTIONS
void	exit_prompt(t_data *obj);
int		pwd_prompt(void);

#endif
