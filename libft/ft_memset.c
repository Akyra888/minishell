/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:17:32 by nicpinar          #+#    #+#             */
/*   Updated: 2023/10/26 17:47:06 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}
/*
int	main(void)
{
	char	str[10];
	char	str1[10];
	printf("%s\n", memset(str, 'a', 9));
	printf("%s\n", ft_memset(str1, 'a', 9));
}*/