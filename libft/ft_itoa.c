/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:59:16 by nicpinar          #+#    #+#             */
/*   Updated: 2023/11/04 23:32:30 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

static char	*ft_sign_case(char *result, long nb, int og_len, int sign)
{
	if (sign)
		result[1] = nb + 48;
	else
		result[0] = nb + 48;
	result[og_len] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		og_len;
	int		len;
	int		sign;
	char	*result;

	nb = n;
	og_len = ft_len(nb);
	len = og_len - 1;
	sign = 0;
	result = (char *)malloc(sizeof(char) * (og_len + 1));
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
		sign++;
	}
	while (nb > 9)
	{
		result[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (ft_sign_case(result, nb, og_len, sign));
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-144));
}*/