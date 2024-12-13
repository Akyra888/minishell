/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:40:01 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/11 15:26:19 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_token_table(t_tokentab *table)
{
	int	i;

	i = -1;
	if (table == NULL)
		return ;
	if (table->tokens == NULL)
		return ;
	if (table->tokens[0] == NULL)
		return ;
	printf("\nTokens:\n\n");
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
	printf("\n");
}

static void	print_array(char **array, const char *label)
{
	int	i;

	i = 0;
	printf("%s: ", label);
	if (array == NULL)
	{
		printf("(NULL)\n");
		return ;
	}
	while (array[i] != NULL)
	{
		printf("%s", array[i]);
		if (array[i + 1] != NULL)
			printf(" -> ");
		i++;
	}
	printf("\n");
}

void	print_sections(t_sections *sections)
{
	int	n;

	n = 0;
	while (sections != NULL)
	{
		printf("Section %d:\n\n", n);
		print_array(sections->args, "ARGS");
		print_array(sections->redir, "REDIR");
		print_array(sections->filename, "FILE");
		print_array(sections->heredoc, "HEREDOC");
		if (sections->pipe)
			printf("PIPE \"%s\"\n", sections->pipe);
		else
			printf("PIPE (NULL)\n");
		printf("\n");
		sections = sections->next;
		n++;
	}
}
