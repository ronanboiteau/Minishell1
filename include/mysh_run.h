/*
** mysh_run.h for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Dec 31 19:23:32 2015 Ronan Boiteau
** Last update Wed Apr  6 19:02:49 2016 Ronan Boiteau
*/

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
