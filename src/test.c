/*
** test.c for test in /home/wilmot_g/Rush3/SDL_Tests
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 16 21:42:39 2015 guillaume wilmot
** Last update Sun May 17 23:08:32 2015 Jean BARRIERE
*/

#include "sdl.h"

void		put_unit(t_anims *anims, t_assets *assets,
			 t_coords coords, char **map)
{
  SDL_Surface	*unit;
  SDL_Rect	pos;

  pos.x = 80 + ((coords.x / 3 - 1) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((coords.y - 1) * ((WIN_Y - 286) / (assets->length)));
  if (map[coords.y][coords.x] > 10 && map[coords.y][coords.x] <= 30)
    unit = (map[coords.y][coords.x] <= 20) ?
      anims->blue_b.stand[0] : anims->blue_s.stand[0];
  if (map[coords.y][coords.x] > 30 && map[coords.y][coords.x] <= 50)
    unit = (map[coords.y][coords.x] <= 40) ?
      anims->blue_k.stand[0] : anims->red_b.stand[0];
  if (map[coords.y][coords.x] > 50 && map[coords.y][coords.x] <= 70)
    unit = (map[coords.y][coords.x] <= 60) ?
      anims->red_s.stand[0] : anims->red_k.stand[0];
  SDL_BlitSurface(unit, NULL, assets->bg2, &pos);
}

void		put_health(t_assets *assets,
			 t_coords coords, char **map)
{
  t_coords	pos;
  int		i;

  pos.x = 80 + ((coords.x / 3 - 1) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((coords.y - 1) * ((WIN_Y - 286) / (assets->length)));
  pos.x2 = pos.x + 65;
  pos.y2 = 143 + ((coords.y - 1) * ((WIN_Y - 286) / (assets->length)));
  i = 0;
  while (i++ < 4)
    {
      draw_line(pos, assets->bg2, SDL_MapRGB(assets->bg2->format, 166, 0, 0));
      pos.y = ((pos.y2 = pos.y2 + 1) != -10) ? pos.y + 1 : pos.y + 1;
    }
  pos.x = 80 + ((coords.x / 3 - 1) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((coords.y - 1) * ((WIN_Y - 286) / (assets->length)));
  pos.x2 = pos.x + (65 * map[coords.y][coords.x + 1] / 30);
  pos.y2 = 143 + ((coords.y - 1) * ((WIN_Y - 286) / (assets->length)));
  i = 0;
  while (i++ < 4)
    {
      draw_line(pos, assets->bg2, SDL_MapRGB(assets->bg2->format, 0, 220, 0));
      pos.y = ((pos.y2 = pos.y2 + 1) != -10) ? pos.y + 1 : pos.y + 1;
    }
}

int		init_get_bg(char **map, t_assets *assets, t_anims *anims,
			    t_coords except)
{
  t_coords	coords;
  int		y;
  int		x;

  y = 0;
  SDL_BlitSurface(assets->bg, NULL, assets->bg2, NULL);
  while (map && map[y])
    {
      x = 0;
      while (map[y][x] != -1)
	{
	  if (map[y][x] > 10 && map[y][x] <= 70 &&
	      (x != except.x || y != except.y))
	    {
	      coords.x = x;
	      coords.y = y;
	      put_unit(anims, assets, coords, map);
	      put_health(assets, coords, map);
	    }
	  x += 3;
	}
      y++;
    }
  return (1);
}

int		test(t_anims *anims, char **map, t_assets *assets, char *file)
{
  t_sdl		sdl;
  t_coords	coords;

  coords.x = 0;
  coords.y = 0;
  display_board(map, 3);
  if (!init_draw_board(map, &assets->bg, assets))
    return (my_puterr_int("Could not draw board, aborted\n", 0));
  assets->bg2 = SDL_CreateRGBSurface(SDL_HWSURFACE, WIN_X, WIN_Y, BPP,
				     0, 0, 0, 0);
  if (!init_get_bg(map, assets, anims, coords))
    return (my_puterr_int("Could not draw board, aborted\n", 0));
  SDL_BlitSurface(assets->bg2, NULL, assets->screen, NULL);
  SDL_Flip(assets->screen);
  sdl.assets = assets;
  sdl.anims = anims;
  sdl.file = file;
  return (radiance(map, 0, &sdl, &coords));
}
