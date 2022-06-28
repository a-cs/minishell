/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:44:49 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/28 01:34:18 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_cwd(void)
{
	char	*export_pwd;
	char	*buffer;
	char	*pwd;

	buffer = NULL;
	pwd = getcwd(buffer, 0);
	export_pwd = ft_strjoin("export PWD=", pwd);
	free(pwd);
	return (export_pwd);
}

static void	try_chdir(char *path, char *oldpwd)
{
	char	*export_pwd;
	char	*export_oldpwd;
	char	**to_export;

	if (chdir(path) == 0)
	{
		export_pwd = get_cwd();
		export_oldpwd = ft_strjoin("export OLDPWD=", oldpwd);
		to_export = tokenizer(export_pwd);
		export_prompt(to_export);
		ft_free_matrix(to_export);
		to_export = tokenizer(export_oldpwd);
		export_prompt(to_export);
		ft_free_matrix(to_export);
		free(export_pwd);
		free(export_oldpwd);
	}
	else
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		g_obj.exit_code = 1;
	}
}

static void	to_old_chdir(char *oldpwd, char *pwd)
{
	char	*export_pwd;
	char	*export_oldpwd;
	char	**to_export;

	if (chdir(oldpwd) == 0)
	{
		export_pwd = ft_strjoin("export PWD=", oldpwd);
		export_oldpwd = ft_strjoin("export OLDPWD=", pwd);
		to_export = tokenizer(export_pwd);
		export_prompt(to_export);
		ft_free_matrix(to_export);
		to_export = tokenizer(export_oldpwd);
		export_prompt(to_export);
		ft_free_matrix(to_export);
		free(export_pwd);
		free(export_oldpwd);
	}
	else
	{
		ft_putendl_fd("cd: OLDPWD not set", STDERR_FILENO);
		g_obj.exit_code = 1;
	}
}

static void	do_cd(char **args, char **home, char **pwd, char **oldpwd)
{
	char	*aux;

	if (args[1][0] == '/')
		try_chdir(args[1], pwd[0]);
	else if (ft_memcmp(args[1], "-", ft_strlen(args[1])) == 0
		&& ft_memcmp(args[1], "-", 1) == 0)
		to_old_chdir(oldpwd[0], pwd[0]);
	else if (args[1][0] == '~')
	{
		aux = ft_strjoin(home[0], args[1] + 1);
		if (ft_strlen(args[1]) > 1)
			try_chdir(aux, pwd[0]);
		else
			try_chdir(home[0], pwd[0]);
		free(aux);
	}
	else
		try_chdir(args[1], pwd[0]);
}

void	cd_prompt(char **args)
{
	char	**home;
	char	**pwd;
	char	**oldpwd;

	if (g_obj.args_num > 2)
	{
		printf("cd: too many arguments\n");
		g_obj.error++;
		g_obj.exit_code = 1;
	}
	pwd = replace_env_var(tokenizer("$PWD"));
	oldpwd = replace_env_var(tokenizer("$OLDPWD"));
	home = replace_env_var(tokenizer("$HOME"));
	do_cd(args, home, pwd, oldpwd);
	ft_free_matrix(home);
	ft_free_matrix(pwd);
	ft_free_matrix(oldpwd);
}
