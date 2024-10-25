/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:35:00 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/25 19:37:57 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// libere la memoire et affiche un message d'erreur
static void	ft_early_error(char *str, char *line)
{
	free(line);
	ft_putstr_fd("minishell: syntax error ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

// trouve si le heredoc a un delimiter
static int	is_delimiter(char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

//verifie si les quotes sont fermes
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

//pareil mais pour le heredoc et le backslash
static void	detect_early_errors2(char *line)
{
	int	i;

	i = to_find_str(line, "<<");
	if (i != -1)
	{
		if (!is_delimiter(line, i))
		{
			free(line);
			ft_early_error(": no delimiter\n", line);
		}
	}
	if (find_backslash(line) == 1)
		ft_early_error(": backslash is not handled", line);
}

void	detect_early_errors(char *line)
{
	if (!is_quote_closed(line))
		ft_early_error(": unclosed quote", line);
	if (to_find_str(line, ";") != -1)
		ft_early_error(": ';' is not handled", line);
	if (to_find_str(line, "||") != -1)
		ft_early_error(": '||' is not handled", line);
	if (to_find_str(line, "&&") != -1)
		ft_early_error(": '&&' is not handled", line);
	if (to_find_str(line, "&") != -1)
		ft_early_error(": '&' is not handled", line);
	if (to_find_str(line, "(") != -1 || to_find_str(line, ")") != -1)
		ft_early_error(": parenthesis are not handled", line);
	if (to_find_str(line, "><") != -1)
		ft_early_error(": '><' is not handled", line);
	if (to_find_str(line, "<>") != -1
		&& !is_only_spaces(line + to_find_str(line, "<>")))
		ft_early_error("near unexpected token `newline'", line);
	detect_early_errors2(line);
}
