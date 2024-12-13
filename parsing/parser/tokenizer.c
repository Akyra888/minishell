/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:54:21 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/13 19:57:26 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_txt(t_parserstate *state, char c)
{
	if (!state->current_token)
		state->current_token = create_token(state);
	define_type(state, 0);
	push_char(state->current_token, c, state);
	state->index++;
}

static void	handle_operator(t_parserstate *state, char operator_char)
{
	char	next_char;

	push_token(state->table, state->current_token, state);
	state->current_token = create_token(state);
	next_char = state->line[state->index + 1];
	define_op_type(state, operator_char, next_char);
	if ((operator_char == '>' && next_char == '>')
		|| (operator_char == '<' && next_char == '<'))
	{
		push_char(state->current_token, operator_char, state);
		operator_char = state->line[++state->index];
	}
	push_char(state->current_token, operator_char, state);
	push_token(state->table, state->current_token, state);
	state->current_token = NULL;
	state->index++;
}

static void	handle_quote(t_parserstate *state, char quote)
{
	char	c;

	if (!state->current_token)
		state->current_token = create_token(state);
	define_type(state, 1);
	while (state->line[state->index++] != '\0')
	{
		c = state->line[state->index];
		while (c == '$' && is_valid_exp(state->line[state->index + 1], 0)
			&& quote != '\'' && !prev_heredoc(state))
		{
			handle_expansion(state, 1);
			c = state->line[state->index];
		}
		if (c == quote)
		{
			state->index++;
			break ;
		}
		else
			push_char(state->current_token, c, state);
	}
}

t_tokentab	*tokenizer(t_parserstate *state)
{
	char			c;

	while (state->line[state->index] != '\0')
	{
		c = state->line[state->index];
		if ((c == ' ' || c == '\t'))
		{
			push_token(state->table, state->current_token, state);
			state->index++;
		}
		else if (c == '$' && is_valid_exp(state->line[state->index + 1], 1)
			&& !prev_heredoc(state))
			handle_expansion(state, 0);
		else if (c == '\'' || c == '"')
			handle_quote(state, c);
		else if (is_operator(c))
			handle_operator(state, c);
		else
			handle_txt(state, c);
	}
	push_token(state->table, state->current_token, state);
	return (state->table);
}
