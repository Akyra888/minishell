/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:37:44 by nicpinar          #+#    #+#             */
/*   Updated: 2023/12/02 15:31:02 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c %= 256;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "teste";
	char	str1[] = "teste";
	
	printf("%s \n", ft_strchr(str, 's' + 256));
	printf("%s \n", strchr(str1, 's' + 256));
}
*/