/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:42:00 by nicpinar          #+#    #+#             */
/*   Updated: 2023/10/23 15:53:22 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int		i;
	char	c;

	i = -1;
	c = 'z';
	printf("%d\n", ft_isprint(i));
	printf("%d\n", ft_isprint(c));
	printf("%d\n", isprint(i));
	printf("%d\n", isprint(c));
}*/
