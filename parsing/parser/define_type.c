/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyra <kyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:10:33 by nicpinar          #+#    #+#             */
/*   Updated: 2025/01/28 18:19:09 by kyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	define_type2(t_parserstate *state, int i)
{
	if (state->table->tokens[i - 1]->type == DELIMITER)
	{
		if (state->table->tokens[0]->type != COMMAND)
			state->current_token->type = COMMAND;
		else
			state->current_token->type = ARG;
	}
	if (state->table->tokens[i - 1]->type == PIPE)
		state->current_token->type = COMMAND;
}

void	define_type(t_parserstate *state, int quote)
{
	int		i;

	i = state->table->size;
	if (i == 0)
		state->current_token->type = COMMAND;
	else
	{
		if (state->table->tokens[i - 1]->type == COMMAND
			|| state->table->tokens[i - 1]->type == ARG)
			state->current_token->type = ARG;
		if (state->table->tokens[i - 1]->type == REDIN
			|| state->table->tokens[i - 1]->type == REDOUT
			|| state->table->tokens[i - 1]->type == REDAPP)
			state->current_token->type = FILENAME;
		if (state->table->tokens[i - 1]->type == HEREDOC)
			state->current_token->type = DELIMITER;
		if (state->table->tokens[i - 1]->type == HEREDOC && quote)
			state->current_token->type = DELIMITER_Q;
		if (state->table->tokens[i - 1]->type == FILENAME)
			state->current_token->type = ARG;
		define_type2(state, i);
	}
}

void	define_op_type(t_parserstate *state, char c, char next)
{
	if (c == '|')
		state->current_token->type = PIPE;
	else if (c == '<')
	{
		if (next == '<')
			state->current_token->type = HEREDOC;
		else
			state->current_token->type = REDIN;
	}
	else if (c == '>')
	{
		if (next == '>')
			state->current_token->type = REDAPP;
		else
			state->current_token->type = REDOUT;
	}
}
