/*
** get_infos.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/III : Radiant Down
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 17:25:35 2015 Jean BARRIERE
** Last update Sat May 16 22:23:23 2015 guillaume wilmot
*/

#include "sdl.h"

int	get_damage(int unit, int target, int *flag)
{
  int	ret;

  ret = 5;
  if ((unit >= 11 && unit <= 20 && target >= 61 && target <= 70) ||
      (unit >= 41 && unit <= 50 && target >= 31 && target <= 40) ||
      (unit >= 21 && unit <= 30 && target >= 41 && target <= 50) ||
      (unit >= 51 && unit <= 60 && target >= 11 && target <= 20) ||
      (unit >= 31 && unit <= 40 && target >= 51 && target <= 60) ||
      (unit >= 61 && unit <= 70 && target >= 21 && target <= 30))
    ret *= 3;
  if (flag != NULL)
    *flag += 1;
  return (ret);
}

int	get_hp(char **board, int unit)
{
  int	y;
  int	x;

  y = 0;
  while (board && board[y] != NULL)
    {
      x = 0;
      while (board[y][x] != -1)
	{
	  if (board[y][x] == unit)
	    return (board[y][x + 1]);
	  x += 3;
	}
      ++y;
    }
  return (0);
}
