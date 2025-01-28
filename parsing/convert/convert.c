/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyra <kyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:59:36 by nicpinar          #+#    #+#             */
/*   Updated: 2025/01/27 17:50:40 by kyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	fill_sections(t_sections *curr, t_token *tok)
{
	if (tok->type == ARG || tok->type == COMMAND)
	{
		curr->args = add_to_array(curr->args, tok->str);
		if (!curr->args)
			return (1);
	}
	else if (tok->type == REDIN || tok->type == REDOUT || tok->type == REDAPP)
	{
		curr->redir = add_to_array(curr->redir, tok->str);
		if (!curr->redir)
			return (1);
	}
	else if (tok->type == FILENAME)
	{
		curr->filename = add_to_array(curr->filename, tok->str);
		if (!curr->filename)
			return (1);
	}
	else if (tok->type == HEREDOC)
	{
		curr->heredoc = add_to_array(curr->heredoc, tok->str);
		if (!curr->heredoc)
			return (1);
	}
	return (0);
}

static int	handle_pipe(t_sections *curr, t_sections **sections)
{
	curr->pipe = ft_strdup("|");
	if (!(curr->pipe))
	{
		free_sections(sections);
		return (1);
	}
	return (0);
}

static t_sections	*alloc_node(t_sections **sections)
{
	t_sections	*node;

	node = NULL;
	node = (t_sections *)malloc(sizeof(t_sections));
	if (!node)
		free_sections(sections);
	else
	{
		node->args = NULL;
		node->binpath = NULL;
		node->redir = NULL;
		node->filename = NULL;
		node->heredoc = NULL;
		node->pipe = NULL;
		node->next = NULL;
	}
	return (node);
}

static int	alloc_and_update(t_sections **sections, t_sections **curr)
{
	t_sections	*new;

	new = alloc_node(sections);
	if (!new)
		return (1);
	if (*sections == NULL)
		*sections = new;
	else
		(*curr)->next = new;
	*curr = new;
	return (0);
}

int	convert_to_list(t_sections **sections, t_tokentab *table)
{
	t_sections	*curr;
	t_token		*token;
	int			i;

	i = -1;
	curr = NULL;
	while (++i < table->size)
	{
		token = table->tokens[i];
		if (token->type == PIPE || curr == NULL)
		{
			if (token->type == PIPE && i == table->size - 1)
			{
				if (handle_pipe(curr, sections))
					return (free_sections(sections), 1);
			}
			else if (alloc_and_update(sections, &curr))
				return (free_sections(sections), 1);
		}
		if (fill_sections(curr, token))
			return (free_sections(sections), 1);
	}
	return (0);
}
