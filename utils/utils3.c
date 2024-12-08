/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:37:38 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/08 18:40:41 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void	free_sections(t_sections **sections)
{
	t_sections	*curr;
	t_sections	*next;

	if (!sections && !*sections)
		return ;
	curr = *sections;
	while (curr)
	{
		next = curr->next;
		free_strs(curr->args);
		free_strs(curr->redir);
		free_strs(curr->filename);
		free_strs(curr->heredoc);
		free(curr->pipe);
		free(curr);
		curr = next;
	}
	*sections = NULL;
}

int	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
	return (1);
}
