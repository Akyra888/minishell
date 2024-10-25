/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:45:14 by nicpinar          #+#    #+#             */
/*   Updated: 2023/10/26 13:23:32 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	slen;
	unsigned int	dlen;

	i = 0;
	j = 0;
	slen = ft_strlen(src);
	while (dst[i] != '\0')
		i++;
	dlen = i;
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[j] != '\0' && (dlen + j) < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (slen + dlen);
}
/*
int	main(void)
{
	char	dest[10] = "0123456789";
	char	src[] = "abcd";

	printf("%lu\n", ft_strlcat(dest, src, 6));
	printf("%s\n\n", dest);
}*/