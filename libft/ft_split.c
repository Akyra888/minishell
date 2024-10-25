/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:06:59 by nicpinar          #+#    #+#             */
/*   Updated: 2023/11/04 22:30:31 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_next_sep(const char *s, char c)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*ft_str(const char *s, char c)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_next_sep(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s && *s != c)
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_free(char **split, unsigned int *i)
{
	unsigned int	j;

	j = *i;
	while (j > 0)
		free(split[--j]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**split;
	char			*temp;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count_str(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			temp = ft_str(s, c);
			if (!temp)
				return (ft_free(split, &i));
			split[i++] = temp;
			s += ft_strlen(temp);
		}
	}
	split[i] = NULL;
	return (split);
}
/*
int	main(void)
{
	unsigned int	i;
	char	**split;

	i = 0;
	split = ft_split("hello 42 how are you" , ' ');
	while (split[i] != NULL)
	{
		printf("%s\n", split[i]);
		i++;
	}
	free(split);
}*/