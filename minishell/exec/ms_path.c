/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:36:47 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/07/24 09:36:49 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_checkpath(t_myshell *myshell, t_command *command)
{
	struct stat	pathstat;

	if (stat(command->command[0], &pathstat) == -1)
		return (ms_error(myshell, " No such file or directory\n", 127));
	else if (S_ISDIR(pathstat.st_mode))
		return (ms_error(myshell, " Is a directory\n", 126));
	else if (S_ISREG(pathstat.st_mode) && !(pathstat.st_mode & S_IXUSR))
		return (ms_error(myshell, " Permission denied\n", 126));
	else if (S_ISREG(pathstat.st_mode) && (pathstat.st_mode & S_IXUSR))
		command->path = command->command[0];
}

void	ms_findvalidpath(t_myshell *myshell, t_command *command, char **temp)
{
	char	*validpath;
	char	*tempath;
	int		i;

	i = 0;
	while (temp[i])
	{
		tempath = ft_strjoin(temp[i], "/");
		validpath = ft_strjoin(tempath, command->command[0]);
		free(tempath);
		if (!validpath)
			return (ms_error(myshell, "path memory allocation failure\n", 12));
		if (access(validpath, F_OK) == 0)
		{
			command->path = validpath;
			while (temp[i])
				free (temp[i++]);
			return (free (temp));
		}
		free (validpath);
		free (temp[i++]);
	}
	free (temp);
	if (myshell->error == 0)
		ms_error(myshell, " command not found\n", 127);
}

void	ms_findcommand(t_myshell *myshell, t_command *command)
{
	char	**temp;
	int		i;

	i = 0;
	temp = NULL;
	if (command->command[0] == NULL && (command->redir == 1
			|| command->token == 1))
		return ;
	if (command->command[0] == NULL)
		return ;
	if (command->command[0][0] == '\0')
		return (ms_error(myshell, " command not found\n", 127));
	if (ft_strchr(command->command[0], '/') != NULL)
	{
		ms_checkpath(myshell, command);
		return ;
	}
	while (myshell->env[i] && (ft_strncmp("PATH=", myshell->env[i], 5) != 0))
		i++;
	if (myshell->env[i] != NULL)
		temp = ft_split(&myshell->env[i][5], ':');
	if (!temp)
		return (ms_error(myshell, "No such file or directory\n", 127));
	ms_findvalidpath(myshell, command, temp);
}
