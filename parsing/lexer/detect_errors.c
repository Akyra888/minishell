/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:35:00 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/03 13:49:37 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_early_error(char *str)
{
	ft_putstr_fd("minishell: syntax error ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

static int	is_delimiter(char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && is_operator(line[i]) == 0)
			return (1);
		i++;
	}
	return (0);
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

static int	detect_early_errors2(char *line)
{
	int	i;

	i = to_find_str(line, "<<");
	if (i != -1)
	{
		if (!is_delimiter(line, i))
		{
			free(line);
			ft_early_error("near unexpected token `newline'\n");
		}
	}
	if (find_backslash(line) == 1)
		return (ft_early_error(": backslash is not handled"));
	return (0);
}

int	detect_early_errors(char *line)
{
	if (!is_quote_closed(line))
		return (ft_early_error(": unclosed quote"));
	if (to_find_str(line, "\n") != -1)
		return (ft_early_error(": newline is not handled"));
	if (to_find_str(line, ";") != -1)
		return (ft_early_error(": ';' is not handled"));
	if (to_find_str(line, "||") != -1)
		return (ft_early_error(": '||' is not handled"));
	if (to_find_str(line, "&&") != -1)
		return (ft_early_error(": '&&' is not handled"));
	if (to_find_str(line, "&") != -1)
		return (ft_early_error(": '&' is not handled"));
	if (to_find_str(line, "(") != -1 || to_find_str(line, ")") != -1)
		return (ft_early_error(": parenthesis are not handled"));
	if (to_find_str(line, "><") != -1)
		return (ft_early_error(": '><' is not handled"));
	if (to_find_str(line, "<>") != -1
		&& !is_only_spaces(line + to_find_str(line, "<>")))
		return (ft_early_error("near unexpected token `newline'"));
	return (detect_early_errors2(line));
}
