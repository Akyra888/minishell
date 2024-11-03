/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tab_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:47:11 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/01 19:47:11 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_tokentab	*create_token_table(void)
{
	t_tokentab	*table;

	table = malloc(sizeof(t_tokentab));
	if (!table)
		return (ft_error("Error : malloc failed in create_token_table",
				NULL, NULL));
	table->mem_size = 16;
	table->tokens = malloc(sizeof(t_token *) * table->mem_size);
	if (!table->tokens)
	{
		free(table->tokens);
		return (ft_error("Error realloc in create_token_table", NULL, NULL));
	}
	table->size = 0;
	return (table);
}

void	*push_token(t_tokentab *table, t_token *tok, t_parserstate *state)
{
	size_t	old_size;

	if (table->size >= table->mem_size)
	{
		old_size = sizeof(t_token *) * table->mem_size;
		table->mem_size *= 2;
		table->tokens = ft_realloc(table->tokens, old_size,
				sizeof(t_token *) * table->mem_size, state);
		if (!table->tokens)
			return (NULL);
	}
	table->tokens[table->size] = tok;
	table->size++;
	return (state);
}

void	destroy_token_table(t_tokentab *table)
{
	int	i;

	i = -1;
	if (table)
	{
		while (++i < table->size)
		{
			if (table->tokens[i])
				destroy_token(table->tokens[i]);
		}
		if (table->tokens)
			free(table->tokens);
		free(table);
	}
}
