/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:05:36 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/13 21:25:04 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	define_type(t_lexerstate *state, char c, char next)
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
			state->current_token->type = REDAPPEND;
		else
			state->current_token->type = REDOUT;
	}
}

char	*ft_expand(char *str, t_lexerstate *state)
{
	char	*var_name;
	char	*expanded;
	int		len;
	int		i;

	len = 0;
	i = state->index;
	while (is_next_valid(str[i++]))
		len++;
	var_name = (char *)malloc(sizeof(char) * (len + 1));
	if (!var_name)
		malloc_error("malloc failed ft_expand 32", state, NULL);
	i = 0;
	while (is_next_valid(str[state->index]))
	{
		var_name[i] = str[state->index];
		i++;
		state->index++;
	}
	var_name[i] = '\0';
	expanded = getenv(var_name);
	free(var_name);
	return (expanded);
}

void	other_cases(t_lexerstate *state, char c)
{
	if (!state->current_token)
		state->current_token = create_token(state);
	state->current_token->type = COMMAND;
	push_char(state->current_token, c, state);
	state->index++;
}

void	handle_expansion(t_lexerstate *state)
{
	char	*expanded;
	int		i;

	i = 0;
	if (!state->current_token)
		state->current_token = create_token(state);
	state->index++;
	expanded = ft_expand(state->line, state);
	if (expanded)
	{
		while (expanded[i])
		{
			push_char(state->current_token, expanded[i], state);
			i++;
		}
	}
}
