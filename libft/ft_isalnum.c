/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:12:48 by nicpinar          #+#    #+#             */
/*   Updated: 2023/10/25 17:43:36 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) == 1 || ft_isalpha(c) == 1)
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

	i = 1;
	c = 'c';
	printf("%d\n", ft_isalnum(i));
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", isalnum(i));
	printf("%d\n", isalnum(c));
}*/
