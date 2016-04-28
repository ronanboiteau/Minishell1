/*
** echo.c for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Jan 14 20:06:55 2016 Ronan Boiteau
** Last update Thu Apr  7 15:25:06 2016 Ronan Boiteau
*/

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
