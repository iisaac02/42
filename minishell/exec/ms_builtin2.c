/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:36:28 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/07/24 09:36:30 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_updatepwd(t_myshell *myshell)
{
	char	*pwd;
	char	*newpwd;
	char	*oldpwd;
	int		i;

	i = 0;
	newpwd = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", newpwd);
	while (myshell->env[i] && (ft_strncmp("PWD=", myshell->env[i], 4) != 0))
		i++;
	if (myshell->env[i] != NULL)
		oldpwd = ft_strjoin("OLDPWD=", ms_gv(myshell, "PWD"));
	else
		oldpwd = ft_strdup("OLDPWD=");
	if (ms_replacevariable(myshell, pwd) == 0)
		ms_addvariable(myshell, pwd);
	if (ms_replacevariable(myshell, oldpwd) == 0)
		ms_addvariable(myshell, oldpwd);
	free(pwd);
	free(oldpwd);
	free(newpwd);
}

int	ms_replacevariable(t_myshell *myshell, char *string)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (string == NULL)
		return (0);
	while (string[i] && string[i++] != '=')
		len++;
	i = 0;
	while (myshell->env[i])
	{
		if (ft_strncmp(myshell->env[i], string, len) == 0)
		{
			free(myshell->env[i]);
			myshell->env[i] = ft_strdup(string);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ms_gv(t_myshell *myshell, char *name)
{
	int		i;
	int		j;
	char	*key;

	i = 0;
	key = ft_strjoin(name, "=");
	j = ft_strlen(key);
	while (myshell->env && myshell->env[i]
		&& (ft_strncmp(key, myshell->env[i], j) != 0))
		i++;
	free(key);
	if (!myshell->env || !myshell->env[i])
		return (NULL);
	return ((myshell->env[i] + j));
}

void	ms_tilde(t_myshell *myshell, t_command *command)
{
	int		i;
	char	*temp;

	i = 0;
	if (command->command[1] == NULL || command->command[1][0] != '~')
		return ;
	while (myshell->env[i] && (ft_strncmp("HOME=", myshell->env[i], 5) != 0))
		i++;
	if (myshell->env[i] != NULL)
	{
		temp = ft_strjoin(ms_gv(myshell, "HOME"), &command->command[1][1]);
		free(command->command[1]);
		command->command[1] = temp;
	}
	else
	{
		temp = ft_strdup(myshell->home);
		free(command->command[1]);
		command->command[1] = temp;
	}
}

void	ms_changedir(t_myshell *myshell, t_command *command)
{
	ms_laststatus(myshell, 0);
	ms_tilde(myshell, command);
	if (command->command[2] != NULL)
		return (ms_error(myshell, "cd: too many arguments\n", 1));
	if (command->command[1] == NULL && ms_gv(myshell, "HOME") == NULL)
		return (ms_error(myshell, "cd: HOME not set\n", 1));
	else if (command->command[1] == NULL && chdir(ms_gv(myshell, "HOME")) != 0)
		return (ms_error(myshell, "cd: No such file or directory\n", 1));
	else if (command->command[1] == NULL)
		chdir(ms_gv(myshell, "HOME"));
	else if (command->command[1][0] == '-' && (ms_gv(myshell, "OLDPWD")
		== NULL || ms_gv(myshell, "OLDPWD")[0] == '\0'))
		ms_error(myshell, "cd: OLDPWD not set\n", 1);
	else if (command->command[1][0] == '-' && !chdir(ms_gv(myshell, "OLDPWD")))
		printf("%s\n", ms_gv(myshell, "OLDPWD"));
	else if (command->command[1][0] == '-' && chdir(ms_gv(myshell, "OLDPWD")))
		return (ms_error(myshell, "cd: No such file or directory\n", 1));
	else if (chdir(command->command[1]) != 0)
		return (ms_error(myshell, "cd: No such file or directory\n", 1));
	ms_updatepwd(myshell);
}
