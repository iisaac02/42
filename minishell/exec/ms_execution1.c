/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execution1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:39:11 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/04 10:19:54 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_isbuiltin(t_command *command)
{
	if (command->command[0] && (ft_strncmp(command->command[0], "echo", 5) == 0
			|| ft_strncmp(command->command[0], "cd", 3) == 0
			|| ft_strncmp(command->command[0], "pwd", 4) == 0
			|| ft_strncmp(command->command[0], "export", 7) == 0
			|| ft_strncmp(command->command[0], "unset", 6) == 0
			|| ft_strncmp(command->command[0], "env", 4) == 0
			|| ft_strncmp(command->command[0], "exit", 5) == 0))
		return (1);
	else
		return (0);
}

void	ms_onebuiltin(t_myshell *myshell, t_command *command)
{
	ms_stdredir(myshell, 1);
	ms_redirection1(myshell, command);
	ms_redirection2(myshell, command);
	if (myshell->error == 1)
		return ;
	ms_builtinexec(myshell, command);
	ms_stdredir(myshell, 2);
	ms_unlink(myshell);
}

void	ms_child(t_myshell *myshell, t_command *command, int *pipefd, int *prev)
{
	ms_redirection1(myshell, command);
	if (command->index != 1 && command->redir == 0)
	{
		if (dup2(prev[0], STDIN_FILENO) < 0)
			return (ms_error(myshell, "Error duplicating fd STDIN\n", 27));
		close(prev[0]);
		close(prev[1]);
	}
	ms_redirection2(myshell, command);
	if (command->index < myshell->nbr_command && command->token == 0)
	{
		if (dup2(pipefd[1], STDOUT_FILENO) < 0)
			return (ms_error(myshell, "Error duplicating fd STDOUT\n", 28));
		close(pipefd[1]);
		close(pipefd[0]);
	}
	if (ms_isbuiltin(command) == 1)
		return (ms_builtinexec(myshell, command));
	ms_findcommand(myshell, command);
	execve(command->path, command->command, myshell->env);
}

void	ms_parentproccess(t_myshell *myshell, t_command *command, int *prev)
{
	pid_t	child;
	int		pipefd[2];

	if (command->index < myshell->nbr_command && pipe(pipefd) == -1)
		return (ms_error(myshell, "Error creating pipe", 36));
	ms_setsignals4();
	child = fork();
	if (child < 0)
		return (ms_error(myshell, "Error creating child process", 35));
	if (child == 0)
	{
		myshell->child = 1;
		ms_child(myshell, command, pipefd, prev);
		myshell->error = ft_atoi(ms_gv(myshell, "?"));
		exit(myshell->error);
	}
	else
	{
		if (command->index != 1)
			close(prev[0]);
		close(prev[1]);
		prev[0] = pipefd[0];
		prev[1] = pipefd[1];
	}
}

void	ms_execution(t_myshell *myshell)
{
	int	i;
	int	status;
	int	prev[2];

	i = -1;
	prev[0] = 0;
	prev[1] = -1;
	if (myshell->nbr_command == 1 && ms_isbuiltin(&myshell->commands[0]) == 1)
		return (ms_onebuiltin(myshell, &myshell->commands[0]));
	while (++i < myshell->nbr_command)
		ms_parentproccess(myshell, &myshell->commands[i], prev);
	i = -1;
	while (++i < myshell->nbr_command)
	{
		waitpid(-1, &status, 0);
		ms_laststatus(myshell, WEXITSTATUS(status));
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
			ms_laststatus(myshell, 130);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
			ms_laststatus(myshell, 131);
	}
	ms_unlink(myshell);
}
