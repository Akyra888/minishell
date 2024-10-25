/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:46:40 by nicpinar          #+#    #+#             */
/*   Updated: 2023/11/05 16:19:23 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	display(t_list *list)
{
	printf("\nlist is: ");
	while (list)
	{
		printf("%d->", *(int *)list->content);
		list = list->next;
	}
	printf("\n\n");
}*/

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
	display(list);
}*/