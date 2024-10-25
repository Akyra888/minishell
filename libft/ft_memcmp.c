/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:56:39 by nicpinar          #+#    #+#             */
/*   Updated: 2023/10/27 21:57:22 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;

	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	while (n--)
	{
		if (*str == *str1)
		{
			str++;
			str1++;
		}
		else
			return (*str - *str1);
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "abcdef6";
	char	str1[] = "abcdef5";
	char	str2[] = "abcdef6";
	char	str3[] = "abcdef5";

	printf("%d\n", ft_memcmp(str, str1, 8));
	printf("%d\n", memcmp(str2, str3, 8));
}*/