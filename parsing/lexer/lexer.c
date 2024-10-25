/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:54:21 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/25 19:47:36 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//traite les cas suivants : < > >> << | et les transforme en tokens
static void	unquoted_operator(t_parserstate *state, char operator_char)
{
	t_token	*operator_token;
	char	next_char;

	operator_token = create_token();
	next_char = state->line[state->index + 1];
	if (is_operator(operator_char))
	{
		if ((operator_char == '>' && next_char == '>')
			|| (operator_char == '<' && next_char == '<'))
		{
			push_char(operator_token, operator_char);
			operator_char = state->line[++state->index];
		}
	}
	if (state->current_token)
	{
		push_token(state->tokens, state->current_token);
		state->current_token = NULL;
	}
	push_char(operator_token, operator_char);
	push_token(state->tokens, operator_token);
}

//traite les espaces et les tabulations et les transforme en tokens
static void	spaces_tab(t_parserstate *state, char c)
{
	if (state->current_token)
	{
		push_token(state->tokens, state->current_token);
		state->current_token = NULL;
	}
	if (is_operator(c))
		unquoted_operator(state, c);
	state->index++;
}

//traite les quotes et les transforme en tokens
static void	handle_quote(t_parserstate *state, char quote_char)
{
	char	c;

	state->index++;
	if (!state->current_token)
		state->current_token = create_token();
	if (quote_char == '\'')
		state->current_token->quote = SQUOTE;
	else
		state->current_token->quote = DQUOTE;
	while (state->line[state->index] != '\0')
	{
		c = state->line[state->index];
		if (c == quote_char)
		{
			state->index++;
			break ;
		}
		else
		{
			push_char(state->current_token, c);
			state->index++;
		}
	}
}

static void	init_parser_state(t_parserstate *state, char *line)
{
	detect_early_errors(line);
	state->tokens = create_token_table();
	state->current_token = NULL;
	state->line = line;
	state->index = 0;
}

t_tokentab	*tokenize_line(char *line)
{
	t_parserstate	state;
	char			c;

	init_parser_state(&state, line);
	while (state.line[state.index] != '\0')
	{
		c = state.line[state.index];
		if ((c == ' ' || c == '\t') || (is_operator(c)))
			spaces_tab(&state, c);
		else if (c == '\'' || c == '"')
			handle_quote(&state, c);
		else
		{
			if (!state.current_token)
				state.current_token = create_token();
			push_char(state.current_token, c);
			state.index++;
		}
	}
	if (state.current_token)
	{
		push_token(state.tokens, state.current_token);
		state.current_token = NULL;
	}
	return (state.tokens);
}
