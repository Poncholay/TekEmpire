/*
** draw_board.c for draw_board in /home/wilmot_g/Rush3/SDL_Tests
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 16 22:48:39 2015 guillaume wilmot
** Last update Sun May 17 21:24:53 2015 Jean BARRIERE
*/

#include "sdl.h"

void		fill_bg(SDL_Surface *bg, t_assets *assets)
{
  SDL_Rect	pos;

  pos.y = 0;
  while (pos.y < WIN_Y)
    {
      pos.x = 0;
      while (pos.x < WIN_X)
	{
	  SDL_BlitSurface(assets->grass, NULL, bg, &pos);
	  pos.x += 64;
	}
      pos.y += 64;
    }
}

void		draw_grille_bis(SDL_Surface *bg, t_assets *assets)
{
  t_coords	coords;
  int		x;
  int		i;

  x = 0;
  while (x < assets->width - 1)
    {
      i = -1;
      while (i < 2)
	{
	  coords.x = 80 + (x + 1) * ((WIN_X - 160) / (assets->width)) + i;
	  coords.y = 143;
	  coords.x2 = 80 + (x + 1) * ((WIN_X - 160) / (assets->width)) + i;
	  coords.y2 = WIN_Y - 143;
	  draw_line(coords, bg, 0);
	  i++;
	}
      x++;
    }
}

void		draw_grille(SDL_Surface *bg, t_assets *assets)
{
  t_coords	coords;
  int		y;
  int		i;

  y = 0;
  while (y < assets->length - 1)
    {
      i = -1;
      while (i < 2)
	{
	  coords.x = 80;
	  coords.y = 143 + (y + 1) * ((WIN_Y - 286) / (assets->length)) + i;
	  coords.x2 = WIN_X - 80;
	  coords.y2 = 143 + (y + 1) * ((WIN_Y - 286) / (assets->length)) + i;
	  draw_line(coords, bg, 0);
	  i++;
	}
      y++;
    }
  draw_grille_bis(bg, assets);
}

void		draw_walls(SDL_Surface *bg, t_assets *assets)
{
  SDL_Rect	pos;

  pos.y = 0;
  pos.x = WIN_X - 50;
  while (pos.x > -70)
    {
      SDL_BlitSurface(assets->wall1, NULL, bg, &pos);
      pos.x -= 74;
    }
  while (pos.y < WIN_Y - 143)
    {
      pos.x = WIN_X - 100;
      SDL_BlitSurface(assets->wall2, NULL, bg, &pos);
      pos.x = -20;
      SDL_BlitSurface(assets->wall2, NULL, bg, &pos);
      pos.y += 50;
    }
  pos.y = WIN_Y - 140;
  pos.x = WIN_X - 50;
  while (pos.x > -70)
    {
      SDL_BlitSurface(assets->wall1, NULL, bg, &pos);
      pos.x -= 74;
    }
}

int		init_draw_board(char **map, SDL_Surface **bg, t_assets *assets)
{
  int	i;

  i = 0;
  while (map[0][i] != -1)
    i++;
  assets->width = i / 3 - 2;
  assets->length = tab_len(map) - 2;
  *bg = SDL_CreateRGBSurface(SDL_HWSURFACE, WIN_X, WIN_Y, BPP, 0, 0, 0, 0);
  fill_bg(*bg, assets);
  draw_grille(*bg, assets);
  draw_walls(*bg, assets);
  return (1);
}
