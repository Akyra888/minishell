/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyra <kyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:12:45 by nicpinar          #+#    #+#             */
/*   Updated: 2025/01/26 20:29:39 by kyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	init_parserstate(t_parserstate *state, char *line)
{
	state->current_token = NULL;
	state->line = line;
	state->index = 0;
	state->table = create_token_table();
	if (!state->table)
		malloc_error("init table failed\n", state, NULL);
	return (0);
}

t_sections	*parsing_main(char *line, char **dict)
{
	t_tokentab		*table;
	t_parserstate	state;
	t_sections		*sections;

	sections = NULL;
	if (analyse_line(line) || init_parserstate(&state, line))
		return (NULL);
	table = tokenizer(&state);
	if (analyse_tokens(table, &state))
	{
		destroy_token_table(table);
		return (NULL);
	}
	print_token_table(table);
	convert_to_list(&sections, table);
	destroy_token_table(table);
	define_binpath(&sections, dict);
	print_sections(sections);
	return (sections);
}
