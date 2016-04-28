/*
** main.c for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Dec 24 14:30:39 2015 Ronan Boiteau
** Last update Thu Apr  7 15:29:48 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "mysh_builtins.h"
#include "mysh_input.h"
#include "mysh_run.h"
#include "mysh_signal_parent.h"

static void	chkenv(char ***env)
{
  if (my_getenv(*env, "PATH=") == NULL)
    my_setenv(env, "PATH=", "/bin:/usr/local/bin:/sbin:/usr/bin:/usr/sbin");
  return ;
}

int		main(int argc, char **argv, char **environ)
{
  t_builtin_ptr	**builtins;
  t_command	command;
  t_uchar	ret;
  char		**env;

  ret = EXIT_SUCCESS;
  (void)(argc + argv);
  env = my_envcpy(environ);
  if ((builtins = malloc(sizeof(t_builtin_ptr *) * (BUILTINS_NBR + 1)))
      == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  init_builtins(builtins);
  while (TRUE)
    {
      signal_handler(SETSIG, SIGINT_REGULAR);
      chkenv(&env);
      if (get_input(&command, ret, env) == EXIT_SUCCESS
	  && (ret = chck_command_logic(command)) == EXIT_SUCCESS)
	ret = handle_command_logic(builtins, &env, command);
      my_free_2d_tab(command.argv);
    }
  return (EXIT_SUCCESS);
}
