/*
** move.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/II : Path of Radiance
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 14:49:04 2015 Jean BARRIERE
** Last update Sun May 17 19:53:38 2015 guillaume wilmot
*/

#include "sdl.h"

t_coords	*get_target_pos(char **board, int target)
{
  t_coords	*ret;
  int		y;
  int		x;

  if ((ret = malloc(sizeof(t_coords))) == NULL)
    return (my_puterr("Error: cannot perform malloc\n", NULL));
  ret->x = 0;
  ret->y = 0;
  y = 0;
  while (board && board[y] != NULL && ret->x == 0)
    {
      x = 0;
      while (board[y][x] != -1 && ret->x == 0)
	{
	  if (board[y][x] == target)
	    {
	      ret->x = x;
	      ret->y = y;
	    }
	  x += 3;
	}
      ++y;
    }
  return (ret);
}

t_coords	*get_pos_by_target(int y, int x, t_coords *pos)
{
  t_coords	*ret;

  if ((ret = malloc(sizeof(t_coords))) == NULL)
    return (my_puterr("Error: cannot perform malloc\n", NULL));
  ret->x = x - pos->x;
  ret->y = y - pos->y;
  return (ret);
}

int		access_target(t_sdl *sdl, t_coords *upos, int unit,
			      int target)
{
  t_coords	*pos;
  t_coords	*pos_tar;
  int		ret;

  pos_tar = ((ret = 0) == 0) ? get_target_pos(sdl->map, target) : NULL;
  pos = get_pos_by_target(upos->y, upos->x, pos_tar);
  if (((pos->x == 3 || pos->x == -3) && pos->y == 0) ||
      ((pos->y == 1 || pos->y == -1) && pos->x == 0))
    {
      animate_units(sdl->anims, sdl->map, sdl->assets,
		    get_event(unit, target, sdl->map, 1));
      sdl->map[upos->y][upos->x + 2] += 2;
      sdl->map[pos_tar->y][pos_tar->x + 1] -= get_damage(unit, target, &ret);
    }
  if (sdl->map[pos_tar->y][pos_tar->x + 1] <= 0 && ++ret > 0)
    {
      animate_units(sdl->anims, sdl->map, sdl->assets,
		    get_event(target, unit, sdl->map, 2));
      sdl->map[pos_tar->y][pos_tar->x] = 0;
      sdl->map[pos_tar->y][pos_tar->x + 1] = 0;
      sdl->map[pos_tar->y][pos_tar->x + 2] = 0;
    }
  free(pos);
  free(pos_tar);
  return (((ret == 0) ? (-1) : (ret)));
}

int	display_end_attack(int msg, int unit, int target, char **board)
{
  if (msg == 1)
    {
      my_printf("%d has attacked of %d %d. %d is %d hp now\n", unit,
		get_damage(unit, target, NULL), target, target,
		get_hp(board, target));
      return (1);
    }
  else if (msg == 2)
    {
      my_printf("%d has attacked of %d %d. The %d is dead\n", unit,
		get_damage(unit, target, NULL), target, target);
      return (2);
    }
  else
    my_putstr("There is an error on your command\n");
  return (0);
}

void		try_attack(int unit, int target, char **board, t_sdl *sdl)
{
  t_coords	pos;
  int		msg;

  pos.y = 0;
  msg = 0;
  while (board && board[pos.y] != NULL && msg == 0)
    {
      pos.x = 0;
      while (board[pos.y][pos.x] != -1 && msg == 0)
	{
	  if (board[pos.y][pos.x] == unit && (board[pos.y][pos.x + 2] == 0 ||
					      board[pos.y][pos.x + 2] == 1))
	    {
	      sdl->map = board;
	      msg = access_target(sdl, &pos, unit, target);
	      board = sdl->map;
	    }
	  pos.x += 3;
	}
      ++pos.y;
    }
  display_end_attack(msg, unit, target, board);
}
