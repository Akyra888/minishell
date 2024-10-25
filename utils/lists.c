/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:30:00 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/21 18:52:07 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_lists	*list_create(void)
{
	t_lists	*l;

	l = (t_lists *)malloc(sizeof(t_lists));
	if (!l)
		return (NULL);
	(*l).tail = NULL;
	l->head = NULL;
	l->len = 0;
	return (l);
}

void	push_head(t_lists *l, char *token)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->token = token;
	if (l->len > 0)
	{
		node->next = l->head;
		l->head = node;
	}
	else
	{
		node->next = NULL;
		l->head = node;
		l->tail = node;
	}
	l->len++;
}

void	lstadd_tail(t_lists *l, char *token)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->token = token;
	if (l->len > 0)
	{
		l->tail->next = node;
		l->tail = node;
	}
	else
		l->head = node;
	l->tail = node;
	node->next = NULL;
	l->len++;
}

t_node	*lstdel_head(t_lists *l)
{
	t_node	*head;

	head = l->head;
	if (l->len > 0)
	{
		l->head = l->head->next;
		l->len--;
	}
	else
		return (NULL);
	return (head);
}

int	main(int argc, char **argv)
{
	t_lists	*l;

	l = create_list();
	push_head(l, argv[1]);
	lstadd_tail(l, argv[2]);
	lstadd_tail(l, argv[3]);
	lstadd_tail(l, argv[4]);
	print_lists(l);
	swap_nodes(l, argv[1], argv[4]);
	print_lists(l);
	swap_nodes(l, argv[2], argv[3]);
	print_lists(l);
	return (0);
}
