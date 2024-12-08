/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:17:14 by nicpinar          #+#    #+#             */
/*   Updated: 2024/12/08 18:38:33 by nicpinar         ###   ########.fr       */
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
# include <bits/sigaction.h>
# include <asm-generic/signal-defs.h>

extern volatile sig_atomic_t	g_sigint_received;

typedef struct s_dict
{
	char			*name;
	char			*value;
	struct s_dict	*next;
}	t_dict;

typedef struct s_sections
{
	char				**args;
	char				**redir;
	char				**filename;
	char				**heredoc;
	char				*pipe;
	struct s_sections	*next;
}	t_sections;

typedef struct s_whole
{
	t_sections	**sections;
	t_dict		**dict;
}	t_whole;

typedef enum e_type
{
	UNKNOWN,
	PIPE,
	REDIN,
	REDOUT,
	REDAPP,
	FILENAME,
	HEREDOC,
	DELIMITER,
	DELIMITER_Q,
	COMMAND,
	ARG
}	t_type;

typedef struct token
{
	char				*str;
	int					size;
	int					mem_size;
	t_type				type;
}	t_token;

typedef struct tokentab
{
	t_token				**tokens;
	int					size;
	int					mem_size;
}	t_tokentab;

typedef struct s_parserstate
{
	t_tokentab			*table;
	t_token				*current_token;
	char				*line;
	int					index;
}	t_parserstate;

//------MAIN------//
char		*ft_readline(int type);

//--------------------------------PARSING-------------------------------------//

t_sections	*parsing_main(char *line, char **envp);

//------LISTS-----//
int			convert_to_list(t_sections **sections, t_tokentab *table);

//------ANALYSER-----//

//detect_errors.c
int			detect_early_errors(char *line);
//detect_last_errors
int			analyse_tokens(t_tokentab *table, t_parserstate *state);
int			analyse_heredoc(t_tokentab *table, t_token **token,
				int i, t_parserstate *state);
int			handle_heredoc_analyse(t_tokentab *table, t_parserstate *state);

//------HEREDOC-----//
int			gen_heredoc_prompt(t_token *token, t_token *del,
				t_parserstate *state);

//------PARSING-----//

//define_type.c
void		define_op_type(t_parserstate *state, char c, char next);
void		define_type(t_parserstate *state, int quote);

//expansions.c
int			handle_expansion(t_parserstate *state);
char		*ft_expand(char *str, t_parserstate *state);

//parser.c
t_tokentab	*tokenizer(t_parserstate *state);

//TOKEN_MANIP

//token_handling.c
t_token		*create_token(t_parserstate *state);
void		destroy_token(t_token *t);
void		push_char(t_token *t, char c, t_parserstate *state);

//token_tab_handling.c
t_tokentab	*create_token_table(void);
void		destroy_token_table(t_tokentab *t);
void		push_token(t_tokentab *t, t_token *tok, t_parserstate *state);
void		print_tokens(t_tokentab *t);

//-----------------------------SIGNAL-----------------------------------------//
int			ft_signal(void);
// void		ft_heredoc_signal(void);
int			check_signal(void);

//-----------------------------UTILS-----------------------------------------//

//utils.c
int			is_valid(char c);
int			ft_strcmp(const char *s1, const char *s2);
void		malloc_error(char *str, t_parserstate *state, void **local);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size,
				t_parserstate *state);
int			is_next_valid(char c);
void		append_to_result(char *dest, char *src, int *index);

//utils2.c
int			is_operator(char c);
int			is_only_spaces(char *str);
int			to_find_str(char *str, char *to_find);
int			find_backslash(char *str);
int			prev_heredoc(t_parserstate *state);

//utils3.c
void		free_sections(t_sections **sections);
int			free_strs(char **strs);
char		**add_to_array(char **array, char *str);

//test.c
void		print_token_table(t_tokentab *table);
void		print_sections(t_sections *sections);

#endif
