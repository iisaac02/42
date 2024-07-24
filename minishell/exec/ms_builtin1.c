/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:36:18 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/07/24 09:36:19 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_echooption(t_command *command, int len)
{
	int	i;
	int	j;

	i = 1;
	while (command->command[i])
	{
		j = 0;
		if (command->command[i][0] == '-' && command->command[i][1] == 'n')
		{
			j++;
			while (command->command[i][j] == 'n')
				j++;
		}
		if (command->command[i][j] == '\0')
			len++;
		else
			return (len);
		i++;
	}
	return (len);
}

void	ms_echo(t_myshell *myshell, t_command *command)
{
	int	i;
	int	option;

	i = 1;
	if (ft_strncmp(command->command[0], "echo", 5) != 0)
		return ;
	if (command->command[1] && command->command[1][0] == '-')
		i = ms_echooption(command, i);
	option = i;
	if (command->command[i] != NULL)
		printf("%s", command->command[i++]);
	while (command->command[i] != NULL)
	{
		printf(" ");
		printf("%s", command->command[i++]);
	}
	if (option == 1)
		printf("\n");
	ms_laststatus(myshell, 0);
}

void	ms_unset(t_myshell *myshell, t_command *command)
{
	int	i;
	int	j;

	j = 1;
	if (ft_strncmp(command->command[0], "unset", 6) != 0)
		return ;
	while (command->command[j])
	{
		i = 0;
		while (myshell->env[i])
		{
			if (ft_strncmp(myshell->env[i], command->command[j],
					ft_strlen(command->command[j])) == 0)
			{
				free(myshell->env[i--]);
				while (myshell->env[++i + 1])
					myshell->env[i] = myshell->env[i + 1];
				myshell->env[i] = NULL;
			}
			i++;
		}
		j++;
	}
	ms_laststatus(myshell, 0);
}

void	ms_env(t_myshell *myshell, t_command *command)
{
	int	i;

	i = -1;
	if (ft_strncmp(command->command[0], "env", 4) != 0)
		return ;
	while (myshell->env[++i])
	{
		if (myshell->env[i][0] != '?' && myshell->env[i][0] != '~'
			&& strchr(myshell->env[i], '=') != NULL)
			printf("%s\n", myshell->env[i]);
	}
	ms_laststatus(myshell, 0);
}

void	ms_pwd(t_myshell *myshell, t_command *command)
{
	int		i;
	char	*pwd;

	if (ft_strncmp(command->command[0], "pwd", 4) != 0)
		return ;
	ms_laststatus(myshell, 0);
	pwd = getcwd(NULL, 0);
	if (pwd != NULL)
	{
		printf("%s\n", pwd);
		free (pwd);
		return ;
	}
	i = 0;
	while (myshell->env[i] && ft_strncmp(myshell->env[i], "PWD=", 4) != 0)
		i++;
	if (myshell->env[i] != NULL)
		printf("%s\n", &myshell->env[i][4]);
	else
		printf("\n");
}
