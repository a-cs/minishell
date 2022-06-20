/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:40:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/20 15:44:29 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDES
# include "../libft/includes/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// DEFINES
# define SPACE_VALUE	32
# define DOUBLE_QUOTES	34
# define DOLLAR_SIGN	36
# define SINGLE_QUOTES	39

// STRUCTS
typedef struct s_data
{
	int		args_num;
	int		error;
	int		exit_code;
	char	*input;
	char	*prompt;
	char	**envp;
}	t_data;

// GLOBAL VARIABLE
t_data	g_obj;

/* FUNCTIONS */
// BUILTINS
int		echo_prompt(char **args);
int		env_prompt(void);
int		export_prompt(char **args);
int		pwd_prompt(void);
int		unset_prompt(char **args);
void	exit_prompt(void);

// UTILS
int		has_quotes_before_space(char *str);
int		increment_count(int i, int c);
int		increment_quotes(int i);
int		skip_spaces(int i, int j);
char	*join_list(t_list *char_list);
char	**clean_quotes(char **temp);
char	**replace_env_var(char **temp);
char	**tokenizer(void);
void	check_input(void);
void	new_line(int signal);
void	new_prompt(int signal);
void	split_args(char **args);

#endif
