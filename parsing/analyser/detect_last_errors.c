/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_last_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:24:28 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/26 19:48:51 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	analyse_heredoc(t_tokentab *table, t_token **token,
	int i, t_parserstate *state)
{
	if (token[i]->type == HEREDOC)
	{
		if (i + 1 == table->size)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);
		}
		else if (token[i + 1]->type == REDAPP || token[i + 1]->type == REDIN
			|| token[i + 1]->type == REDOUT || token[i + 1]->type == HEREDOC)
		{		
			printf("minishell: syntax error near unexpected token `%s'\n",
				token[i + 1]->str);
			return (0);
		}
		else if (token[i + 1]->type == DELIMITER
			|| token[i + 1]->type == DELIMITER_Q)
			gen_heredoc_prompt(token[i], token[i + 1], state);
	}
	return (1);
}

static int	analyse_pipe(t_token **token, int i)
{
	if (token[i]->type == PIPE)
	{
		if (token[i + 1]->type == PIPE)
		{
			printf("minishell: syntax error near unexpected token `|'\n");
			return (0);
		}
	}
	return (1);
}

static int	analyse_redirections(t_tokentab *table, t_token **token, int i)
{
	if (token[i]->type == REDIN || token[i]->type == REDOUT
		|| token[i]->type == REDAPP)
	{
		if (i + 1 == table->size)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);
		}
		else if (token[i + 1]->type != FILENAME)
		{		
			printf("minishell: syntax error near unexpected token `%s'\n",
				token[i + 1]->str);
			return (0);
		}
	}
	return (1);
}

int	analyse_tokens(t_tokentab *table, t_parserstate *state)
{
	int				i;
	t_token			**token;

	i = 0;
	token = table->tokens;
	if (token[0]->str[0] == '\0')
		return (0);
	if (token[0]->type == PIPE)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	while (i < table->size)
	{
		if (!analyse_redirections(table, token, i))
			return (0);
		if (!analyse_pipe(token, i))
			return (0);
		if (!analyse_heredoc(table, token, i, state))
			return (0);
		i++;
	}
	return (1);
}
