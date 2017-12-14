#ifndef MYSH_RUN_H_
# define MYSH_RUN_H_

# include "mysh_builtins.h"
# include "mysh_command.h"

# define IGN (0)
# define AND (1)
# define OR (2)

t_uchar		chck_command_logic(t_command command);
char		**get_path(char **env);
t_uchar		handle_command_logic(t_builtin_ptr **builtins,
				     char ***env,
				     t_command command);
t_uchar		run_command(t_builtin_ptr **builtins,
			    char ***env,
			    t_command *command);

#endif /* !MYSH_RUN_H_ */
