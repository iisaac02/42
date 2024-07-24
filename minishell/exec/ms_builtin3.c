/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:36:35 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/07/24 09:36:37 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_onlyexport(t_myshell *myshell)
{
	int		i;
	int		min;
	char	**env;

	env = ms_copyenv(myshell);
	while (env[0])
	{
		i = -1;
		min = 0;
		while (env[++i])
		{
			if (ft_strncmp(env[min], env[i], 20) > 0)
				min = i;
		}
		if (ft_isalpha(env[min][0]))
			printf("declare -x %s\n", env[min]);
		free(env[min]);
		min--;
		while (env[++min + 1])
			env[min] = env[min + 1];
		env[min] = NULL;
	}
	free(env);
}

void	ms_addvariable(t_myshell *myshell, char *command)
{
	int		i;
	int		j;
	char	**dup;

	i = 0;
	j = -1;
	while (myshell->env[i] != NULL)
		i++;
	dup = malloc(sizeof(char *) * (i + 2));
	if (!dup)
		return (ms_error(myshell, "export: memory allocation failure", 12));
	while (++j < i)
		dup[j] = myshell->env[j];
	dup[j++] = ft_strdup(command);
	dup[j] = NULL;
	free(myshell->env);
	myshell->env = dup;
}

int	ms_validexport(t_myshell *myshell, char *command)
{
	int		i;

	i = 0;
	if (!ft_isalpha(command[0]) && command[0] != '_')
		ms_error(myshell, "export: not a valid identifier\n", 1);
	while (command[i] && command[i] != '=' && myshell->error == 0)
	{
		if (!ft_isalnum(command[i]) && command[i] != '_'
			&& !(command[i] == '+' && command[i + 1] == '='))
			ms_error(myshell, "export: not a valid identifier\n", 1);
		i++;
	}
	return (i);
}

void	ms_appendexport(t_myshell *myshell, t_command *command, int i, int j)
{
	char	*new;
	int		k;

	k = 0;
	i = i - 1;
	new = ft_substr(command->command[j], 0, i);
	while (myshell->env[k] && (ft_strncmp(new, myshell->env[k], i) != 0))
		k++;
	free(new);
	if (myshell->env[k] != NULL)
	{
		new = ft_strjoin(myshell->env[k], &command->command[j][i + 2]);
		free(command->command[j]);
		command->command[j] = new;
	}
	else
	{
		i--;
		while (command->command[j][++i + 1])
			command->command[j][i] = command->command[j][i + 1];
		command->command[j][i] = '\0';
	}
}

void	ms_export(t_myshell *myshell, t_command *command)
{
	int		j;
	int		i;

	j = 0;
	ms_laststatus(myshell, 0);
	if (command->command[j + 1] == NULL)
		ms_onlyexport(myshell);
	while (command->command[++j])
	{
		i = ms_validexport(myshell, command->command[j]);
		if (myshell->error == 1)
		{
			myshell->error = 0;
			continue ;
		}
		if (command->command[j][i] == '=' && command->command[j][i - 1] == '+')
			ms_appendexport(myshell, command, i, j);
		if (ms_replacevariable(myshell, command->command[j]) == 0)
			ms_addvariable(myshell, command->command[j]);
	}
}
