/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_environment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:12:56 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/17 09:22:53 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_duplicateenv(t_myshell *myshell, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (env[i] != NULL)
		i++;
	myshell->env = malloc(sizeof(char *) * (i + 3));
	if (!myshell->env)
		return (ms_error(myshell, "memory allocation failure in env", 12));
	while (env[++j])
		myshell->env[j] = ft_strdup(env[j]);
	if (j == 0)
		myshell->env[j++] = ft_strdup("PATH=/usr/local/sbin:/usr/local/bin:/usr\
/sbin:/usr/bin:/sbin:/bin");
	myshell->env[j] = ft_strdup("?=0");
	myshell->env[++j] = NULL;
	ms_shlvl(myshell);
	ms_savehome(myshell);
}

char	*ms_expandedtoken(char *envline, char *token, int *pos, int len)
{
	int		len3;
	int		len4;
	char	*newtoken;

	len = len + 1;
	len4 = 0;
	if (envline)
		len4 = ft_strlen(envline) - (len);
	len3 = ft_strlen(token) - (len);
	newtoken = malloc(len4 + len3 + 1);
	if (!newtoken)
		return (NULL);
	len3 = -1;
	while (token[++len3] != '$')
		newtoken[len3] = token[len3];
	*pos = len3 + len4;
	len4 = len3 + len;
	while (envline && envline[len])
		newtoken[len3++] = envline[len++];
	while (token[len4])
		newtoken[len3++] = token[len4++];
	newtoken[len3] = '\0';
	return (newtoken);
}

int	ms_envlenght(char *token, int *pos)
{
	int	len;
	int	i;

	i = *pos;
	len = 0;
	while (token[i] && token[i] != 32 && token[i] != '"' && token[i] != '\''
		&& (token[i] < 9 || token[i] > 13) && token[i] != '='
		&& token[i] != '$')
	{
		len++;
		i++;
	}
	return (len);
}

int	ms_checkequal(char *envline, int len)
{
	int	i;

	i = 0;
	while (envline[i] && envline[i] != '=')
		i++;
	if (i == len)
		return (0);
	return (1);
}

char	*ms_expanding(t_myshell *myshell, char *token, int *pos)
{
	int		len;
	int		i;
	char	*newtoken;

	*pos = *pos + 1;
	if (token[*pos] == 0 || token[*pos] == 32 || token[*pos] == '"')
	{
		newtoken = ft_strdup(token);
		free (token);
		return (newtoken);
	}
	len = ms_envlenght(token, pos);
	if (token[*pos] == '?')
		len = 1;
	i = 0;
	while (myshell->env[i] && !(ft_strncmp(&token[*pos], myshell->env[i],
				len) == 0 && ms_checkequal(myshell->env[i], len) == 0))
		i++;
	newtoken = ms_expandedtoken(myshell->env[i], token, pos, len);
	free(token);
	token = NULL;
	if (newtoken[0] == '\0')
		return (free(newtoken), NULL);
	return (newtoken);
}
