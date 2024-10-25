/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:33:10 by nicpinar          #+#    #+#             */
/*   Updated: 2023/10/23 15:41:00 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	printf("%d\n", ft_isascii(i));
	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(i));
	printf("%d\n", isascii(c));
}*/
