/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:40:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/16 22:59:42 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDES
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>

// DEFINE
# define DOUBLE_QUOTES 34
# define SINGLE_QUOTES 39

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
void	check_input(t_data *obj);
char	**tokenizer(t_data *obj);
int		check_string(t_data *obj);
int		echo_prompt(char **args);

#endif
