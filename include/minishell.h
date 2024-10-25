/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:17:14 by nicpinar          #+#    #+#             */
/*   Updated: 2024/10/25 19:51:02 by nicpinar         ###   ########.fr       */
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

typedef enum e_type
{
	CMD,
	TXT
}	t_type;

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
	t_type				type;
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
// fonction principale du lexer. prends l'input original et le transforme en tableau de tokens. analyse caractere par caractere et appelle les fonctions correspondantes.
t_tokentab	*tokenize_line(char *line);

//heredoc.c
void		handle_heredoc(t_parserstate *state, char *line, int index);

//detect_errors.c
// detecte les erreurs de syntaxe et les cas non geres (; || && etc)
void		detect_early_errors(char *line);

//PARSER

//parser.c
void		parse_line(char *line);

//TOKEN_MANIP

//token_handling.c
t_token		*create_token(void);
void		destroy_token(t_token *t);
void		push_char(t_token *t, char c);

//token_tab_handling.c
t_tokentab	*create_token_table(void);
void		destroy_token_table(t_tokentab *t);
void		push_token(t_tokentab *t, t_token *tok);
void		print_tokens(t_tokentab *t);

//-----SIGNAL-----//
//gere les signaux en cas de ctrl+c ou ctrl+d
void		ft_signal(void);

//-----UTILS-----//

//utils.c
int			ft_strcmp(const char *s1, const char *s2);
void		ft_error(char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

//utils2.c
//wallah je la commente pas celle la
int			is_operator(char c);
//cherche si il n'y a que des espaces dans la chaine
int			is_only_spaces(char *str);
//cherche une chaine dans une autre genre "<<" dans "ls << file" mais ne la detecte pas si elle est entre guillemets
int			to_find_str(char *str, char *to_find);
//cherche un backslash dans une chaine
int			find_backslash(char *str);

//test.c
void		print_token_table(t_tokentab *table);

//lists.c
void		push_head(t_list *l, char *token);
void		lstadd_tail(t_list *l, char *token);
t_node		*lstdel_head(t_list *l);

//lists2.c
void		print_list(t_list *l);
void		find_nodes(t_list *l, char *token1, char *token2,
				t_node **curr1, t_node **curr2);
void		swap_pointers(t_list *l, t_node *curr1, t_node *curr2);
void		swap_nodes(t_list *l, char *token1, char *token2);

#endif
