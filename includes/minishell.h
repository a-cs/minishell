/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:40:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/24 03:07:05 by rfelipe-         ###   ########.fr       */
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
# define SPACE 32
# define DOUBLE_QUOTES 34
# define SINGLE_QUOTES 39

// STRUCTS
typedef struct s_data
{
	char	**envp;
	char	*prompt;
	char	*input;
	int		error;
}	t_data;

// FUNCTIONS
void	exit_prompt(t_data *obj);
int		pwd_prompt(void);
void	check_input(t_data *obj);
char	**tokenizer(t_data *obj);
int		echo_prompt(char **args);
void	new_prompt(int signal);
void	new_line(int signal);

#endif
