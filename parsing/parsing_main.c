/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:12:45 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/27 19:25:54 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	init_parserstate(t_parserstate *state, char *line)
{
	state->current_token = NULL;
	state->line = line;
	state->index = 0;
	state->table = NULL;
	if (detect_early_errors(line) == 1)
		return (1);
	state->table = create_token_table();
	if (!state->table)
		malloc_error("init table failed\n", state, NULL);
	return (0);
}

static void	create_sections(t_parserstate *state, char *line)
{
	t_tokentab	*table;
	char		**sections;
	int			i;

	i = 0;
	sections = ft_split(line, '|');
	if (!sections)
		return ;
	while (sections[i])
	{
		if (init_parserstate(state, line))
			return ;
		state->line = sections[i];
		table = tokenizer(state);
		printf("\nsections[%d]\n", i);
		print_token_table(table);
		destroy_token_table(table);
		i++;
	}
}

void	parsing_main(char *line, char **envp)
{
	t_tokentab		*table;
	t_parserstate	state;

	(void)envp;
	if (init_parserstate(&state, line))
		return ;
	table = tokenizer(&state);
	printf("\nPRINT BEFORE SECTIONS\n");
	print_token_table(table);
	printf("\n");
	if (analyse_tokens(table, &state))
	{
		destroy_token_table(table);
		return ;
	}
	destroy_token_table(table);
	create_sections(&state, line);
}
