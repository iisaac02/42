/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:17:26 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/18 14:18:17 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _POSIX_C_SOURCE 200809L

# include <stdio.h>	  // For printf
# include <unistd.h>  // For write
# include <stdlib.h>  // For exit
# include <string.h>  // For strerror
# include <errno.h>   // For errno
# include <fcntl.h>   // For open
# include <unistd.h>  // For close
# include <signal.h>  // For sigaction
# include <dirent.h>  // For directories
# include <limits.h>  // For macro limits
# include <sys/types.h> // For pid
# include <sys/wait.h> // For childen wait
# include <sys/stat.h> // For stat
# include <readline/readline.h> // read line
# include <readline/history.h> // line history
# include "libft/libft.h"

extern volatile sig_atomic_t	g_signal;

typedef struct s_command
{
	int		index;
	char	*command[50];
	char	*redirs[30];
	char	*path;
	int		redir;
	int		token;
	int		qts1;
	int		qts2;
}	t_command;

typedef struct s_myshell
{
	char		**env;
	char		*home;
	char		*temp;
	int			child;
	int			nbr_command;
	int			error;
	t_command	*commands;
}	t_myshell;

//global funtions
void	ms_error(t_myshell *myshell, char *error, int status);
void	ms_frecommands(t_myshell *myshell);
void	ms_freeall(t_myshell *myshell);
void	ms_setsignals1(void);
void	ms_setsignals2(void);
void	ms_setsignals3(void);
void	ms_setsignals4(void);
void	ms_duplicateenv(t_myshell *myshell, char **env);
void	ms_laststatus(t_myshell *myshell, int status);
void	ms_shlvl(t_myshell *myshell);
void	ms_savehome(t_myshell *myshell);
int		ms_isbuiltin(t_command *command);
void	print_myshell(t_myshell *myshell);

//parsing
void	ms_lineprocessing(t_myshell *myshell, char **line);
void	ms_getcommands(t_myshell *myshell, char *line);
char	*ms_findtoken(t_myshell *myshell, char *string, int *len);
void	ms_redirections1(t_command *command, char *token, int *len2);
void	ms_processtoken(t_myshell *myshell, t_command *command, char *token);
void	ms_words(t_myshell *myshell, t_command *command, char *token,
			int *len2);
char	*ms_expanding(t_myshell *myshell, char *token, int *pos);
void	ms_redirections2(t_command *command, char *token, int *len2);
void	ms_heredoc(t_myshell *myshell);
void	ms_openpipes(t_myshell *myshell, char **line, int i);
void	ms_openquotes(t_myshell *myshell, char **line);
void	ms_closing1(t_myshell *myshell, char **line);
void	ms_closing2(t_myshell *myshell, char **line);
void	ms_reopenstdin(t_myshell *myshell);
void	ms_anglebrakets(t_myshell *myshell, char *line);
int		ms_quotestoken(char *string);

//built in
void	ms_echo(t_myshell *myshell, t_command *command);
void	ms_unset(t_myshell *myshell, t_command *command);
void	ms_export(t_myshell *myshell, t_command *command);
void	ms_pwd(t_myshell *myshell, t_command *command);
void	ms_changedir(t_myshell *myshell, t_command *command);
void	ms_env(t_myshell *myshell, t_command *command);
void	ms_exit(t_myshell *myshell, t_command *command);
void	ms_addvariable(t_myshell *myshell, char *command);
char	*ms_gv(t_myshell *myshell, char *key);
int		ms_replacevariable(t_myshell *myshell, char *string);
char	**ms_copyenv(t_myshell *myshell);

//execution
void	ms_execution(t_myshell *myshell);
void	ms_builtinexec(t_myshell *myshell, t_command *command);
void	ms_redirection1(t_myshell *myshell, t_command *command);
void	ms_redirection2(t_myshell *myshell, t_command *command);
void	ms_stdredir(t_myshell *myshell, int nbr);
void	ms_findcommand(t_myshell *myshell, t_command *command);
void	ms_children(t_myshell *myshell, t_command *command, int *pipefd);
void	ms_unlink(t_myshell *myshell);

#endif