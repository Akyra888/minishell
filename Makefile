# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 22:30:31 by nicpinar          #+#    #+#              #
#    Updated: 2024/11/13 20:48:56 by nicpinar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCDIR	= .
INCDIR	= include
LIBFTDIR = libft
PARSDIR = parsing
SIGNDIR = signal
UTILSDIR = utils

LEXERDIR = $(PARSDIR)/lexer
TOKENDIR = $(PARSDIR)/token_manip
PARSERDIR = $(PARSDIR)/parser

SRC = $(SRCDIR)/main.c \
      $(LEXERDIR)/lexer.c \
	  $(LEXERDIR)/lexer2.c \
      $(LEXERDIR)/detect_errors.c \
      $(TOKENDIR)/token_handling.c \
      $(TOKENDIR)/token_tab_handling.c \
      $(PARSERDIR)/parser.c \
      $(SIGNDIR)/signal.c \
	  $(UTILSDIR)/test.c \
	  $(UTILSDIR)/utils.c \
	  $(UTILSDIR)/utils2.c

OBJ = $(SRC:.c=.o)

LIBS = -lreadline -L $(LIBFTDIR) -lft
INCLUDES = -I $(INCDIR) -I $(LIBFTDIR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
