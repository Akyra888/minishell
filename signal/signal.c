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

void	setup_child_signals(void)
{
	signal(SIGINT, sigint_child);
	signal(SIGQUIT, sigquit_child);
}

void	setup_heredoc_signals(void)
{
	signal(SIGINT, sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	setup_signals(void)
{
	rl_event_hook = do_nothing;
	signal(SIGINT, sigint_main);
	signal(SIGQUIT, SIG_IGN);
}
