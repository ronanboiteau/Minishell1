#include <limits.h>
#include <stdlib.h>
#include "my.h"

t_uchar		run_echo(char ***env, char **argv)
{
  t_uint	idx;

  (void)env;
  idx = 1;
  while (idx < UINT_MAX && argv != NULL && argv[idx] && argv[idx + 1])
    {
      my_printf("%s ", argv[idx]);
      idx += 1;
    }
  if (argv[idx])
    my_printf("%s", argv[idx]);
  my_printf("\n");
  return (0);
}
