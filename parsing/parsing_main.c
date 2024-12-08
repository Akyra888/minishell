/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:12:45 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/08 17:50:41 by nicpinar         ###   ########.fr       */
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

t_sections	*parsing_main(char *line, char **envp)
{
	t_tokentab		*table;
	t_parserstate	state;
	t_sections		*sections;

	(void)envp;
	sections = NULL;
	if (init_parserstate(&state, line))
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
	return (NULL);
}
