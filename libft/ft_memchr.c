/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:18:54 by nicpinar          #+#    #+#             */
/*   Updated: 2023/10/28 20:25:37 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "abcdefg";
	char	str1[] = "abcdefg";

	printf("%s\n", ft_memchr(str, 'c', 2));
	printf("%s\n", memchr(str1, 'c', 2));
}*/