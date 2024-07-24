/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:57:55 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/16 13:57:54 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_builtinexec(t_myshell *myshell, t_command *command)
{
	if (!command->command[0])
		return ;
	if (ft_strncmp(command->command[0], "echo", 5) == 0)
		ms_echo(myshell, command);
	else if (ft_strncmp(command->command[0], "cd", 3) == 0)
		ms_changedir(myshell, command);
	else if (ft_strncmp(command->command[0], "pwd", 4) == 0)
		ms_pwd(myshell, command);
	else if (ft_strncmp(command->command[0], "export", 7) == 0)
		ms_export(myshell, command);
	else if (ft_strncmp(command->command[0], "unset", 6) == 0)
		ms_unset(myshell, command);
	else if (ft_strncmp(command->command[0], "env", 4) == 0)
		ms_env(myshell, command);
	else if (ft_strncmp(command->command[0], "exit", 5) == 0)
		ms_exit(myshell, command);
}

void	ms_redirection2(t_myshell *myshell, t_command *command)
{
	int	i;
	int	fd;

	i = -1;
	while (command->redirs[++i] != NULL)
	{
		fd = -5;
		if (command->redirs[i][0] == '>' && command->redirs[i][1] == '>')
			fd = open(command->redirs[++i], O_APPEND | O_CREAT | O_WRONLY,
					0644);
		else if (command->redirs[i][0] == '>' && command->redirs[i][1] == '\0')
			fd = open(command->redirs[++i], O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (fd == -1 && myshell->error == 0)
			return (ms_error(myshell, " No such file or directory\n", 1));
		if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
		{
			close(fd);
			return (ms_error(myshell, "Error in redirection STDOUT\n", 1));
		}
		if (fd > 0)
			command->token = 1;
		close (fd);
	}
}

void	ms_redirection1(t_myshell *myshell, t_command *command)
{
	int	i;
	int	fd;

	i = -1;
	while (command->redirs[++i] != NULL)
	{
		fd = -5;
		if (command->redirs[i] && command->redirs[i][0] == '<')
			fd = open(command->redirs[++i], O_RDONLY);
		if (fd == -1 && myshell->error == 0)
			return (ms_error(myshell, " No such file or directory\n", 1));
		if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
		{
			close(fd);
			return (ms_error(myshell, "Error in redirection STDIN\n", 1));
		}
		if (fd > 0)
			command->redir = 1;
		close (fd);
	}
}

void	ms_stdredir(t_myshell *myshell, int nbr)
{
	static int	input;
	static int	output;

	if (nbr == 1)
	{
		input = dup(STDIN_FILENO);
		output = dup(STDOUT_FILENO);
	}
	else
	{
		if (dup2(input, STDIN_FILENO) < 0)
			ms_error(myshell, "Error in resetting stdin\n", 1);
		if (dup2(output, STDOUT_FILENO) < 0)
			ms_error(myshell, "Error in resetting stdout\n", 1);
		close(input);
		close(output);
	}
}
