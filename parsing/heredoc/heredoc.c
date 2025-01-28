/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyra <kyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:44:10 by nicpinar          #+#    #+#             */
/*   Updated: 2025/01/27 19:09:19 by kyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	recreate_token(t_token *token, t_parserstate *state)
{
	free(token->str);
	token->mem_size = 16;
	token->size = 0;
	token->str = (char *)malloc(sizeof(char) * token->mem_size);
	if (!token->str)
		malloc_error("Malloc failed at detect last error 22\n", state, NULL);
	token->str[0] = '\0';
}

static void	handle_exp_here(t_token *token, char *here_line,
	t_parserstate *state)
{
	char	*expanded;
	int		i;

	state->index++;
	expanded = ft_expand(here_line, state);
	i = 0;
	if (!expanded)
		return ;
	while (expanded[i])
	{
		push_char(token, expanded[i], state);
		i++;
	}
}

void	fill_token_with_prompt(char *here_line, t_token *token, t_token *del,
	t_parserstate *state)
{
	while (here_line[state->index] != '\0')
	{
		if (here_line[state->index] == '$' && is_valid_exp
			(here_line[state->index + 1], 0) && del->type == DELIMITER)
			handle_exp_here(token, here_line, state);
		else
		{
			push_char(token, here_line[state->index], state);
			state->index++;
		}
	}	
}

int	gen_heredoc_prompt(t_token *token, t_token *del, t_parserstate *state)
{
	char	*here_line;

	recreate_token(token, state);
	setup_heredoc_signals();
	rl_event_hook = do_nothing;
	while (1)
	{
		here_line = ft_readline(1);
		if (here_line == NULL)
			return (1);
		state->index = 0;
		if (token->str[0] != '\0' && (ft_strcmp(here_line, del->str) != 0))
			push_char(token, '\n', state);
		if (ft_strcmp(here_line, del->str) == 0)
		{
			free(here_line);
			return (0);
		}
		fill_token_with_prompt(here_line, token, del, state);
		free(here_line);
	}
	return (0);
}
