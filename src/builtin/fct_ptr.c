#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "mysh_builtins.h"

void		free_builtins(t_builtin_ptr **builtins)
{
  int		idx;

  idx = 0;
  while (idx < BUILTINS_NBR)
    {
      free(builtins[idx]->command);
      free(builtins[idx]);
      idx += 1;
    }
  free(builtins);
  return ;
}

static void	alloc_builtins(t_builtin_ptr **builtins)
{
  int		idx;

  idx = 0;
  while (idx < BUILTINS_NBR)
    {
      if ((builtins[idx] = malloc(sizeof(t_builtin_ptr) * 1)) == NULL)
	my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
      idx += 1;
    }
  return ;
}

void		init_builtins(t_builtin_ptr **builtins)
{
  alloc_builtins(builtins);
  builtins[0]->command = my_strdup("builtins");
  builtins[0]->fct = print_builtins;
  builtins[1]->command = my_strdup("cd");
  builtins[1]->fct = change_directory;
  builtins[2]->command = my_strdup("chdir");
  builtins[2]->fct = change_directory;
  builtins[3]->command = my_strdup("echo");
  builtins[3]->fct = run_echo;
  builtins[4]->command = my_strdup("env");
  builtins[4]->fct = run_env;
  builtins[5]->command = my_strdup("printenv");
  builtins[5]->fct = run_printenv;
  builtins[6]->command = my_strdup("pwd");
  builtins[6]->fct = print_working_dir;
  builtins[7]->command = my_strdup("setenv");
  builtins[7]->fct = run_setenv;
  builtins[8]->command = my_strdup("unsetenv");
  builtins[8]->fct = run_unsetenv;
  builtins[9] = NULL;
}

t_uchar		call_builtins(t_builtin_ptr **builtins,
			      int *builtin_found,
			      char ***env,
			      char **argv)
{
  int		idx;

  idx = 0;
  while (builtins[idx])
    {
      if (my_cmp(argv[0], builtins[idx]->command))
	{
	  *builtin_found = true;
	  return (builtins[idx]->fct(env, argv));
	}
      idx += 1;
    }
  *builtin_found = false;
  return (0);
}
