/*
** ia.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/IV : Awakening
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 19:57:06 2015 Jean BARRIERE
** Last update Sun May 17 23:22:13 2015 Jean BARRIERE
*/

#include "sdl.h"

int	is_my_unit(char c, int flag)
{
  if ((flag == 1 && c >= 41 && c <= 70) || (flag == 0 && c >= 11 && c <= 40))
    return (1);
  return (0);
}

int	can_move(char **board, int y, int x, t_coords *pos)
{
  int	dir;

  dir = 0;
  if (x > pos->x && board[y][x - 3] == 0)
    dir = 4;
  else if (x < pos->x && board[y][x + 3] == 0)
    dir = 2;
  else
    {
      if (y > pos->y && board[y - 1][x] == 0)
	dir = 1;
      else if (y < pos->y && board[y + 1][x] == 0)
	dir = 3;
    }
  return (dir);
}

void		play_unit(char **board, int y, int x, t_sdl *sdl)
{
  t_coords	*target;
  t_coords	pos;
  int		unit;

  sdl->map = board;
  pos.y = y;
  pos.x = x;
  unit = board[y][x];
  target = get_enemy_closer(board, y, x);
  if (target == NULL)
    target = get_ia_target(board, &pos);
  try_ia_attack(board, &pos, target, sdl);
  try_ia_move(board, &pos, target, sdl);
  free(target);
  target = get_target_pos(board, unit);
  pos.y = target->y;
  pos.x = target->x;
  free(target);
  target = get_enemy_closer(board, y, x);
  if (target == NULL)
    target = get_ia_target(board, &pos);
  try_ia_attack(board, &pos, target, sdl);
  free(target);
}

void	play_as(char **board, int flag, t_sdl *sdl)
{
  int	y;
  int	x;
  int	prev_unit;

  y = 0;
  prev_unit = 0;
  while (board && board[y] != NULL)
    {
      x = 0;
      while (board[y] && board[y][x] != -1)
	{
	  if (is_my_unit(board[y][x], flag) && board[y][x] != prev_unit)
	    {
	      prev_unit = board[y][x];
	      play_unit(board, y, x, sdl);
	    }
	  x += 3;
	}
      ++y;
    }
}

void	play_ia(char **board, int *flag, t_sdl *sdl)
{
  play_as(board, *flag, sdl);
  *flag = ((*flag == 0) ? (1) : (0));
  reinit_board(board, *flag);
  display_board(board, 3);
}
