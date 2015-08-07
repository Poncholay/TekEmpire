/*
** ia_update.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/IV : Awakening
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sun May 17 02:18:13 2015 Jean BARRIERE
** Last update Sun May 17 23:35:14 2015 Jean BARRIERE
*/

#include "sdl.h"

int	enemy_around(char **board, int y, int x)
{
  int	flag;

  flag = ((is_my_unit(board[y][x], 0)) ? (1) : (0));
  if (is_my_unit(board[y - 1][x], flag))
    return (3);
  if (is_my_unit(board[y][x + 3], flag))
    return (4);
  if (is_my_unit(board[y + 1][x], flag))
    return (1);
  if (is_my_unit(board[y][x - 3], flag))
    return (2);
  return (0);
}

t_coords	*get_enemy_closer(char **board, int y, int x)
{
  t_coords	*ret;
  int		dir;

  if ((ret = malloc(sizeof(t_coords))) == NULL)
    return (my_puterr("Error: cannot perform malloc\n", NULL));
  ret->y = y;
  ret->x = x;
  dir = enemy_around(board, y, x);
  if (dir == 1 || dir == 3)
    ret->y += ((dir == 1) ? (1) : (-1));
  else if (dir == 2 || dir == 4)
    ret->x += ((dir == 2) ? (-3) : (3));
  else
    free(ret);
  return (((dir == 0) ? (NULL) : (ret)));
}

int	friend_around(char **board, int y, int x)
{
  int	flag;

  flag = ((is_my_unit(board[y][x], 0)) ? (0) : (1));
  if (is_my_unit(board[y - 1][x], flag))
    return (((enemy_around(board, y, x) == 3) ? (2) :
	     (enemy_around(board, y, x))));
  if (is_my_unit(board[y][x + 3], flag))
    return (((enemy_around(board, y, x) == 4) ? (1) :
	     (enemy_around(board, y, x))));
  if (is_my_unit(board[y + 1][x], flag))
    return (((enemy_around(board, y, x) == 1) ? (4) :
	     (enemy_around(board, y, x))));
  if (is_my_unit(board[y][x - 3], flag))
    return (((enemy_around(board, y, x) == 2) ? (3) :
	     (enemy_around(board, y, x))));
  return (0);
}

int	has_to_move(char **board, int y, int x, int *dir)
{
  if (friend_around(board, y, x) > 0 && enemy_around(board, y, x) > 0)
    {
      *dir = friend_around(board, y, x);
      return (1);
    }
  else if (get_hp(board, board[y][x]) <= 5 && enemy_around(board, y, x) > 0)
    {
      *dir = enemy_around(board, y, x);
      return (1);
    }
  return (0);
}
