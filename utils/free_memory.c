/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyra <kyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:32:00 by nicpinar          #+#    #+#             */
/*   Updated: 2025/01/28 20:53:09 by kyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	malloc_error2(char *str, char **split, t_sections **sections, char **dict)
{
	if (split)
		free_strs(split);
	if (sections)
		free_sections(sections);
	if (dict)
		free_strs(dict);
	ft_putstr_fd(str, 2);
	g_signbr = 2;
	exit(g_signbr);
}

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
	{
		if (state->current_token->str)
			free(state->current_token->str);
		if (state->current_token->expanded_split)
			free_strs(state->current_token->expanded_split);
		free(state->current_token);
	}
	if (state->table)
		destroy_token_table(state->table);
	g_signbr = 2;
	exit(g_signbr);
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
		if (curr->binpath)
			free(curr->binpath);
		free_strs(curr->redir);
		free_strs(curr->filename);
		free_strs(curr->heredoc);
		if (curr->pipe)		
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