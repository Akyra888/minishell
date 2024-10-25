/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:12:45 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/25 19:27:36 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_line(char *line)
{
	t_tokentab	*tokens;

	tokens = tokenize_line(line);
	if (!tokens)
		return ;
	print_token_table(tokens);
	destroy_token_table(tokens);
}
