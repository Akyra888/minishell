/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:37:38 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/13 19:37:20 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strs_len(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return (0);
	while (strs[i] != NULL)
		i++;
	return (i);
}

char	**add_to_array(char **array, char *str)
{
	int		i;
	char	**new;

	i = 0;
	if (!str)
		return (NULL);
	while (array && array[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (array && array[i])
	{
		new[i] = array[i];
		i++;
	}
	new[i] = ft_strdup(str);
	if (!new[i])
		return (free_strs(new), NULL);
	if (array)
		free(array);
	new[i + 1] = NULL;
	return (new);
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
			malloc_error("Error: realloc 63\n", state, NULL);
		return (new_ptr);
	}
	if (new_size == 0)
		malloc_error("Error: realloc 67\n", state, (void **)&ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		malloc_error("Error: realloc 70\n", state, (void **)&ptr);
	if (old_size > new_size)
		old_size = new_size;
	if (!ft_memcpy(new_ptr, ptr, old_size))
	{
		free(new_ptr);
		malloc_error("Error: realloc 76\n", state, (void **)&ptr);
	}
	free(ptr);
	return (new_ptr);
}
