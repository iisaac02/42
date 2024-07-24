/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:36:40 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/07/24 09:36:42 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ms_exportqts(char *string)
{
	int		i;
	int		j;
	int		equal;
	char	*newstr;

	i = 0;
	j = 0;
	equal = 0;
	newstr = malloc(ft_strlen(string) + 3);
	while (string[i])
	{
		if (i > 0 && string[i - 1] == '=' && equal == 0)
		{
			newstr[j++] = '"';
			equal = 1;
		}
		newstr[j++] = string[i++];
	}
	if (string[i - 1] == '=')
		newstr[j++] = '"';
	if (ft_strchr(string, '=') != NULL)
		newstr[j++] = '"';
	newstr[j] = '\0';
	return (newstr);
}

char	**ms_copyenv(t_myshell *myshell)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	j = -1;
	while (myshell->env[i] != NULL)
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (ms_error(myshell, "env: memory allocation failure", 12), NULL);
	while (++j < i)
		env[j] = ms_exportqts(myshell->env[j]);
	env[j] = NULL;
	return (env);
}

void	ms_exit(t_myshell *myshell, t_command *command)
{
	int	i;

	i = 0;
	if (myshell->child == 0)
		printf("exit\n");
	if (command->command[1] == NULL)
	{
		i = ft_atoi(ms_gv(myshell, "?"));
		ms_freeall(myshell);
		exit(i % 256);
	}
	if (command->command[1][0] == '-' || command->command[1][0] == '+')
		i++;
	while ((command->command[1] && command->command[1][i] && !ft_isdigit
		(command->command[1][i++]) && myshell->error == 0)
		|| ft_atoi(command->command[1]) == 0)
	{
		ms_error(myshell, "exit: numeric argument required\n", 2);
		exit(2);
	}
	if (command->command[2] != NULL)
		return (ms_error(myshell, "exit: too many arguments\n", 1));
	i = ft_atoi(command->command[1]) % 256;
	ms_freeall(myshell);
	exit (i);
}
//9223372036854775807