/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:50:11 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/15 18:19:35 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	do_nothing(void)
{
	return (0);
}

void	sigquit_child(int sig)
{
	g_signbr = sig;
	ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	sigint_child(int sig)
{
	g_signbr = sig + 128;
	write(STDERR_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	sigint_main(int sig)
{
	g_signbr = sig + 128;
	write(STDERR_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigint_heredoc(int sig)
{
	g_signbr = sig;
	rl_replace_line("", 0);
	rl_done = 1;
	rl_on_new_line();
}