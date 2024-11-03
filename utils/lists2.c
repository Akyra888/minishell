/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:23 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/03 20:12:58 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_list(t_lists *l)
{
	t_node	*n;

	n = l->head;
	while (n != NULL)
	{
		printf("%s ", n->token);
		n = n->next;
	}
	printf("\n");
}

void	swap_nodes(t_lists *l, char *token1, char *token2)
{
	t_node	**curr;
	t_node	**curr1;
	t_node	*tmp;

	curr = (&(l->head));
	while (*curr && ft_strcmp((*curr)->token, token1) != 0)
		curr = (&(*curr)->next);
	curr1 = (&(l->head));
	while (*curr1 && ft_strcmp((*curr1)->token, token2) != 0)
		curr1 = (&(*curr1)->next);
	tmp = *curr;
	*curr = *curr1;
	*curr1 = tmp;
	tmp = (*curr)->next;
	(*curr)->next = (*curr1)->next;
	(*curr1)->next = tmp;
	if (!(*curr)->next)
		l->tail = *curr;
	if (!(*curr1)->next)
		l->tail = *curr1;
}
