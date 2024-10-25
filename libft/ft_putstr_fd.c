/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:23:13 by nicpinar          #+#    #+#             */
/*   Updated: 2023/11/05 14:33:25 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd("0123456789",fd);
	close(fd);
	return (0);
}*/