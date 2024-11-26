/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:40:01 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/23 22:49:40 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_token_table(t_tokentab *table)
{
	int	i;

	i = -1;
	if (table == NULL)
		return ;
	printf("Tokens:\n");
	while (++i < table->size)
	{
		if (table->tokens[i] && table->tokens[i]->str)
		{
			printf("Token %d: '%s' ", i, table->tokens[i]->str);
			if (table->tokens[i]->type == PIPE)
				printf("Type: PIPE\n");
			else if (table->tokens[i]->type == REDIN)
				printf("Type: REDIN\n");
			else if (table->tokens[i]->type == REDOUT)
				printf("Type: REDOUT\n");
			else if (table->tokens[i]->type == REDAPP)
				printf("Type: REDAPPEND\n");
			else if (table->tokens[i]->type == HEREDOC)
				printf("Type: HEREDOC\n");
			else if (table->tokens[i]->type == DELIMITER)
				printf("Type: DELIMITER\n");
			else if (table->tokens[i]->type == DELIMITER_Q)
				printf("Type: DELIMITER_Q\n");
			else if (table->tokens[i]->type == COMMAND)
				printf("Type: COMMAND\n");
			else if (table->tokens[i]->type == ARG)
				printf("Type: ARG\n");
			else if (table->tokens[i]->type == FILENAME)
				printf("Type: FILENAME\n");
			else
				printf("Type: UNKNOWN\n");
		}
	}
}
