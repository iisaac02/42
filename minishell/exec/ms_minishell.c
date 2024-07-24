/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:24:58 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/18 14:24:22 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

volatile sig_atomic_t	g_signal = 0;

void	ms_error(t_myshell *myshell, char *error, int status)
{
	if (error != NULL)
	{
		while (*error)
			write(2, error++, 1);
	}
	myshell->error = 1;
	ms_laststatus(myshell, status);
	if (myshell->child == 1)
	{
		ms_freeall(myshell);
		exit(status);
	}
}

void	ms_frecommands(t_myshell *myshell)
{
	int	i;
	int	j;

	i = -1;
	while (++i < myshell->nbr_command)
	{
		j = -1;
		while (myshell->commands[i].command[++j] != NULL)
		{
			free(myshell->commands[i].command[j]);
			myshell->commands[i].command[j] = NULL;
		}
		j = -1;
		while (myshell->commands[i].redirs[++j] != NULL)
		{
			free(myshell->commands[i].redirs[j]);
			myshell->commands[i].redirs[j] = NULL;
		}
	}
	free(myshell->commands);
	myshell->commands = NULL;
	myshell->nbr_command = 0;
	myshell->error = 0;
	g_signal = 0;
}

void	ms_freeall(t_myshell *myshell)
{
	int	i;

	i = 0;
	ms_frecommands(myshell);
	while (myshell->env[i] != NULL)
	{
		free(myshell->env[i]);
		myshell->env[i++] = NULL;
	}
	free(myshell->env);
	myshell->env = NULL;
	free(myshell->home);
	myshell->home = NULL;
	free(myshell->temp);
	myshell->temp = NULL;
}

char	*ms_displaypath(void)
{
	char	*path;
	char	*display;
	int		i;
	int		j;

	i = 14;
	j = 0;
	path = getcwd(NULL, 0);
	display = malloc(ft_strlen(path) - 10);
	display[j++] = '~';
	while (path[i])
		display[j++] = path[i++];
	display[j++] = '$';
	display[j++] = ' ';
	display[j] = '\0';
	free (path);
	return (display);
}

int	main(int argc, char	**argv, char **env)
{
	t_myshell	myshell;
	char		*line;
	char		*display;

	ft_memset(&myshell, 0, sizeof(t_myshell));
	ms_duplicateenv(&myshell, env);
	while (argc || argv)
	{
		ms_setsignals1();
		display = ms_displaypath();
		line = readline(display);
		free(display);
		if (line == NULL)
			break ;
		ms_setsignals2();
		ms_lineprocessing(&myshell, &line);
		if (*line != 0)
			add_history(line);
		if (myshell.error == 0 && g_signal == 0)
			ms_execution(&myshell);
		free(line);
		ms_frecommands(&myshell);
	}
	ms_freeall(&myshell);
	printf("exit\n");
}
