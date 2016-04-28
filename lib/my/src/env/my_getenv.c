/*
** my_getenv.c for my_getenv in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Jan  3 18:38:17 2016 Ronan Boiteau
** Last update Mon Jan 18 16:36:52 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

char		*my_getenv(char **env, const char *to_find)
{
  t_uint	idx;
  char		*elem;

  elem = NULL;
  idx = 0;
  while (env != NULL && env[idx])
    {
      if (my_strncmp(env[idx], to_find, my_strlen(to_find)) == 0)
	elem = env[idx] + my_strlen(to_find);
      idx += 1;
    }
  return (elem);
}
