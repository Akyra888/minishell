/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:17:14 by nicpinar          #+#    #+#             */
/*   Updated: 2024/11/03 20:14:56 by nicpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stddef.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_node
{
	char			*token;
	struct s_node	*next;
}	t_node;

typedef struct s_lists
{
	struct s_node	*head;
	struct s_node	*tail;
	int				len;
}	t_lists;

typedef enum e_quote
{
	NONE,
	SQUOTE,
	DQUOTE
}	t_quote;

typedef struct token
{
	char				*str;
	int					size;
	int					mem_size;
	t_quote				quote;
}	t_token;

typedef struct tokentab
{
	t_token				**tokens;
	int					size;
	int					mem_size;
}	t_tokentab;

typedef struct s_parserstate
{
	t_tokentab			*tokens;
	t_token				*current_token;
	char				*line;
	int					index;
}	t_parserstate;

//----PARSING----//

//LEXER

//lexer.c
t_tokentab	*tokenize_line(char *line);

//lexer2.c
void		*last_token_push(t_parserstate *state);
void		*other_cases(t_parserstate *state, char c);

//special_cases.c
void		heredoc_newline(t_parserstate *state);
void		new_line(t_parserstate *state);

//detect_errors.c
int			detect_early_errors(char *line);

//PARSER

//parser.c
void		parse_line(char *line, char **envp);

//TOKEN_MANIP

//token_handling.c
t_token		*create_token(t_parserstate *state);
void		destroy_token(t_token *t);
void		*push_char(t_token *t, char c, t_parserstate *state);

//token_tab_handling.c
t_tokentab	*create_token_table(void);
void		destroy_token_table(t_tokentab *t);
void		*push_token(t_tokentab *t, t_token *tok, t_parserstate *state);
void		print_tokens(t_tokentab *t);

//-----SIGNAL-----//
void		ft_signal(void);

//-----UTILS-----//

//utils.c
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_error(char *str, t_parserstate *state, void **local);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size,
				t_parserstate *state);

//utils2.c
int			is_operator(char c);
int			is_only_spaces(char *str);
int			to_find_str(char *str, char *to_find);
int			find_backslash(char *str);

//test.c
void		print_token_table(t_tokentab *table);

//lists.c
void		push_head(t_lists *l, char *token);
void		lstadd_tail(t_lists *l, char *token);
t_node		*lstdel_head(t_lists *l);

//lists2.c
void		print_list(t_lists *l);
void		swap_nodes(t_lists *l, char *token1, char *token2);

#endif
