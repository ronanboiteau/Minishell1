#include <stdlib.h>
#include "my.h"

static t_uint	_get_word_size(char *str)
{
  t_uint	size;

  size = 0;
  while (str[size] && str[size] != ' ' && str[size] != '\t')
    size += 1;
  return (size);
}

static t_uint	_count_words(char *str)
{
  t_uint	idx;
  t_uint	words;

  words = 0;
  idx = 0;
  while (str[idx])
    {
      if (str[idx] == ' ' || str[idx] == '\t')
	words += 1;
      while (str[idx] == ' ' || str[idx] == '\t')
	idx += 1;
      idx += 1;
    }
  return (words + 1);
}

static char	*_fill_column(char *clean_str, t_uint *idx_str)
{
  t_uint	idx;
  t_uint	size;
  char		*column;

  size = _get_word_size(clean_str + *idx_str);
  if ((column = malloc(sizeof(char) * (size + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  idx = 0;
  while (idx < size && clean_str[*idx_str])
    {
      column[idx] = clean_str[*idx_str];
      *idx_str += 1;
      idx += 1;
    }
  column[idx] = '\0';
  *idx_str += 1;
  return (column);
}

char		**my_str_to_wordtab(char *clean_str)
{
  t_uint	idx_line;
  t_uint	idx_str;
  t_uint	words;
  char		**tab;

  if (clean_str == NULL)
    return (NULL);
  words = _count_words(clean_str);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  idx_str = 0;
  idx_line = 0;
  while (idx_line < words)
    {
      tab[idx_line] = _fill_column(clean_str, &idx_str);
      idx_line += 1;
    }
  tab[idx_line] = NULL;
  return (tab);
}
