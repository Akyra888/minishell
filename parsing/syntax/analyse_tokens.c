/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyra <kyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:24:28 by nicpinar          #+#    #+#             */
/*   Updated: 2025/01/28 20:54:09 by kyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	analyse_heredoc(t_tokentab *table, t_token **token,
	int i, t_parserstate *state)
{
	if (token[i]->type == HEREDOC)
	{
		if (i + 1 == table->size)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
			g_signbr = 2;
			return (1);
		}
		else if (token[i + 1]->type == REDAPP || token[i + 1]->type == REDIN
			|| token[i + 1]->type == REDOUT || token[i + 1]->type == HEREDOC)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
			ft_putstr_fd(token[i + 1]->str, 2);
			ft_putstr_fd("\n", 2);
			g_signbr = 2;
			return (1);
		}
		else if (token[i + 1]->type == DELIMITER
			|| token[i + 1]->type == DELIMITER_Q)
		{
			if (gen_heredoc_prompt(token[i], token[i + 1], state) == 1)
				return (1);
		}
	}
	return (0);
}

static int	analyse_pipe(t_tokentab *table, t_token **token, int i)
{
	if (token[i]->type == PIPE)
	{
		if (i == 0)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
			return (1);
		}
		else if (i + 1 < table->size)
		{
			if (token[i + 1]->type == PIPE)
			{
				ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
				return (1);
			}
		}
	}
	return (0);
}

static int	analyse_redirections(t_tokentab *table, t_token **token, int i)
{
	if (token[i]->type == REDIN || token[i]->type == REDOUT
		|| token[i]->type == REDAPP)
	{
		if (i + 1 == table->size)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
			return (1);
		}
		else if (token[i + 1]->type != FILENAME)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
			ft_putstr_fd(token[i + 1]->str, 2);
			return (1);
		}
	}
	return (0);
}

int	analyse_tokens(t_tokentab *table, t_parserstate *state)
{
	int				i;
	t_token			**token;

	i = 0;
	token = table->tokens;
	while (i < table->size)
	{
		if (analyse_redirections(table, token, i))
			return (1);
		if (analyse_pipe(table, token, i))
			return (1);
		if (analyse_heredoc(table, token, i, state))
			return (1);
		i++;
	}
	return (0);
}
