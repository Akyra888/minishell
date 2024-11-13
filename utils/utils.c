/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:10:03 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/13 20:56:23 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_valid(char c)
{
	if (isalpha(c) || c == 95)
		return (1);
	return (0);
}

int	is_next_valid(char c)
{
	if (ft_isalnum(c) || c == 95)
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	malloc_error(char *str, t_lexerstate *state, void **local)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	free(state->line);
	if (local && *local)
		free(*local);
	if (state->current_token)
		free(state->current_token);
	if (state->table)
		destroy_token_table(state->table);
	exit(EXIT_FAILURE);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size,
	t_lexerstate *state)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (!ptr)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			malloc_error("Error: realloc 61\n", state, NULL);
		return (new_ptr);
	}
	if (new_size == 0)
		malloc_error("Error: realloc 65\n", state, (void **)&ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		malloc_error("Error: realloc 68\n", state, (void **)&ptr);
	if (old_size > new_size)
		old_size = new_size;
	if (!ft_memcpy(new_ptr, ptr, old_size))
	{
		free(new_ptr);
		malloc_error("Error: realloc 74\n", state, (void **)&ptr);
	}
	free(ptr);
	return (new_ptr);
}
