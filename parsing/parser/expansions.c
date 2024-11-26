/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:05:36 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/26 20:18:24 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_expand(char *str, t_parserstate *state)
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
		malloc_error("malloc failed at expansions.c 44", state, NULL);
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

void	handle_expansion(t_parserstate *state)
{
	char	*expanded;
	int		i;

	i = 0;
	if (!state->current_token)
		state->current_token = create_token(state);
	define_type(state, 0);
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
