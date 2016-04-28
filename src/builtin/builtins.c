/*
** builtins.c for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Jan 14 19:19:36 2016 Ronan Boiteau
** Last update Thu Apr  7 15:24:02 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"

t_uchar		print_builtins(char ***env, char **argv)
{
  (void)env;
  (void)argv;
  if (argv[1] != NULL)
    {
      my_dprintf(STDERR, "builtins: Too many arguments.\n");
      return (1);
    }
  my_printf("builtins" "\t" "cd" "\t" "chdir" "\t" "echo" "\t" "env" "\t"
	    "printenv" "\t" "pwd" "\t" "setenv" "\n"
	    "unsetenv" "\n");
  return (0);
}
