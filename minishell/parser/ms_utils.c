/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:37:08 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/07/24 09:37:10 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <dirent.h>
#include "../minishell.h"

void	ms_laststatus(t_myshell *myshell, int status)
{
	int		i;
	char	*last;
	char	*nbr;

	i = 0;
	nbr = ft_itoa(status);
	last = ft_strjoin("?=", nbr);
	while (myshell->env[i][0] != '?')
		i++;
	free (myshell->env[i]);
	myshell->env[i] = last;
	free (nbr);
}

void	ms_shlvl(t_myshell *myshell)
{
	int		i;
	int		j;
	int		shlvl;
	char	*temp;
	char	*string;

	i = 0;
	j = 6;
	shlvl = 0;
	while (myshell->env[i] && (ft_strncmp("SHLVL=", myshell->env[i], 6) != 0))
		i++;
	while (myshell->env[i] && myshell->env[i][j])
		shlvl = shlvl * 10 + (myshell->env[i][j++] - '0');
	shlvl += 1;
	temp = ft_itoa(shlvl);
	string = ft_strjoin("SHLVL=", temp);
	ms_replacevariable(myshell, string);
	free (temp);
	free (string);
}

void	ms_reopenstdin(t_myshell *myshell)
{
	int	fd;

	if (access("/dev/tty", R_OK) == 0)
	{
		fd = open("/dev/tty", O_RDONLY);
		if (fd == -1)
			return (ms_error(myshell, "open fd", 1));
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			close(fd);
			return (ms_error(myshell, "open fd", 1));
		}
	}
}

void	ms_unlink(t_myshell *myshell)
{
	DIR				*dir;
	char			*filepath;
	struct dirent	*entry;

	dir = opendir(myshell->temp);
	if (!dir)
		return (ms_error(myshell, "error opening directory\n", 1));
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_type == DT_REG && !ft_strncmp(entry->d_name, "hedoc_", 6))
		{
			filepath = ft_strjoin(myshell->temp, entry->d_name);
			if (unlink(filepath) != 0)
				ms_error(myshell, "error deleting file", 1);
			if (filepath)
				free (filepath);
			filepath = NULL;
		}
	}
	closedir(dir);
}

void	ms_savehome(t_myshell *myshell)
{
	char	*path;
	char	*temp;
	char	*home;
	int		i;

	i = -1;
	path = getcwd(NULL, 0);
	home = malloc(15);
	while (++i < 14)
		home[i] = path[i];
	home[i] = '\0';
	myshell->home = home;
	free(path);
	path = getcwd(NULL, 0);
	temp = ft_strjoin(path, "/temp/");
	myshell->temp = temp;
	free(path);
}

//gcc -std=gnu11 -o ms_utils ms_utils.c 