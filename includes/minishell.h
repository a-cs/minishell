/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:40:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/16 00:56:54 by acarneir         ###   ########.fr       */
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
	char	*input;
	char	*prompt;
	char	**envp;
}	t_data;

/* FUNCTIONS */
// BUILTINS
int		echo_prompt(char **args, t_data *obj);
int		env_prompt(t_data *obj);
int		pwd_prompt(void);
void	exit_prompt(t_data *obj);

// UTILS
int		has_quotes_before_space(char *str);
int		increment_count(t_data *obj, int i, int c);
int		increment_quotes(t_data *obj, int i);
int		skip_spaces(t_data *obj, int i, int j);
char	*join_list(t_list *char_list);
char	**clean_quotes(t_data *obj, char **temp);
char	**replace_env_var(t_data *obj, char **temp);
char	**tokenizer(t_data *obj);
void	check_input(t_data *obj);
void	new_line(int signal);
void	new_prompt(int signal);
void	split_args(t_data *obj, char **args);

#endif
