/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:40:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/10 01:36:14 by acarneir         ###   ########.fr       */
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
# define SPACE_VALUE 32
# define DOUBLE_QUOTES 34
# define SINGLE_QUOTES 39
# define DOLLAR_SIGN 36

// STRUCTS
typedef struct s_data
{
	char	**envp;
	char	*prompt;
	char	*input;
	int		error;
	int		args_num;
}	t_data;

// FUNCTIONS
void	exit_prompt(t_data *obj);
int		pwd_prompt(void);
void	check_input(t_data *obj);
char	**tokenizer(t_data *obj);
int		echo_prompt(char **args, t_data *obj);
void	new_prompt(int signal);
void	new_line(int signal);
int		increment_count(t_data *obj, int i, int c);
void	split_args(t_data *obj, char **args);
char	**clean_quotes(t_data *obj, char **temp);
int		has_quotes_before_space(char *str);
int		increment_quotes(t_data *obj, int i);
int		skip_spaces(t_data *obj, int i, int j);

#endif
