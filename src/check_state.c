/*
** check_state.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/IV : Awakening
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 21:42:55 2015 Jean BARRIERE
** Last update Sun May 17 14:34:21 2015 Jean BARRIERE
*/

#include "sdl.h"

int	is_enemy(char unit, char target)
{
  if ((unit >= 11 && unit <= 40 && target >= 41 && target <= 70) ||
      (unit >= 41 && unit <= 70 && target >= 11 && target <= 40))
    return (1);
  return (0);
}

int	coef_by_type(char unit, char target)
{
  if (get_damage(unit, target, NULL) == 15)
    return (5);
  return (6);
}

double		my_size(t_coords *tmp, t_coords *pos)
{
  double	ret;
  int		i;
  double	nb;

  nb = (tmp->x - pos->x) * (tmp->x - pos->x);
  nb += ((tmp->y - pos->y) * (tmp->y - pos->y));
  ret = ((nb < 0) ? ((double)-1) : ((double)2));
  i = 0;
  if (ret > 0)
    while (i < 10)
	{
	  ret = ((nb - ret * ret) / (2 * ret)) + ret;
	  ++i;
	}
  return (ret);
}

void		get_value(char **board, t_coords *pos, t_coords *tmp,
			  t_coords *new)
{
  double	value_new;
  double	value_tmp;

  value_tmp = my_size(tmp, pos);
  value_tmp *= (double)board[tmp->y][tmp->x + 1];
  value_tmp *= (double)coef_by_type(board[pos->y][pos->x],
				    board[tmp->y][tmp->x]);
  value_new = my_size(tmp, pos);
  value_new *= (double)board[new->y][new->x + 1];
  value_new /= (double)coef_by_type(board[pos->y][pos->x],
				    board[new->y][new->x]);
  if ((value_new > value_tmp && value_tmp > 0) ||
      (new->x == 0 && new->y == 0))
    {
      new->y = tmp->y;
      new->x = tmp->x;
    }
}

t_coords	*get_ia_target(char **board, t_coords *pos)
{
  t_coords	*ret;
  t_coords	tmp;

  if ((ret = malloc(sizeof(t_coords))) == NULL)
    return (my_puterr("Error: cannot perform malloc\n", NULL));
  ret->y = 0;
  ret->x = 0;
  tmp.y = 0;
  while (board && board[tmp.y] != NULL)
    {
      tmp.x = 0;
      while (board[tmp.y] && board[tmp.y][tmp.x] != -1)
	{
	  if (is_enemy(board[pos->y][pos->x], board[tmp.y][tmp.x]))
	    get_value(board, pos, &tmp, ret);
	  tmp.x += 3;
	}
      ++tmp.y;
    }
  return (ret);
}
