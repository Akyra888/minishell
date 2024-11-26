/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:12:45 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/26 18:37:57 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// static void	create_sections(char *line)
// {
// 	t_tokentab	*table;
// 	char		**sections;
// 	int			i;

// 	i = -1;
// 	sections = ft_split(line, '|');
// 	if (!sections)
// 		return ;
// 	while (sections[++i])
// 	{
// 		table = tokenizer(sections[i]);
// 		if (!table || table->tokens == NULL)
// 			return ;
// 		printf("\nsections[%d]\n", i);
// 		//fullfill_node
// 		print_token_table(table);
// 		destroy_token_table(table);
// 	}
// }

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

void	parsing_main(char *line, char **envp)
{
	t_tokentab		*table;
	t_parserstate	state;

	(void)envp;
	if (init_parserstate(&state, line))
		return ;
	table = tokenizer(&state);
	if (!table || table->tokens == NULL)
		return ;
	print_token_table(table);
	if (analyse_tokens(table, &state) == 0)
	{
		destroy_token_table(table);
		return ;
	}
	print_token_table(table);
	destroy_token_table(table);
}
