/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:12:45 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/11 13:37:15 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	init_parserstate(t_parserstate *state, char *line)
{
	state->current_token = NULL;
	state->line = line;
	state->index = 0;
	state->table = NULL;
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
	//detecter les premiers erreurs et initialiser le parserstate
	if (detect_early_errors(line) || init_parserstate(&state, line))
		return (NULL);
	//transformer la ligne en tokens
	table = tokenizer(&state);
	//analyser les tokens pour detecter les erreurs
	if (analyse_tokens(table, &state))
	{
		destroy_token_table(table);
		return (NULL);
	}
	//imprimer les tokens
	print_token_table(table);
	//convertir les tokens en liste chainee
	//il ya une fonctions a linterieur pour l'imprimer commente la si tu veux pas la voir
	//elle est en bas de convert list elle s'appelle print_sections
	convert_to_list(&sections, table);
	//detruire la table de tokens
	destroy_token_table(table);
	//appelles la fonction free_sections (dans le main apres lexec) pour liberer la memoire de la listes sinon leaks.
	//return la liste chainee
	return (sections);
}
