/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokens01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:12:11 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/22 10:18:05 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_redirections1(t_command *command, char *token, int *len2)
{
	int	i;

	i = 0;
	command->redir = 1;
	command->token = 0;
	while (command->redirs[i] != NULL)
		i++;
	if (token[*len2] == '<')
		command->redirs[i] = ft_strdup("<");
	else if (token[*len2] == '>')
		command->redirs[i] = ft_strdup(">");
	i = 0;
	while (token[i + *len2 + 1] != '\0')
	{
		token[i] = token[i + *len2 + 1];
		i++;
	}
	token[i] = '\0';
	*len2 = 0;
}

void	ms_redirections2(t_command *command, char *token, int *len2)
{
	int	i;

	i = 0;
	command->redir = 1;
	command->token = 0;
	while (command->redirs[i] != NULL)
		i++;
	if (token[*len2] == '<' && token[*len2 + 1] == '>')
		command->redirs[i] = ft_strdup("<");
	else if (token[*len2 + 1] == '<' && token[*len2 + 2] != '<')
		command->redirs[i] = ft_strdup("<<");
	else if (token[*len2 + 1] == '>' && token[*len2 + 2] != '>')
		command->redirs[i] = ft_strdup(">>");
	i = 0;
	while (token[i + *len2 + 2] != '\0')
	{
		token[i] = token[i + *len2 + 2];
		i++;
	}
	token[i] = '\0';
	*len2 = 0;
}

void	ms_deleteqts(t_command *command, char *token, int *pos)
{
	int	i;

	i = *pos;
	if (token[i] == '\'')
		command->qts1 = !command->qts1;
	if (token[i] == '\"')
		command->qts2 = !command->qts2;
	if (*pos > 0 && token[i + 1] != '\0')
		*pos = *pos - 1;
	while (token[i])
	{
		token[i] = token[i + 1];
		i++;
	}
	token[i] = '\0';
}

void	ms_savetokens(t_command *command, char *token, int i, int *len2)
{
	char	*temp;
	int		j;

	j = 0;
	temp = NULL;
	temp = ft_substr(token, *len2, i - *len2);
	if (i > 0 && !temp)
		printf("temp memory allocation failure");
	if (temp != NULL && command->redir == 1)
	{
		while (j < 30 && command->redirs[j] != NULL)
			j++;
		command->redirs[j] = temp;
		command->redir = 0;
	}
	else if (temp != NULL)
	{
		while (j < 50 && command->command[j] != NULL)
			j++;
		command->command[j] = temp;
	}
}

void	ms_words(t_myshell *myshell, t_command *command, char *token, int *len2)
{
	int		i;

	i = *len2;
	while (token && token[i] && (!((token[i] == '<' || token[i] == '>')
				&& command->qts1 == 0 && command->qts2 == 0)))
	{
		if (token[i] == '\'' && command->qts2 == 0)
			ms_deleteqts(command, token, &i);
		else if (token[i] == '"' && command->qts1 == 0)
			ms_deleteqts(command, token, &i);
		else if (token[i] == '$' && command->qts1 == 0)
			token = ms_expanding(myshell, token, &i);
		else
			i++;
	}
	if (token && token[i] && (token[i] == '<' || token[i] == '>'))
		command->token = 1;
	if (token)
		ms_savetokens(command, token, i, len2);
	*len2 = i;
	if (token && token[*len2] == '\0')
		return (free (token));
}
