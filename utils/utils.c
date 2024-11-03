/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:10:03 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/03 15:07:24 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	*ft_error(char *str, t_parserstate *state, void **local)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	if (local && *local)
		free(*local);
	if (state->tokens)
		destroy_token_table(state->tokens);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL || src == NULL)
		return (NULL);
	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size,
	t_parserstate *state)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (!ptr)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (ft_error("Error: realloc 60\n", state, NULL));
		return (new_ptr);
	}
	if (new_size == 0)
		return (ft_error("Error: realloc 64\n", state, (void **)&ptr));
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (ft_error("Error: realloc 67\n", state, (void **)&ptr));
	if (old_size > new_size)
		old_size = new_size;
	if (!ft_memcpy(new_ptr, ptr, old_size))
	{
		free(new_ptr);
		return (ft_error("Error: realloc 73\n", state, (void **)&ptr));
	}
	free(ptr);
	return (new_ptr);
}
