/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:46:10 by nicpinar          #+#    #+#             */
/*   Updated: 2023/10/26 17:46:21 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}

/*
int	main(void)
{
	int	i;
	char	str[10];
	char	str1[10];

	bzero(str, 10);
	ft_bzero(str1, 10);

	for (i = 0; i < 10; i++) 
	{
    	if (str[i] != 0)
        	printf("Erreur avec bzero à l'index %d\n", i);
    	if (str1[i] != 0) 
        	printf("Erreur avec ft_bzero à l'index %d\n", i);
	}
	return (0); // N'oubliez pas de retourner une valeur depuis main.
}*/