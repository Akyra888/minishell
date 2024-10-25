/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:23 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/21 17:26:36 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_list(t_lists *l)
{
	t_node	*n;

	n = l->head;
	while (n != NULL)
	{
		printf("#%s# ", n->token);
		n = n->next;
	}
	printf("\n");
}

void	find_nodes(t_lists *l, char *token1, char *token2, t_node **curr1, t_node **curr2)
{
	t_node	*prev1;
	t_node	*prev2;

	prev1 = NULL;
	prev2 = NULL;
	*curr1 = l->head;
	*curr2 = l->head;
	while (*curr1 && (*curr1)->token != token1)
	{
		prev1 = *curr1;
		*curr1 = (*curr1)->next;
	}
	while (*curr2 && (*curr2)->token != token2)
	{
		prev2 = *curr2;
		*curr2 = (*curr2)->next;
	}
	if (prev1)
		prev1->next = *curr2;
	else
		l->head = *curr2;
	if (prev2)
		prev2->next = *curr1;
	else
		l->head = *curr1;
}

void	swap_pointers(t_lists *l, t_node *curr1, t_node *curr2)
{
	t_node	*temp;

	temp = curr1->next;
	curr1->next = curr2->next;
	curr2->next = temp;
	if (!curr1->next)
		l->tail = curr1;
	if (!curr2->next)
		l->tail = curr2;
}

void	swap_nodes(t_lists *l, char *token1, char *token2)
{
	t_node	*curr1;
	t_node	*curr2;

	curr1 = NULL;
	curr2 = NULL;
	find_nodes(l, token1, token2, &curr1, &curr2);
	if (!curr1 || !curr2)
	{
		printf("One token doesn't exist.\n");
		return (0);
	}
	swap_pointers(l, curr1, curr2);
}
