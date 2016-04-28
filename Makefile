##
## Makefile for minishell in /home/boitea_r
## 
## Made by Ronan Boiteau
## Login   <boitea_r@epitech.net>
## 
## Started on  Thu Dec 24 14:24:41 2015 Ronan Boiteau
## Last update Wed Apr  6 19:14:52 2016 Ronan Boiteau
##

NAME	 = mysh

IDIR	 = include/

LIB	 = libmy.a
LNAME	 = my
LDIR	 = lib/my

CC	 = gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Wextra -ansi
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

SDIR	 = src/
SRCS	 = $(SDIR)builtin/builtins.c			\
	   $(SDIR)builtin/cd.c				\
	   $(SDIR)builtin/echo.c			\
	   $(SDIR)builtin/env.c				\
	   $(SDIR)builtin/exit.c			\
	   $(SDIR)builtin/fct_ptr.c			\
	   $(SDIR)builtin/printenv.c			\
	   $(SDIR)builtin/pwd.c				\
	   $(SDIR)builtin/setenv.c			\
	   $(SDIR)builtin/unsetenv.c			\
	   $(SDIR)count_args.c				\
	   $(SDIR)exec_path.c				\
	   $(SDIR)get_path.c				\
	   $(SDIR)input.c				\
	   $(SDIR)logic.c				\
	   $(SDIR)main.c				\
	   $(SDIR)parser.c				\
	   $(SDIR)run.c					\
	   $(SDIR)signal/child.c			\
	   $(SDIR)signal/parent.c

OBJS	 = $(SRCS:.c=.o)

RM	 = rm -f


all: $(LIB) $(NAME)

$(LIB):
	cd $(LDIR) && $(MAKE)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L lib -l $(LNAME)

clean:
	$(RM) $(OBJS)
	cd $(LDIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd $(LDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
