/*
** get_event.c for get_event in /home/wilmot_g/.ssh/BocalEmblem/V : The Way To Valhalla/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 17 11:16:26 2015 guillaume wilmot
** Last update Sun May 17 15:58:05 2015 guillaume wilmot
*/

#include "sdl.h"

int		*make_event(t_coords coords, int *event, int i)
{
  event[0] = coords.x;
  event[1] = coords.y;
  if (i == 2)
    {
      event[2] = 8;
      return (event);
    }
  event[2] = 9;
  if (coords.x == coords.x2 && coords.y < coords.y2)
    event[2] = 5;
  else if (coords.x == coords.x2 && coords.y > coords.y2)
    event[2] = 4;
  else if (coords.y == coords.y2 && coords.x < coords.x2)
    event[2] = 6;
  else if (coords.y == coords.y2 && coords.x > coords.x2)
    event[2] = 7;
  return (event);
}

int		*get_event(int unit, int target, char **map, int i)
{
  t_coords	coords;
  int		*event;

  if ((event = malloc(3 * sizeof(int))) == NULL)
    return (my_puterr("Malloc : error\n", NULL));
  coords.y = ((coords.x = 0) == 0) ? 0 : 0;
  while (map && map[coords.y] && map[coords.y][coords.x] != unit)
    {
      coords.x = 0;
      while (map[coords.y][coords.x] != -1 && map[coords.y][coords.x] != unit)
	coords.x += 3;
      if (map[coords.y][coords.x] != unit)
	coords.y++;
    }
  coords.y2 = ((coords.x2 = 0) == 0) ? 0 : 0;
  while (map && map[coords.y2] && map[coords.y2][coords.x2] != target)
    {
      coords.x2 = 0;
      while (map[coords.y2][coords.x2] != -1
	     && map[coords.y2][coords.x2] != target)
	coords.x2 += 3;
      if (map[coords.y2][coords.x2] != target)
	coords.y2++;
    }
  return (make_event(coords, event, i));
}
