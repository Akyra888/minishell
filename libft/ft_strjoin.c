/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:06:59 by nicpinar          #+#    #+#             */
/*   Updated: 2023/11/01 16:47:18 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*result;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	char	str[] = "hello";
	char	str1[] = "42 how are you";

	printf("%s\n", ft_strjoin(str, str1));
}*/