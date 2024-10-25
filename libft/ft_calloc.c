/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:00:48 by nicpinar          #+#    #+#             */
/*   Updated: 2023/12/02 15:42:27 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
/*
int main(void) 
{
	int n;
    int *tab;
    
	n = 5;
    tab = (int*)ft_calloc(n, sizeof(int));
    if (tab == NULL) 
	{
        printf("Échec de l'allocation mémoire.\n");
        return (1);
    }
    for (int i = 0; i < n; i++) 
        printf("%d ", tab[i]);
    free(tab);
    return (0);
}
*/