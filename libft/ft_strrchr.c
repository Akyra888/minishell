/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:57:40 by nicpinar          #+#    #+#             */
/*   Updated: 2023/10/30 15:53:43 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "abcdaefg";
	
	printf("\n%s\n", ft_strrchr(str, '\0'));
	printf("adress is %p\n\n", ft_strrchr(str, '\0'));
	printf("%s\n", strrchr(str, '\0'));
	printf("adress is %p\n\n", strrchr(str, '\0'));
}*/