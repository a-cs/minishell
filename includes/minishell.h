/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:40:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/21 23:40:41 by rfelipe-         ###   ########.fr       */
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
int		is_builtin(char **args);
void	echo_prompt(char **args);
void	env_prompt(void);
void	execute_builtin(char **args, int code);
void	exit_prompt(void);
void	export_prompt(char **args);
void	pwd_prompt(void);
void	unset_prompt(char **args);

// SYSTEM
char	**dup_envp(char **envp);
void	keep_prompt(char **envp);
void	reset_obj_data(void);
void	start_msg(void);

// TOKENIZER
int		has_quotes_before_space(char *str);
int		increment_count(int i, int c);
int		increment_quotes(int i);
int		skip_spaces(int i, int j);
char	*join_list(t_list *char_list);
char	**clean_quotes(char **temp);
char	**replace_env_var(char **temp);
char	**tokenizer(void);
void	split_args(char **args);

// UTILS
void	execute_cmd(char **args);
void	new_line(int signal);
void	new_prompt(int signal);

#endif
