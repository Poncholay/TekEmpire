/*
** create_board.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/II : Path of Radiance/src
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 10:48:10 2015 Jean BARRIERE
** Last update Sat May 16 22:22:40 2015 guillaume wilmot
*/

#include "sdl.h"

int	size_str(char *str)
{
  int	i;
  int	size;

  i = 0;
  size = 0;
  while (str && str[i] != 0)
    {
      if (is_number(str[i]) && !is_number(str[i + 1]))
	++size;
      ++i;
    }
  return (size);
}

char	*new_boardline(char *str, int size)
{
  char	*ret;
  int	i;
  int	j;

  i = 0;
  if ((ret = malloc((size * 3 + 1) * sizeof(char))) == NULL)
    return (my_puterr("Error: cannot perform malloc\n", NULL));
  j = 0;
  while (i < size * 3)
    {
      ret[i] = my_atoi(&str[j]);
      ret[i + 1] = ((ret[i] <= 10) ? (0) : (30));
      ret[i + 2] = 0;
      i += 3;
      while (str && str[j] != 0 && is_number(str[j]))
	++j;
      while (str && str[j] != 0 && !is_number(str[j]))
	++j;
    }
  ret[i] = -1;
  return (ret);
}

char	**create_board(char **tab)
{
  char	**ret;
  int	i;
  int	len;
  int	size;

  i = 0;
  size = size_str(tab[0]);
  len = tab_len(tab);
  if ((ret = malloc((len + 1) * sizeof(char *))) == NULL)
    return (my_puterr("Error: cannot perform malloc\n", NULL));
  while (i < len)
    {
      ret[i] = new_boardline(tab[i], size);
      ++i;
    }
  ret[i] = NULL;
  return (ret);
}
