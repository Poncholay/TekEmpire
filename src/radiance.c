/*
** radiance.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/II : Path of Radiance
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 14:51:00 2015 Jean BARRIERE
** Last update Sun May 17 22:45:28 2015 Jean BARRIERE
*/

#include "sdl.h"

void	reinit_board(char **board, int turn)
{
  int	x;
  int	y;

  y = 0;
  while (board && board[y] != NULL)
    {
      x = 0;
      while (board[y][x] != -1)
	{
	  if (board[y][x] >= ((turn == 1) ? (11) : (41)) &&
	      board[y][x] <= ((turn == 1) ? (40) : (70)))
	    board[y][x + 2] = 0;
	  x += 3;
	}
      ++y;
    }
}

void	check_turn(char **board, int *turn, int x, int y)
{
  int	units;
  int	moved;

  units = 0;
  moved = 0;
  while (board && board[y] != NULL)
    {
      x = 0;
      while (board[y][x] != -1)
	{
	  if (board[y][x] >= ((*turn == 0) ? (11) : (41)) &&
	      board[y][x] <= ((*turn == 0) ? (40) : (70)))
	    ++units;
	  if (board[y][x] >= ((*turn == 0) ? (11) : (41)) &&
	      board[y][x] <= ((*turn == 0) ? (40) : (70)) &&
	      board[y][x + 2] == 3)
	    ++moved;
	  x += 3;
	}
      ++y;
    }
  if (units == moved)
      *turn = ((*turn == 0) ? (1) : (0));
  if (units == moved)
    reinit_board(board, *turn);
}

int	check_win(char **tab)
{
  t_coords	pos;
  int		bunit;
  int		runit;

  bunit = 0;
  runit = 0;
  pos.y = 0;
  while (tab && tab[pos.y] != NULL)
    {
      pos.x = 0;
      while (tab[pos.y] && tab[pos.y][pos.x] != -1)
	{
	  if (is_my_unit(tab[pos.y][pos.x], 0))
	    ++bunit;
	  else if (is_my_unit(tab[pos.y][pos.x], 1))
	    ++runit;
	  pos.x += 3;
	}
      ++pos.y;
    }
  if (bunit == 0 || runit == 0)
    my_printf("%s win this war.\n", ((bunit == 0) ? ("Red") : ("Blue")));
  return (((bunit == 0) ? (2) : (((runit == 0) ? (1) : (0)))));
}

int	exec_berserk(char **tab, int *turn, t_sdl *sdl, int turns)
{
  int		i;
  int		win;
  t_coords	coords;

  coords.x = 0;
  coords.y = 0;
  win = 0;
  i = ((turns == 0) ? (-1) : (0));
  while (i < turns && win == 0)
    {
      play_ia(tab, turn, sdl);
      play_ia(tab, turn, sdl);
      i += ((i > -1) ? (1) : (0));
      if (!init_get_bg(tab, sdl->assets, sdl->anims, coords))
	return (my_puterr_int("Could not draw board, aborted\n", 0));
      SDL_BlitSurface(sdl->assets->bg2, NULL, sdl->assets->screen, NULL);
      SDL_Flip(sdl->assets->screen);
      win = check_win(tab);
    }
  if (win == 0)
    write(1, ":>", 2);
  return (win);
}

int		radiance(char **tab, int turn, t_sdl *sdl, t_coords *coords)
{
  char		*line;
  int		win;

  win = 0;
  write(1, ":>", 2);
  while (win == 0 && (line = get_next_line(0)) != NULL && !match(line, "exit"))
    if (nmatch(line, "berserk", 7))
      win = exec_berserk(tab, &turn, sdl, my_atoi(&line[7]));
    else
      {
	exec_cmd(line, tab, &turn, sdl);
	free(line);
	check_turn(tab, &turn, 0, 0);
	if (turn == 1)
	  play_ia(tab, &turn, sdl);
	if ((win = check_win(tab)) == 0)
	  write(1, ":>", 2);
	if (!init_get_bg(tab, sdl->assets, sdl->anims, *coords))
	  return (my_puterr_int("Could not draw board, aborted\n", 0));
	SDL_BlitSurface(sdl->assets->bg2, NULL, sdl->assets->screen, NULL);
	SDL_Flip(sdl->assets->screen);
      }
  if (win == 0)
    free(line);
  return (win);
}
