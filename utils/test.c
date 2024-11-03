/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:40:01 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/03 15:33:08 by nicpinar         ###   ########.fr       */
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
			if (table->tokens[i]->quote == NONE)
				printf("None");
			else if (table->tokens[i]->quote == SQUOTE)
				printf("Single quote");
			else if (table->tokens[i]->quote == DQUOTE)
				printf("Double quote");
			printf("\n");
		}
	}
}
