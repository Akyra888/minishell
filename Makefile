# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicpinar <nicpinar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 22:30:31 by nicpinar          #+#    #+#              #
#    Updated: 2024/11/24 21:52:20 by nicpinar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
SRCDIR      = .
INCDIR      = include
LIBFTDIR    = libft
PARSDIR     = parsing
SIGNDIR     = signal
UTILSDIR    = utils

PARSERDIR   = $(PARSDIR)/parser
TOKENDIR    = $(PARSDIR)/token_manip
ANALYSERDIR = $(PARSDIR)/analyser
HEREDIR	 	= $(PARSDIR)/heredoc

OBJDIR      = obj

SRC = $(SRCDIR)/main.c \
      $(PARSDIR)/parsing_main.c \
      $(ANALYSERDIR)/detect_first_errors.c \
      $(ANALYSERDIR)/detect_last_errors.c \
	  $(HEREDIR)/heredoc.c \
      $(PARSERDIR)/define_type.c \
      $(PARSERDIR)/expansions.c \
      $(PARSERDIR)/parser.c \
      $(TOKENDIR)/token_handling.c \
      $(TOKENDIR)/token_tab_handling.c \
      $(SIGNDIR)/signal.c \
      $(UTILSDIR)/test.c \
      $(UTILSDIR)/utils.c \
      $(UTILSDIR)/utils2.c

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
