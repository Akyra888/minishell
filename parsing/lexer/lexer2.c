/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:05:36 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/03 14:05:16 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*other_cases(t_parserstate *state, char c)
{
	if (!state->current_token)
		state->current_token = create_token(state);
	if (!state->current_token)
		return (NULL);
	if (!push_char(state->current_token, c, state))
		return (NULL);
	state->index++;
	return (state);
}

void	*last_token_push(t_parserstate *state)
{
	if (state->current_token)
	{
		if (!push_token(state->tokens, state->current_token, state))
			return (ft_error("Error: push_token failed in last_token_push\n",
					state, NULL));
		state->current_token = NULL;
	}
	return (state->tokens);
}
