/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:40:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/25 16:20:01 by rfelipe-         ###   ########.fr       */
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
	int		close_code;
	int		old_pipe_in;
	int		invalid_input;
	int		initial_fd[2];
	int		actual_fd[2];
	char	*input;
	char	*prompt;
	char	**envp;
}	t_data;

// GLOBAL VARIABLE
extern t_data	g_obj;

/* FUNCTIONS */
// BUILTINS
int		is_builtin(char **args);
int		is_exit_cmd(void);
int		is_valid_attribution(char *arg, char *next);
void	echo_prompt(char **args);
void	env_prompt(void);
void	execute_builtin(char **args, int code);
void	exit_prompt(void);
void	export_prompt(char **args);
void	pwd_prompt(void);
void	unset_prompt(char **args);

// PIPE
char	**pipe_args(void);
void	pipe_checker(void);

// REDIRECT
char	**redirect_args(char **temp);
void	change_fd(int *fd);
void	change_input(char *file, int flags);
void	change_output(char *file, int flags);
void	clean_redirect_input(char **args, char **input);
void	here_doc(char *eof);
void	redirect(char **input);
void	save_fd(int *fd);

// SYSTEM
char	**dup_envp(char **envp);
void	execute(char **input);
void	keep_prompt(char **envp);
void	reset_obj_data(void);
void	start_msg(void);

// TOKENIZER
int		has_quotes_before_space(char *str);
int		increment_count(int i, int c, char *input);
int		increment_quotes(int i, char *input);
int		skip_spaces(int i, int j, char *input);
char	*join_list(t_list *char_list);
char	**clean_quotes(char **temp);
char	**replace_env_var(char **temp);
char	**tokenizer(char *input);
void	split_args(char **args, char *input);

// UTILS
int		is_valid_history(char *str);
void	execute_cmd(char **args);
void	here_doc_stop(int signal);
void	new_line(int signal);
void	new_prompt(int signal);
void	pipe_stop(int signal);

#endif
