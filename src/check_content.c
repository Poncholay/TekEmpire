/*
** check_content.c for check_content in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 21:42:24 2015 guillaume wilmot
** Last update Sun May 17 22:45:59 2015 guillaume wilmot
*/

#include "sdl.h"

char	**str_to_word_tab(char *str)
{
  char	**tab;
  int	i;
  int	k;
  int	j;

  i = 0;
  j = 0;
  while (str[i] && str[i] == ' ')
    i++;
  if ((tab = malloc((my_strlen(str) + 2) * sizeof(char *))) == NULL)
    return (my_puterr("Malloc : error\n", NULL));
  while (str[i])
    {
      if ((tab[j] = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
	return (my_puterr("Malloc : error\n", NULL));
      k = 0;
      while (str[i] && str[i] != ' ')
	tab[j][k++] = str[i++];
      tab[j][k] = '\0';
      while (str[i] && str[i] == ' ')
	i++;
      j++;
    }
  tab[j] = '\0';
  return (tab);
}

int	check_borders(char **map)
{
  int	x;
  int	y;

  y = 0;
  while (map[y])
    {
      x = 0;
      if (y == 0 || y == tab_len(map) - 1)
	{
	  while (map[y][x] && (map[y][x] == '1' || map[y][x] == ' '))
	    x++;
	  if (map[y][x] != '\0' && map[y][x] != '1')
	    return (my_puterr_int("Bad borders\n", 0));
	}
      else
	if (map[y][0] != '1' || map[y][my_strlen(map[y]) - 1] != '1')
	  return (my_puterr_int("Bad borders\n", 0));
      y++;
    }
  return (1);
}

int	check_space_integrity(char **map)
{
  int	x;
  int	y;
  int	nbr;
  int	nbr2;

  nbr = 0;
  nbr2 = 0;
  x = 0;
  while (map[0][x])
    if (map[0][x++] == ' ')
      nbr++;
  y = 0;
  while (map[y])
    {
      x = 0;
      nbr2 = 0;
      while (map[y][x])
	if (map[y][x++] == ' ')
	  nbr2++;
      if (nbr2 != nbr)
	return ((my_puterr_int
		 ("Spaces missing, the map is not a rectangle\n", 0)));
      y++;
    }
  return (1);
}

int	check_spaces(char **map)
{
  int	x;
  int	y;

  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x])
	{
	  if (map[y][x] == ' ')
	    {
	      if (map[y][x + 1] == ' ')
		return ((my_puterr_int
			 ("More than one space between two elements\n", 0)));
	    }
	  x++;
	}
      y++;
    }
  if (my_strlen(map[0]) < 8 || tab_len(map) < 4)
    return ((my_puterr_int("Map muste be at least 4 x 4 on the SDL\n", 0)));
  return (check_space_integrity(map));
}

int	check_values(char **map)
{
  int	y;
  int	x;
  char	**tab;

  y = 0;
  while (map[y])
    {
      x = 0;
      tab = str_to_word_tab(map[y]);
      while (tab[x])
	{
	  if (my_atoi(tab[x]) < 0 || my_atoi(tab[x]) > 70)
	    {
	      my_fprintf("The value %d at (%d;%d) is wrong\n",
			 my_atoi(tab[x]), x, y);
	      free_double_tab(tab);
	      return (0);
	    }
	  x++;
	}
      free_double_tab(tab);
      y++;
    }
  return (1);
}
