#include "my.h"

char		*my_strupcase(char *str)
{
  t_uint	idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] >= 'a' && str[idx] <= 'z')
	str[idx] = str[idx] - 32;
      idx += 1;
    }
  return (str);
}
