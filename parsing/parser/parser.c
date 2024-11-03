/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:12:45 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/03 15:35:20 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_line(char *line, char **envp)
{
	t_tokentab	*tokens;

	(void)envp;
	tokens = tokenize_line(line);
	if (!tokens)
		return ;
	print_token_table(tokens);
	destroy_token_table(tokens);
}
