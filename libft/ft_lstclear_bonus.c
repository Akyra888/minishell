/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:47:07 by nicpinar          #+#    #+#             */
/*   Updated: 2024/02/25 16:57:34 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	display(t_list *list)
{
	printf("\n");
	while (list)
	{
		printf("%d -> ", *(int *)list->content);
		list = list->next;
	}
	printf("NULL\n\n");
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	else
	{
		list->content = content;
		list->next = NULL;
	}
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (*lst)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*lst = new;
}

void	ft_free(void *content)
{
	*(int *)content = 0;
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = next;
	}
}
/*
int	main(void)
{
	t_list	*list;

	int	a;
	int	b;
	int	c;

	int	*ptr;
	int	*ptr1;
	int	*ptr2;

	list = NULL;

	a = 1;
	b = 2;
	c = 3;

	ptr = &a;
	ptr1 = &b;
	ptr2 = &c;

	list = ft_lstnew(ptr);
	ft_lstadd_back(&list, ft_lstnew(ptr1));
	ft_lstadd_back(&list, ft_lstnew(ptr2));
	display(list);
	fflush(stdout);
	ft_lstclear(&list, &ft_free);
	display(list);
}*/