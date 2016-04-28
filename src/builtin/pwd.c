/*
** pwd.c for minishell in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jan 12 20:34:36 2016 Ronan Boiteau
** Last update Thu Apr  7 15:26:49 2016 Ronan Boiteau
*/

#include <linux/limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

t_uchar		print_working_dir(char ***env, char **argv)
{
  char		*path;

  (void)env;
  (void)argv;
  if ((path = malloc(sizeof(char) * PATH_MAX)) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! Please reduce PATH_MAX.\n");
  if (getcwd(path, 100) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: getcwd() failed.");
  my_printf("%s\n", path);
  free(path);
  return (0);
}
