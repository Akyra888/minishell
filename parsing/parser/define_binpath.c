/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_binpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyra <kyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:09:47 by kyra              #+#    #+#             */
/*   Updated: 2025/01/26 20:27:26 by kyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_builtin(char *str)
{
	if (!ft_strcmp(str, "echo") || !ft_strcmp(str, "cd")
		|| !ft_strcmp(str, "pwd") || !ft_strcmp(str, "export")
		|| !ft_strcmp(str, "unset") || !ft_strcmp(str, "env")
		|| !ft_strcmp(str, "exit"))
		return (1);
	return (0);
}

static char	*extract_path(char **dict)
{
	int		i;
	char	*path;

	i = 0;
	if (!dict)
		return (NULL);
	path = NULL;
	while (dict[i])
	{
		if (ft_strnstr(dict[i], "PATH=", 5))
		{
			path = ft_strchr(dict[i], '=');
			path++;
			return (path);
		}
		i++;
	}
	return (NULL);
}

static char	*extract_binpath(char *str, char **dict)
{
	int		i;
	char	*path;
	char	**path_split;

	i = -1;
	path = extract_path(dict);
	if (!path)
		return (NULL);
	path_split = ft_split(path, ':');
	if (!path_split)
		malloc_error("path_split malloc failed\n", NULL, NULL);
	while (path_split[++i])
	{
		path = ft_strjoin(path_split[i], "/");
		if (!path)
			malloc_error("path malloc failed\n", NULL, (void**)path_split);
		path = ft_strjoin(path, str);
		if (!path)
			malloc_error("path malloc failed\n", NULL, (void**)path_split);
		if (access(path, X_OK) == 0)
		{
			free_strs(path_split);
			return (path);
		}
	}
	return (NULL);
}

void	define_binpath(t_sections **sections , char **dict)
{
	t_sections *current;

	if (!(*sections))
		return ;
	current = *sections;
	while (current)
	{
		if (!is_builtin(current->args[0]))
			current->binpath = extract_binpath(current->args[0], dict);			
		else
			current->binpath = ft_strdup("builtin");
		current = current->next;
	}
}
