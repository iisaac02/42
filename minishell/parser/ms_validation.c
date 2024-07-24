/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:33:31 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/16 13:59:01 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_closing1(t_myshell *myshell, char **line)
{
	char	*line2;
	char	*newline;

	line2 = NULL;
	ms_setsignals3();
	line2 = readline("pipe> ");
	ms_reopenstdin(myshell);
	if (line2 != NULL)
	{
		newline = ft_strjoin(*line, line2);
		free (line2);
		free (*line);
		*line = newline;
		return ;
	}
	else if (g_signal == 0)
	{
		printf (" syntax error: unexpected end of file\n");
		printf("exit");
		free (line2);
		exit(2);
	}
}

void	ms_closing2(t_myshell *myshell, char **line)
{
	char	*line2;
	char	*newline;

	line2 = NULL;
	ms_setsignals3();
	newline = readline("quotes> ");
	ms_reopenstdin(myshell);
	if (newline)
		line2 = ft_strjoin("\n", newline);
	free (newline);
	if (line2 != NULL)
	{
		newline = ft_strjoin(*line, line2);
		free (line2);
		free (*line);
		*line = newline;
		return ;
	}
	else if (g_signal == 0)
	{
		printf(" unexpected EOF while looking for matching quotes\n");
		printf (" syntax error: unexpected end of file\n");
		free (line2);
		myshell->error = 1;
	}
}

int	ms_checkchars(t_myshell *myshell, char *line, int i)
{
	char	quote;

	while (line[i] != '\0' && (line[i] == 32 || line[i] == 9))
		i++;
	if (line[i] && (line[i] == '"' || line[i] == '\''))
	{
		quote = line[i++];
		while (line[i] && quote != line[i])
			i++;
		if (line[i])
			i++;
	}
	else if ((line[i] == '|' || line[i] == '&') && myshell->error == 0)
		ms_error(myshell, " syntax error near unexpected token `|'\n", 2);
	else if (line[i] == '\0' || line[i] == '!' || line[i] == '#')
		ms_error(myshell, "", 0);
	return (i);
}

void	ms_openpipes(t_myshell *myshell, char **line, int i)
{
	i = ms_checkchars(myshell, *line, i);
	while ((*line)[i] != '\0' && (*line)[i + 1] != '\0')
	{
		if ((*line)[i] == '"' || (*line)[i] == '\'')
			i = ms_checkchars(myshell, *line, i);
		if ((*line)[i] == '\0')
			break ;
		if ((*line)[i] == '|')
		{
			while ((*line)[i + 1] == 32 || (*line)[i + 1] == 9)
				i++;
			if ((*line)[i + 1] == '|' && myshell->error == 0)
				ms_error(myshell, " syntax error near unexpected token |\n", 2);
		}
		i++;
	}
	while (i > 0 && ((*line)[i] == '\0' || (*line)[i] == 32 || (*line)[i] == 9))
		i--;
	if ((*line)[i] == '|' && myshell->error == 0 && g_signal == 0)
	{
		ms_closing1(myshell, line);
		ms_openpipes(myshell, line, 0);
	}
}

void	ms_anglebrakets(t_myshell *myshell, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] && (line[i] == '"' || line[i] == '\''))
			i = ms_checkchars(myshell, line, i);
		if (line[i] && (line[i] == '<' || line[i] == '>'))
		{
			if (line[i] == '>' && line[i + 1] == '<' && myshell->error == 0)
				return (ms_error(myshell,
						" syntax error near unexpected token `<'\n", 2));
			i++;
			if (line[i] == '<' || line[i] == '>')
				i++;
			while (line[i] && (line[i] == 32 || line[i] == 9))
				i++;
			if ((line[i] == '\0' || line[i] == '<' || line[i] == '>'
					|| line[i] == '|') && (myshell->error == 0))
				return (ms_error(myshell,
						" syntax error near unexpected token `<'\n", 2));
		}
		if (line[i] != '\0')
			i++;
	}
}
