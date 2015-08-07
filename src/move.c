/*
** move.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/II : Path of Radiance
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 14:49:04 2015 Jean BARRIERE
** Last update Sun May 17 16:15:32 2015 guillaume wilmot
*/

#include "sdl.h"

int	is_good_direction(char *str)
{
  if (nmatch(str, "top", 3))
    return (1);
  else if (nmatch(str, "left", 4))
    return (4);
  else
    {
      if (nmatch(str, "bottom", 6))
	return (3);
      else if (nmatch(str, "right", 5))
	return (2);
      else
	return (0);
    }
}

int	is_turn(int nb, int turn)
{
  if (nb > 10 && nb < 41 && turn == 0)
    return (1);
  else if (nb > 40 && nb < 71 && turn == 1)
    return (1);
  return (0);
}

t_coords	*get_pos_by_dir(char **board, int y, int x, int dir)
{
  t_coords	*ret;

  if ((ret = malloc(sizeof(t_coords))) == NULL)
    return (my_puterr("Error: cannot perform malloc\n", NULL));
  if ((dir == 1 && board[y - 1][x] == 0) || (dir == 3 && board[y + 1][x] == 0))
    {
      ret->y = y + ((dir == 1) ? (-1) : (1));
      ret->x = x;
    }
  else if ((dir == 2 && board[y][x + 3] == 0) ||
	   (dir == 4 && board[y][x - 3] == 0))
    {
      ret->y = y;
      ret->x = x + ((dir == 2) ? (3) : (-3));
    }
  else
    {
      free(ret);
      return (NULL);
    }
  return (ret);
}

int		move_unit(t_sdl *sdl , int y, int x, int dir)
{
  int		event[3];
  t_coords	*pos;

  pos = get_pos_by_dir(sdl->map, y, x, dir);
  if (pos != NULL && dir != 0)
    {
      event[0] = x;
      event[1] = y;
      event[2] = dir - 1;
      animate_units(sdl->anims, sdl->map, sdl->assets, event);
      sdl->map[pos->y][pos->x] = sdl->map[y][x];
      sdl->map[y][x] = 0;
      sdl->map[pos->y][pos->x + 1] = sdl->map[y][x + 1];
      sdl->map[y][x + 1] = 0;
      sdl->map[pos->y][pos->x + 2] += 1;
      sdl->map[y][x + 2] = 0;
      free(pos);
      return (1);
    }
  return (-1);
}

void	try_move(int unit, int dir, char **board, t_sdl *sdl)
{
  int	x;
  int	y;
  int	msg;

  msg = ((y = 0) == 0) ? 0 : 0;
  sdl->map = board;
  while (board && board[y] != NULL && msg == 0)
    {
      x = 0;
      while (board[y][x] != -1 && msg == 0)
	{
	  if (board[y][x] == unit && (board[y][x + 2] == 0 ||
				      board[y][x + 2] == 2))
	    msg = move_unit(sdl, y, x, dir);
	  x += 3;
	}
      ++y;
    }
  board = sdl->map;
  if (msg == 1)
    my_printf("%d has moved of 1 to %s\n", unit, (dir == 1) ? ("top") :
	      ((dir == 2) ? ("right") :
	       ((dir == 3) ? ("bottom") : ("left"))));
  else
    my_putstr("There is an error on your command\n");
}
