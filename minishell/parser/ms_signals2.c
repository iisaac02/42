/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:37:02 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/07/24 09:37:04 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <signal.h>

void	ms_heresignal(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	g_signal = 1;
	close(STDIN_FILENO);
}

void	ms_setsignals3(void)
{
	struct sigaction	signal;

	ft_memset(&signal, 0, sizeof(signal));
	signal.sa_handler = &ms_heresignal;
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
}

void	ms_childsignal(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	g_signal = 1;
}

void	ms_quitsignal(int signum)
{
	(void)signum;
	write(1, "Quit (core dumped)\n", 19);
	g_signal = 1;
}

void	ms_setsignals4(void)
{
	struct sigaction	signal1;
	struct sigaction	signal2;

	ft_memset(&signal1, 0, sizeof(signal1));
	signal1.sa_handler = &ms_childsignal;
	signal1.sa_flags = SA_RESTART;
	sigaction(SIGINT, &signal1, NULL);
	ft_memset(&signal2, 0, sizeof(signal2));
	signal2.sa_handler = &ms_quitsignal;
	signal2.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &signal2, NULL);
}
