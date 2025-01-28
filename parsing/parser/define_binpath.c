/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_binpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyra <kyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:09:47 by kyra              #+#    #+#             */
/*   Updated: 2025/01/27 20:29:04 by kyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	verify_binpath(char *bin_path, t_sections *curr, char **path_split)
{
	if (access(bin_path, X_OK) == 0)
	{
		curr->binpath = bin_path;
		free_strs(path_split);
		return (1);
	}
	free(bin_path);
	return (0);
}

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

static void extract_binpath(t_sections **sections, t_sections *curr, char **dict)
{
	int		i;
	char	*path;
	char	*bin_path;
	char	**path_split;

	i = -1;
	path = extract_path(dict);
	if (!path)
		return ;
	path_split = ft_split(path, ':');
	if (!path_split)
		malloc_error2("path_split malloc failed\n", NULL, sections, dict);
	while (path_split[++i])
	{
		path = ft_strjoin(path_split[i], "/");
		if (!path)
			malloc_error2("path malloc failed\n", path_split, sections, dict);
		bin_path = ft_strjoin(path, curr->args[0]);
		free(path);
		if (!bin_path)
			malloc_error2("path malloc failed\n", path_split, sections, dict);
		if (verify_binpath(bin_path, curr, path_split))
			return ;
	}
	free_strs(path_split);
}

void	define_binpath(t_sections **sections , char **envp)
{
	t_sections *current;
	char		**dict;

	if (!(*sections))
		return ;
	current = *sections;
	dict = get_dict(envp);
	while (current)
	{
		if (current->args)
		{
			if (!is_builtin(current->args[0]))
				extract_binpath(sections, current, dict);			
			else
				current->binpath = ft_strdup("builtin");
		}
		current = current->next;
	}
	free_strs(dict);
}
