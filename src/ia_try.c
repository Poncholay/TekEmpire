/*
** ia_try.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/V : The Way To Valhalla
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sun May 17 21:09:00 2015 Jean BARRIERE
** Last update Sun May 17 23:30:47 2015 Jean BARRIERE
*/

#include "sdl.h"

void	try_ia_attack(char **board, t_coords *pos, t_coords *target,
		      t_sdl *sdl)
{
  int	msg;
  int	unit;
  int	targ;

  msg = 0;
  if ((((pos->x - target->x == 3 || pos->x - target->x == -3) &&
	pos->y - target->y == 0) ||
       ((pos->y - target->y == 1 || pos->y - target->y == -1) &&
	pos->x - target->x == 0)) && board[pos->y][pos->x + 2] < 2)
    {
      unit = board[pos->y][pos->x];
      targ = board[target->y][target->x];
      msg = access_target(sdl, pos, unit, targ);
      board[pos->y][pos->x + 2] += 2;
      display_end_attack(msg, unit, targ, board);
    }
}

void	try_ia_move(char **board, t_coords *pos, t_coords *target, t_sdl *sdl)
{
  int	msg;
  int	dir;
  int	unit;

  msg = 0;
  dir = 0;
  if (((dir = can_move(board, pos->y, pos->x, target)) > 0 &&
       board[pos->y][pos->x + 2] % 2 == 0) ||
      has_to_move(board, pos->y, pos->x, &dir))
    {
      unit = board[pos->y][pos->x];
      msg = move_unit(sdl, pos->y, pos->x, dir);
      if (msg == 1)
	printf("%d has moved of 1 to %s\n", unit, ((dir == 1) ? (strdup("top")) : (dir == 2) ? (strdup("right")) : (dir == 3) ? (strdup("bottom")) : (strdup("left"))));
      else
	my_putstr("There is an error on your command\n");
    }
}
