#ifndef MYSH_COMMAND_H_
# define MYSH_COMMAND_H_

typedef struct	s_command
{
  char		**argv;
  char		**argv_tmp;
  char		interactive;
}		t_command;

#endif /* !MYSH_COMMAND_H_ */
