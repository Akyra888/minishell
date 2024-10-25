/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:40:01 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/24 15:14:32 by nicpinar         ###   ########.fr       */
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
			switch (table->tokens[i]->type)
			{
				case CMD:
					printf("CMD");
					break;
				case TXT:
					printf("TXT");
					break;
				default:
					printf("Unknown");
					break;
			}
			printf(", ");
			switch (table->tokens[i]->quote)
			{
				case NONE:
					printf("None");
					break;
				case SQUOTE:
					printf("Single Quote");
					break;
				case DQUOTE:
					printf("Double Quote");
					break;
				default:
					printf("Unknown");
					break;
			}
			printf("\n");
		}
	}
}
