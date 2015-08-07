/*
** draw_functs.c for draw_functs in /home/wilmot_g/.ssh/CPE_2014_lemin/bonuslemin
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat Apr 25 17:12:47 2015 guillaume wilmot
** Last update Sun May 17 04:03:29 2015 guillaume wilmot
*/

#include "sdl.h"

int	draw_cas_un(t_coords coords, SDL_Surface *screen, Uint32 color)
{
  int	x;

  x = coords.x;
  while (x <= coords.x2)
    {
      if (coords.x2 - coords.x != 0)
	putpixel(screen, x, coords.y + ((coords.y2 - coords.y) *
					 (x - coords.x)) /
		 (coords.x2 - coords.x), color);
      x++;
    }
  return (0);
}

int	draw_cas_deux(t_coords coords, SDL_Surface *screen, Uint32 color)
{
  int	y;

  y = coords.y;
  while (y <= coords.y2)
    {
      if (coords.y2 - coords.y != 0)
	putpixel(screen, coords.x + ((coords.x2 - coords.x) *
					 (y - coords.y)) /
		 (coords.y2 - coords.y), y, color);
      y++;
    }
  return (0);
}

void	putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  int	bpp;
  Uint8	*p;

  bpp = surface->format->BytesPerPixel;
  p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
  if (bpp == 1)
    *p = pixel;
  else if (bpp == 2)
    *(Uint16 *)p = pixel;
  else if (bpp == 3)
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
      {
        p[0] = (pixel >> 16) & 0xff;
        p[1] = (pixel >> 8) & 0xff;
        p[2] = pixel & 0xff;
      }
    else
      {
        p[0] = pixel & 0xff;
        p[1] = (pixel >> 8) & 0xff;
        p[2] = (pixel >> 16) & 0xff;
      }
  else if (bpp == 4)
    *(Uint32 *)p = pixel;
}

void	swap(t_coords *coords)
{
  int	tmp;

  tmp = coords->x;
  coords->x = coords->x2;
  coords->x2 = tmp;
  tmp = coords->y;
  coords->y = coords->y2;
  coords->y2 = tmp;
}

void		draw_line(t_coords coords, SDL_Surface *screen, Uint32 color)
{
  if (coords.x <= coords.x2 && (coords.x2 - coords.x) >=
       abs(coords.y2 - coords.y))
    draw_cas_un(coords, screen, color);
  else if (coords.x > coords.x2 && abs(coords.x2 - coords.x) >=
      abs(coords.y2 - coords.y))
    {
      swap(&coords);
      draw_cas_un(coords, screen, color);
    }
  else if ((coords.y2 - coords.y) >= 0 && abs(coords.x2 - coords.x) <=
       abs(coords.y2 - coords.y))
    draw_cas_deux(coords, screen, color);
  else
    {
      swap(&coords);
      draw_cas_deux(coords, screen, color);
    }
}
