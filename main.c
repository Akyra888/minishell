/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:06:04 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/01 19:06:04 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	exit_shell(char *line)
{
	if (line)
		free(line);
	rl_clear_history();
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	ft_signal();
	while (1)
	{
		line = readline("minishell> ");
		if (line == NULL)
			exit_shell(NULL);
		if (ft_strcmp(line, "exit") == 0)
			exit_shell(line);
		if (*line != '\0')
		{
			add_history(line);
			parse_line(line, envp);
		}
		free(line);
	}
	return (0);
}
