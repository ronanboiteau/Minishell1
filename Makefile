NAME	 = mysh

IDIR	 = include/
IDIR_MY	 = lib/my/include/

LIB	 = libmy.a
LNAME	 = my
LDIR	 = lib/my/

CC	 = gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Wextra -ansi
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

BUILTINS_DIR	= builtin/
BUILTINS_FILES	= builtins.c		\
		  cd.c			\
		  echo.c		\
		  env.c			\
		  exit.c		\
		  fct_ptr.c		\
		  printenv.c		\
		  pwd.c			\
		  setenv.c		\
		  unsetenv.c
BUILTINS	= $(addprefix $(BUILTINS_DIR), $(BUILTINS_FILES))

SIGNAL_DIR	= signal/
SIGNAL_FILES	= child.c	\
		  parent.c
SIGNAL		= $(addprefix $(SIGNAL_DIR), $(SIGNAL_FILES))

SRCS_DIR	= src/
SRCS_FILES	= count_args.c		\
		  exec_path.c		\
		  get_path.c		\
		  input.c		\
		  logic.c		\
		  main.c		\
		  parser.c		\
		  run.c			\
		  $(BUILTINS)		\
		  $(SIGNAL)
SRCS     = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	 = $(SRCS:.c=.o)

RM	 = rm -f


all: $(LIB) $(NAME)

$(LIB):
	make -C $(LDIR)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L $(LDIR) -l $(LNAME)

clean:
	$(RM) $(OBJS)
	make -C $(LDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: all clean fclean re
