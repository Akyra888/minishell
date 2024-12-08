/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:05:19 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/01 19:05:19 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_signal(void)
{
	if (g_sigint_received == SIGINT)
	{
		rl_replace_line("", 0);
		rl_done = 1;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		return (1);
	}
	return (0);
}

static void	sigint_handler(int sig)
{
	g_sigint_received = sig;
}

int	ft_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = sigint_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		ft_putstr_fd("SIGACTION FAILED FOR SIGINT\n", 2);
		return (0);
	}
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
	{
		ft_putstr_fd("SIGACTION FAILED FOR SIGQUIT\n", 2);
		return (0);
	}
	return (1);
}
