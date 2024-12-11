# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 22:30:31 by nicpinar          #+#    #+#              #
#    Updated: 2024/12/11 15:16:09 by nicpinar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
SRCDIR      = .
INCDIR      = include
LIBFTDIR    = libft
PARSDIR     = parsing
SIGNDIR     = signal
UTILSDIR    = utils
CONVDIR		= $(PARSDIR)/convert
PARSERDIR   = $(PARSDIR)/parser
TOKENDIR    = $(PARSDIR)/token_manip
SYNTAX		= $(PARSDIR)/syntax
HEREDIR	 	= $(PARSDIR)/heredoc

OBJDIR      = obj

SRC = $(SRCDIR)/main.c \
      $(PARSDIR)/parsing_main.c \
      $(SYNTAX)/analyse_line.c \
      $(SYNTAX)/analyse_tokens.c \
	  $(HEREDIR)/heredoc.c \
	  $(CONVDIR)/convert.c \
      $(PARSERDIR)/define_type.c \
      $(PARSERDIR)/expansions.c \
      $(PARSERDIR)/tokenizer.c \
      $(TOKENDIR)/token_handling.c \
      $(TOKENDIR)/token_tab_handling.c \
      $(SIGNDIR)/signal.c \
      $(UTILSDIR)/free_memory.c \
      $(UTILSDIR)/parsing_utils.c \
      $(UTILSDIR)/print.c \
	  $(UTILSDIR)/str_manip.c

SRCS = $(patsubst ./%,%,$(SRC))

OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

LIBS     = -lreadline -L $(LIBFTDIR) -lft
INCLUDES = -I $(INCDIR) -I $(LIBFTDIR)

VPATH = $(sort $(dir $(SRCS)))

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
