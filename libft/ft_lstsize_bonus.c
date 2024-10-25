/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:46:40 by nicpinar          #+#    #+#             */
/*   Updated: 2023/11/05 16:31:08 by nicpinar         ###   ########.fr       */
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (*lst)
	{
		node = new;
		node->next = *lst;
		*lst = node;
	}
	else
		*lst = new;
}
*/
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (lst)
	{	
		size++;
		while (lst->next)
		{
			lst = lst->next;
			size++;
		}
	}
	return (size);
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
	ft_lstadd_front(&list, ft_lstnew(ptr1));
	ft_lstadd_front(&list, ft_lstnew(ptr2));
	display(list);
	printf("size is %d\n", ft_lstsize(list));
}*/