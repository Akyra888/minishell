/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:35:00 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/13 20:36:42 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	early_error(char *str)
{
	ft_putstr_fd("minishell: syntax error ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

static int	is_quote_closed(char *str)
{
	int	i;
	int	single_quote;
	int	double_quote;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !double_quote)
			single_quote = !single_quote;
		if (str[i] == '"' && !single_quote)
			double_quote = !double_quote;
		i++;
	}
	if (single_quote || double_quote)
		return (0);
	return (1);
}

int	detect_early_errors(char *line)
{
	if (!is_quote_closed(line))
		return (early_error(": unclosed quote"));
	if (to_find_str(line, "\n") != -1)
		return (early_error(": newline is not handled"));
	if (to_find_str(line, ";") != -1)
		return (early_error(": ';' is not handled"));
	if (to_find_str(line, "||") != -1)
		return (early_error(": '||' is not handled"));
	if (to_find_str(line, "&&") != -1)
		return (early_error(": '&&' is not handled"));
	if (to_find_str(line, "&") != -1)
		return (early_error(": '&' is not handled"));
	if (to_find_str(line, "(") != -1 || to_find_str(line, ")") != -1)
		return (early_error(": parenthesis are not handled"));
	if (to_find_str(line, "><") != -1)
		return (early_error("near unexpected token `<'"));
	if (to_find_str(line, "<>") != -1
		&& !is_only_spaces(line + to_find_str(line, "<>")))
		return (early_error("near unexpected token `newline'"));
	if (find_backslash(line) == 1)
		return (early_error(": backslash is not handled"));
	return (0);
}
