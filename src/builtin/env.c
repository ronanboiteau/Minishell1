#include <stdlib.h>
#include "my.h"
#include "mysh_opt_env.h"

static void	get_opt_env(char **argv, t_opt_env *options)
{
  int		idx;

  idx = 0;
  options->opt_0 = FALSE;
  options->opt_u = FALSE;
  while (argv != NULL && argv[idx])
    {
      if (my_cmp(argv[idx], "-0") || my_cmp(argv[idx], "--null"))
	options->opt_0 = TRUE;
      else if (my_cmp(argv[idx], "-u"))
	{
	  options->opt_u = TRUE;
	  options->opt_u_arg = argv[idx + 1];
	}
      idx += 1;
    }
  return ;
}

t_uchar		run_env(char ***env, char **argv)
{
  t_opt_env	options;

  get_opt_env(argv, &options);
  if (options.opt_u == TRUE)
    {
      if (options.opt_u_arg == NULL || options.opt_u_arg[0] == '\0')
	{
	  my_dprintf(STDERR, "env: option requires an argument -- 'u'\n");
	  return (125);
	}
      else
	my_unsetenv(env, options.opt_u_arg);
    }
  if (options.opt_0 == TRUE)
    my_printenv(*env, '\0');
  else
    my_printenv(*env, '\n');
  return (0);
}
