/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 09:38:20 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/16 16:22:09 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_openquotes(t_myshell *myshell, char **line)
{
	int		i;
	int		nbr;
	char	qte;

	i = -1;
	nbr = 0;
	while ((*line)[++i])
	{
		if (((*line)[i] == '"' || (*line)[i] == '\'') && nbr == 0)
		{
			qte = (*line)[i];
			nbr = !nbr;
		}
		else if (qte == (*line)[i])
		{
			qte = '0';
			nbr = !nbr;
		}
	}
	if (nbr == 1 && myshell->error == 0 && g_signal == 0)
	{
		ms_closing2(myshell, line);
		ms_openquotes(myshell, line);
	}
}

int	ms_pipenumber(char *line)
{
	int		i;
	int		commands;
	char	quote;

	i = 0;
	commands = 1;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			quote = line[i++];
			while (line[i] && line[i] != quote)
				i++;
		}
		if (line[i] && line[i] == '|')
			commands++;
		if (line[i])
			i++;
	}
	return (commands);
}

void	ms_commandnbr(t_myshell *myshell, char *line)
{
	int	count;

	count = ms_pipenumber(line);
	myshell->commands = ft_calloc(count + 1, sizeof(t_command));
	if (myshell->commands == NULL)
		ms_error(myshell, "commads array memory allocation failure", 12);
	myshell->nbr_command = count;
	count = -1;
	while (++count < myshell->nbr_command)
	{
		myshell->commands[count].index = count + 1;
		ft_memset(myshell->commands[count].command, '\0', 50);
		ft_memset(myshell->commands[count].redirs, '\0', 30);
		myshell->commands[count].path = NULL;
		myshell->commands[count].redir = 0;
		myshell->commands[count].qts1 = 0;
		myshell->commands[count].qts2 = 0;
		myshell->commands[count].token = 0;
	}
}

void	ms_lineprocessing(t_myshell *myshell, char **line)
{
	int	i;

	i = 0;
	myshell->error = 0;
	if (*line == NULL || **line == '\0')
		return ;
	ms_openquotes(myshell, line);
	ms_anglebrakets(myshell, *line);
	ms_openpipes(myshell, line, 0);
	if (myshell->error == 1 || g_signal == 1)
		return ;
	ms_commandnbr(myshell, *line);
	ms_getcommands(myshell, *line);
	if (myshell->error == 1 || g_signal == 1)
		return ;
	ms_heredoc(myshell);
	if (myshell->error == 1 || g_signal == 1)
		return ;
}
