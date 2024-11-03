/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:54:21 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/03 15:02:16 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	*unquoted_operator(t_parserstate *state, char operator_char)
{
	t_token	*operator_token;
	char	next_char;

	operator_token = create_token(state);
	next_char = state->line[state->index + 1];
	if ((operator_char == '>' && next_char == '>')
		|| (operator_char == '<' && next_char == '<'))
	{
		if (!push_char(operator_token, operator_char, state))
			return (NULL);
		operator_char = state->line[++state->index];
	}
	if (state->current_token)
	{
		if (!push_token(state->tokens, state->current_token, state))
			return (NULL);
		state->current_token = NULL;
	}
	if (!push_char(operator_token, operator_char, state))
		return (NULL);
	if (push_token(state->tokens, operator_token, state))
		return (NULL);
	return (state);
}

static void	*spaces_tab(t_parserstate *state, char c)
{
	if (state->current_token)
	{
		if (!push_token(state->tokens, state->current_token, state))
			return (NULL);
		state->current_token = NULL;
	}
	if (is_operator(c))
		unquoted_operator(state, c);
	state->index++;
	return (state);
}

static void	*handle_quote(t_parserstate *state, char quote_char)
{
	char	c;

	if (!state->current_token)
		state->current_token = create_token(state);
	if (!state->current_token)
		return (NULL);
	state->current_token->quote = DQUOTE;
	if (quote_char == '\'')
		state->current_token->quote = SQUOTE;
	while (state->line[state->index++] != '\0')
	{
		c = state->line[state->index];
		if (c == quote_char)
		{
			state->index++;
			break ;
		}
		else
		{
			if (push_char(state->current_token, c, state) == NULL)
				return (NULL);
		}
	}
	return (state);
}

static int	init_parser_state(t_parserstate *state, char *line)
{
	if (detect_early_errors(line) == 1)
		return (1);
	state->current_token = NULL;
	state->line = line;
	state->index = 0;
	state->tokens = create_token_table();
	if (!state->tokens)
		return (1);
	return (0);
}

t_tokentab	*tokenize_line(char *line)
{
	t_parserstate	state;
	char			c;

	if (init_parser_state(&state, line))
		return (NULL);
	while (state.line[state.index] != '\0')
	{
		c = state.line[state.index];
		if ((c == ' ' || c == '\t') || (is_operator(c)))
		{
			if (!spaces_tab(&state, c))
				return (NULL);
		}
		else if (c == '\'' || c == '"')
		{
			if (!handle_quote(&state, c))
				return (NULL);
		}
		else
			if (!other_cases(&state, c))
				return (NULL);
	}
	return (last_token_push(&state));
}
