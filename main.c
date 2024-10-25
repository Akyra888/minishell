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

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	(void)envp;
	ft_signal();
	while (1)
	{
		line = readline("minishell> ");
		if (line == NULL)
		{
			rl_clear_history();
			exit(0);
		}
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			rl_clear_history();
			exit(0);
		}
		if (*line != '\0')
		{
			add_history(line);
			parse_line(line);
		}
		free(line);
	}
	return (0);
}
