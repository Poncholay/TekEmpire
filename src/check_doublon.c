/*
** check_doublon.c for check_coublon in /home/wilmot_g/.ssh/BocalEmblem/I : The Sacred Stones/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 16 11:30:52 2015 guillaume wilmot
** Last update Sun May 17 21:24:58 2015 Jean BARRIERE
*/

#include "sdl.h"

int	loop_doublons(char **map, char **tab, t_coords *coords)
{
  char	**tab2;

  while (map[coords->y2])
    {
      if ((tab2 = str_to_word_tab(map[coords->y2])) == NULL)
	return (0);
      coords->x2 = (coords->y2 == coords->y) ? coords->x + 1 : 0;
      while (tab2[coords->x2])
	if (my_atoi(tab2[coords->x2]) == my_atoi(tab[coords->x]))
	  {
	    my_fprintf("Duplicates : %d on (%d;%d)\n",
		       my_atoi(tab2[coords->x2]), coords->x2, coords->y2);
	    free_double_tab(tab2);
	    free_double_tab(tab);
	    return (0);
	  }
	else
	  coords->x2++;
      free_double_tab(tab2);
      coords->y2++;
    }
  return (1);
}

int		check_doublon(char **map)
{
  t_coords	coords;
  char	**tab;

  coords.y = 0;
  while (map[coords.y])
    {
      coords.x = 0;
      if ((tab = str_to_word_tab(map[coords.y])) == NULL)
	return (0);
      while (tab[coords.x])
	{
	  if (my_atoi(tab[coords.x]) > 10 && my_atoi(tab[coords.x]) <= 70)
	    {
	      coords.y2 = coords.y;
	      if (!loop_doublons(map, tab, &coords))
		return (0);
	    }
	  coords.x++;
	}
      free_double_tab(tab);
      coords.y++;
    }
  return (1);
}
