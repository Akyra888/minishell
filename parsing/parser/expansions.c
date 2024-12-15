/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:05:36 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/15 12:42:14 by nicpinar         ###   ########.fr       */
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
	while (is_valid_exp(str[i++], 1))
		len++;
	var_name = (char *)malloc(sizeof(char) * (len + 1));
	if (!var_name)
		malloc_error("malloc failed at expansions.c 44", state, NULL);
	i = 0;
	while (is_valid_exp(str[state->index], 1))
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

static int	split_expansion(char **strs, t_parserstate *state)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strs_len(strs);
	if (!len || len == 1)
		return (0);
	while (strs[i])
	{
		if (i > 0)
			state->current_token = create_token(state);
		j = 0;
		while (strs[i][j])
		{
			push_char(state->current_token, strs[i][j], state);
			j++;
		}
		define_type(state, 0);
		if (i < len -1)
			push_token(state->table, state->current_token, state);
		i++;
	}
	return (1);
}

static int	check_split_expansion(char *expanded, t_parserstate *state)
{
	char	**strs;

	strs = ft_split(expanded, ' ');
	if (!strs)
		malloc_error("malloc failed at expansions.c 77", state, NULL);
	if (split_expansion(strs, state))
		return (1);
	free_strs(strs);
	return (0);
}

int	handle_expansion(t_parserstate *state, int quote)
{
	char	*expanded;
	int		i;

	i = 0;
	if (!state->current_token)
		state->current_token = create_token(state);
	define_type(state, 0);
	state->index++;
	expanded = ft_expand(state->line, state);
	if (!expanded)
		return (1);
	if (!quote)
	{
		if (check_split_expansion(expanded, state))
			return (1);
	}
	while (expanded[i])
	{
		push_char(state->current_token, expanded[i], state);
		i++;
	}
	return (0);
}
