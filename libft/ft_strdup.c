/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:00:48 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/15 21:08:18 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;
	char	*begin;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	begin = str;
	if (!begin)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main(void) 
{
    char	str[] = "0123456789";
    char	str1[] = "0123456789";

	printf("%s\n", ft_strdup(str));
	printf("%s\n", strdup(str1));
}*/
