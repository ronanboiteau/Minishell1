/*
** count_args.c for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed Jan 13 23:44:15 2016 Ronan Boiteau
** Last update Wed Apr  6 19:09:59 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

t_uint		count_args(char **argv)
{
  t_uint	argc;

  argc = 0;
  while (argv != NULL && argv[argc])
    argc += 1;
  return (argc);
}
