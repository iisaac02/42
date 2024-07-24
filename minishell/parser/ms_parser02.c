/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:00:22 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/16 13:58:21 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_processtoken(t_myshell *myshell, t_command *command, char *token)
{
	int	len2;

	len2 = 0;
	if (*token == '\0')
		return (free(token));
	while (token[len2] != '\0')
	{
		if ((token[len2] == '<' || token[len2] == '>')
			&& (token[len2 + 1] == '<' || token[len2 + 1] == '>'))
			ms_redirections2(command, token, &len2);
		else if (token[len2] == '<' || token[len2] == '>')
			ms_redirections1(command, token, &len2);
		if (token[len2] == '\0')
			return (free(token));
		else
		{
			ms_words(myshell, command, token, &len2);
			if (command->token == 1)
				continue ;
			else if (token != NULL || token[len2] == '\0')
				return ;
		}
	}
}

int	ms_quotestoken(char *string)
{
	int		i;
	char	quote;

	i = 0;
	quote = string[i++];
	while (string[i] && string[i] != quote)
		i++;
	if (string[i] == quote)
		i++;
	while (string[i] && (string[i] != 32 && (string[i] < 9 || string[i] > 13))
		&& string[i] != '\'' && string[i] != '"' && string[i] != '|')
		i++;
	return (i);
}

char	*ms_findtoken(t_myshell *myshell, char *string, int *len)
{
	char	*token;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (string[i] == 32 || (string[i] >= 9 && string[i] <= 13))
		i++;
	while ((string[i + j] && string[i + j] != 32 && (string[i + j] < 9
				|| string[i + j] > 13)) && string[i + j] != '\''
		&& string[i + j] != '"' && string[i + j] != '|')
		j++;
	while (string[i + j] && (string[i + j] == '\'' || string[i + j] == '"'))
		j += ms_quotestoken(&string[i + j]);
	if (string[i + j] == '|' && (string[i + j -1] == 32
			|| string[i + j -1] == 9))
		j++;
	token = ft_substr(string, i, j);
	if (!token)
		ms_error(myshell, "token memory allocation failure", 12);
	*len += i + j;
	return (token);
}

void	ms_getcommands(t_myshell *myshell, char *line)
{
	char	*token;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (line[len] != '\0')
	{
		if (line[len] == '|')
		{
			i++;
			len++;
		}
		token = ms_findtoken(myshell, &line[len], &len);
		if (*token == '|')
		{
			free(token);
			i++;
			continue ;
		}
		if (myshell->error == 1)
			return (free(token));
		ms_processtoken(myshell, &myshell->commands[i], token);
	}
}
