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

volatile sig_atomic_t	g_signbr = 0;

void	exit_shell(char *line)
{
	if (line)
		free(line);
	rl_clear_history();
	exit(0);
}

char	*ft_readline(int type)
{
	char	*line;

	if (type == 0)
		line = readline("minishell> ");
	else
		line = readline("> ");
	if (g_signbr == SIGINT)
	{
		g_signbr = SIGINT + 128;
		if (type == 1)
			return (NULL);
	}
	if (g_signbr == SIGQUIT)
	{
		g_signbr = SIGQUIT + 128;
		if (type == 2)
			return (NULL);
	}
	return (line);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_sections	*sections;

	(void)argc;
	(void)argv;
	setup_signals();
	while (1)
	{
		line = ft_readline(0);
		if (line == NULL)
			exit_shell(NULL);
		if (ft_strcmp(line, "exit") == 0)
			exit_shell(line);
		if (*line != '\0')
		{
			add_history(line);
			sections = parsing_main(&line, envp);
			free_sections(&sections);
		}
		if (line)
			free(line);
	}
	return (0);
}
