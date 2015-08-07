/*
** display_board.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/II : Path of Radiance
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 11:07:06 2015 Jean BARRIERE
** Last update Sun May 17 18:51:06 2015 guillaume wilmot
*/

#include "sdl.h"

void	display_line(char *str, int delay)
{
  int	i;

  i = 0;
  while (str && str[i] != -1)
    {
      if (str[i] > 10 && str[i] <= 40)
	my_putstr("\033[01;34m");
      else if (str[i] > 40 && str[i] <= 70)
	my_putstr("\033[01;31m");
      my_put_nbr((int)str[i]);
      if (str[i] < 10)
	my_putchar(' ');
      if (str[i] > 10 && str[i] <= 70)
	my_putstr("\033[0m");
      if (str[i + 1] != -1)
	my_putchar(' ');
      i += delay;
    }
  my_putchar('\n');
}

void	display_board(char **board, int delay)
{
  int	i;

  i = 0;
  while (board && board[i] != NULL)
    {
      display_line(board[i], delay);
      ++i;
    }
}

void	display_content(char **map, char *file)
{
  int	x;
  int	y;
  char	*name;

  y = 0;
  name = get_file_name(file);
  my_printf("The %s is %d on %d\n", name, my_strlen(map[0]), tab_len(map));
  free(name);
  while (map && map[y] != NULL)
    {
      x = 0;
      while (map[y] && map[y][x] != -1)
	{
	  if (map[y][x] >= 11 && map[y][x] <= 40)
	    my_printf("The blue unit %d is in %d/%d\n", map[y][x], y, x / 3);
	  else if (map[y][x] >= 41 && map[y][x] <= 70)
	    my_printf("The red unit %d is in %d/%d\n", map[y][x], y, x / 3);
	  x += 3;
	}
      ++y;
    }
}
