/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:49:28 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/16 13:57:17 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ms_expandhd(t_myshell *myshell, char *line)
{
	int		i;
	char	*newline;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			newline = ms_expanding(myshell, line, &i);
			return (newline);
		}
		i++;
	}
	return (line);
}

void	ms_readinghd(t_myshell *myshell, int fd, char *lmt)
{
	char	*line;

	while (g_signal == 0)
	{
		ms_setsignals3();
		line = readline("> ");
		ms_reopenstdin(myshell);
		if (line == NULL || ft_strncmp(line, lmt, ft_strlen(lmt) + 1) == 0)
		{
			free (line);
			break ;
		}
		line = ms_expandhd(myshell, line);
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line == NULL && g_signal == 0)
		printf("warning: here-document at line delimited by end-of-file\n");
}

void	ms_createfile(t_myshell *myshell, t_command *command, int count, int j)
{
	char	*line;
	char	*path;
	char	*lmt;
	int		fd;

	lmt = command->redirs[j + 1];
	path = ft_strjoin(myshell->temp, "/hedoc_");
	line = ft_itoa(count);
	command->redirs[j + 1] = ft_strjoin(path, line);
	free (line);
	free (path);
	fd = open(command->redirs[j + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ms_error(myshell, "error creating a here_doc file\n", 1));
	ms_readinghd(myshell, fd, lmt);
	free(lmt);
	close(fd);
}

void	ms_heredoc(t_myshell *myshell)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < myshell->nbr_command)
	{
		j = 0;
		while (myshell->commands[i].redirs[j] != NULL)
		{
			if (myshell->commands[i].redirs[j][0] == '<'
				&& myshell->commands[i].redirs[j][1] == '<')
			{
				count++;
				ms_createfile(myshell, &myshell->commands[i], count, j);
				if (myshell->error == 1 || g_signal == 1)
					return ;
				myshell->commands[i].redirs[j][1] = '\0';
			}
			j++;
		}
		i++;
	}
}
