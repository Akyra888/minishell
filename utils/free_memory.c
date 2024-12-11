/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:32:00 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/11 14:45:30 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	malloc_error(char *str, t_parserstate *state, void **local)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	if (state->line)
		free(state->line);
	rl_clear_history();
	if (local && *local)
		free(*local);
	if (state->current_token)
		free(state->current_token);
	if (state->table)
		destroy_token_table(state->table);
	exit(EXIT_FAILURE);
}

void	free_sections(t_sections **sections)
{
	t_sections	*curr;
	t_sections	*next;

	if (!sections && !*sections)
		return ;
	curr = *sections;
	while (curr)
	{
		next = curr->next;
		free_strs(curr->args);
		free_strs(curr->redir);
		free_strs(curr->filename);
		free_strs(curr->heredoc);
		free(curr->pipe);
		free(curr);
		curr = next;
	}
	*sections = NULL;
}

int	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
	return (1);
}