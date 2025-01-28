/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:57:50 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/01 19:57:50 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*create_token(t_parserstate *state)
{
	t_token	*t;

	t = malloc(sizeof(t_token));
	if (!t)
		malloc_error("Error malloc for t in create_token",
			state, NULL);
	t->mem_size = 16;
	t->type = UNKNOWN;
	t->str = malloc(sizeof(char) * t->mem_size);
	if (!t->str)
		malloc_error("Error malloc for t->str in create_token",
			state, (void **)&t);
	t->size = 0;
	t->str[0] = '\0';
	t->expanded_split = NULL;
	return (t);
}

void	destroy_token(t_token *t)
{
	if (t)
	{
		if (t->str)
			free(t->str);
		free(t);
	}
}

void	push_char(t_token *t, char c, t_parserstate *state)
{
	size_t	old_size;

	if (t->size + 1 >= t->mem_size)
	{
		old_size = t->mem_size;
		t->mem_size *= 2;
		t->str = ft_realloc(t->str, old_size, t->mem_size, state);
	}
	t->str[t->size] = c;
	t->size++;
	t->str[t->size] = '\0';
}
