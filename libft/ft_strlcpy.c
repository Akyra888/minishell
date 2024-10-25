/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:41:18 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/10 20:39:09 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;

	i = 0;
	while (src[i] != '\0')
		i++;
	slen = i;
	if (size == 0)
		return (slen);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
/*
int	main(void)
{
	char	dest[10];
	char	src[] = "0123456789";
	char	dest1[10];
	char	src1[] = "0123456789";
	
	printf("%lu\n", ft_strlcpy(dest, src, 10));
	printf("%s\n", dest);
	printf("%lu\n", strlcpy(dest1, src1, 10));
	printf("%s\n", dest1);
}*/