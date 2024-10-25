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

t_token	*create_token(void)
{
	t_token	*t;

	t = malloc(sizeof(t_token));
	if (!t)
	{
		printf("Error malloc for t in createToken");
		return (NULL);
	}
	t->mem_size = 16;
	t->str = malloc(sizeof(char) * t->mem_size);
	if (!t->str)
	{
		printf("Error malloc for t->str in createToken");
		free(t);
		return (NULL);
	}
	t->size = 0;
	t->str[0] = '\0';
	t->type = CMD;
	t->quote = NONE;
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

void	push_char(t_token *t, char c)
{
	size_t	old_size;

	if (t->size + 1 >= t->mem_size)
	{
		old_size = t->mem_size;
		t->mem_size *= 2;
		t->str = ft_realloc(t->str, old_size, t->mem_size);
		if (!t->str)
		{
			printf("Error realloc in push_char");
			return ;
		}
	}
	t->str[t->size] = c;
	t->size++;
	t->str[t->size] = '\0';
}
