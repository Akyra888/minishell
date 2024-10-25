/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:35:44 by nicpinar          #+#    #+#             */
/*   Updated: 2023/11/05 14:39:53 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putendl_fd("0123456789",fd);
	close(fd);
	return (0);
}*/