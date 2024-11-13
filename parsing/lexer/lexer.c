/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:54:21 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/13 21:22:55 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	push_current_token(t_lexerstate *state)
{
	if (state->current_token)
	{
		push_token(state->table, state->current_token, state);
		state->current_token = NULL;
	}
}

static void	handle_operator(t_lexerstate *state, char operator_char)
{
	char	next_char;

	push_current_token(state);
	state->current_token = create_token(state);
	next_char = state->line[state->index + 1];
	if ((operator_char == '>' && next_char == '>')
		|| (operator_char == '<' && next_char == '<'))
	{
		push_char(state->current_token, operator_char, state);
		operator_char = state->line[++state->index];
	}
	define_type(state, operator_char, next_char);
	push_char(state->current_token, operator_char, state);
	push_token(state->table, state->current_token, state);
	state->current_token = NULL;
	state->index++;
}

static void	handle_quote(t_lexerstate *state, char quote)
{
	char	c;

	if (!state->current_token)
		state->current_token = create_token(state);
	state->current_token->type = TXT;
	push_char(state->current_token, quote, state);
	while (state->line[state->index++] != '\0')
	{
		c = state->line[state->index];
		if (c == '$' && is_valid(state->line[state->index + 1])
			&& quote != '\'')
		{
			handle_expansion(state);
			c = state->line[state->index];
		}
		if (c == quote)
		{
			push_char(state->current_token, c, state);
			state->index++;
			break ;
		}
		else
			push_char(state->current_token, c, state);
	}
}

static int	init_lexerstate(t_lexerstate *state, char *line)
{
	if (detect_early_errors(line) == 1)
		return (1);
	state->current_token = NULL;
	state->line = line;
	state->index = 0;
	state->table = create_token_table();
	if (!state->table)
		malloc_error("init table failed\n", state, NULL);
	return (0);
}

t_tokentab	*tokenize_line(char *line)
{
	t_lexerstate	state;
	char			c;

	if (init_lexerstate(&state, line))
		return (NULL);
	while (state.line[state.index] != '\0')
	{
		c = state.line[state.index];
		if ((c == ' ' || c == '\t'))
		{
			push_current_token(&state);
			state.index++;
		}
		else if (c == '$' && is_valid(state.line[state.index + 1]))
			handle_expansion(&state);
		else if (c == '\'' || c == '"')
			handle_quote(&state, c);
		else if (is_operator(c))
			handle_operator(&state, c);
		else
			other_cases(&state, c);
	}
	push_current_token(&state);
	return (state.table);
}
