/*
** animate.c for animate in /home/wilmot_g/Rush3/SDL_Tests/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 17 02:20:00 2015 guillaume wilmot
** Last update Sun May 17 23:08:06 2015 Jean BARRIERE
*/

#include "sdl.h"

int	loop_animation_mtop(SDL_Rect pos, int event[3], t_assets *assets,
			    SDL_Surface **gif)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < 50)
    {
      pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)))
	- ((float)i / 50) * ((WIN_Y - 286) / (assets->length));
      SDL_BlitSurface(assets->bg2, NULL, assets->screen, NULL);
      SDL_BlitSurface(gif[j], NULL, assets->screen, &pos);
      SDL_Flip(assets->screen);
      usleep(10000);
      i++;
      j = (i % 5 == 0) ? j + 1 : j;
    }
  return (0);
}

int	loop_animation_mdown(SDL_Rect pos, int event[3], t_assets *assets,
			     SDL_Surface **gif)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < 50)
    {
      pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)))
	+ ((float)i / 50) * ((WIN_Y - 286) / (assets->length));
      SDL_BlitSurface(assets->bg2, NULL, assets->screen, NULL);
      SDL_BlitSurface(gif[j], NULL, assets->screen, &pos);
      SDL_Flip(assets->screen);
      usleep(10000);
      i++;
      j = (i % 5 == 0) ? j + 1 : j;
    }
  return (0);
}

int	loop_animation_mright(SDL_Rect pos, int event[3], t_assets *assets,
			      SDL_Surface **gif)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < 50)
    {
      pos.x = 80 + ((event[0] / 3 - 1 + 0.2) *
		    ((WIN_X - 160) /(assets->width)))
	+ ((float)i / 50) * ((WIN_X - 160) / (assets->width));
      SDL_BlitSurface(assets->bg2, NULL, assets->screen, NULL);
      SDL_BlitSurface(gif[j], NULL, assets->screen, &pos);
      SDL_Flip(assets->screen);
      usleep(10000);
      i++;
      j = (i % 5 == 0) ? j + 1 : j;
    }
  return (0);
}

int	loop_animation_mleft(SDL_Rect pos, int event[3], t_assets *assets,
			     SDL_Surface **gif)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < 50)
    {
      pos.x = 80 + ((event[0] / 3 - 1 + 0.2) *
		    ((WIN_X - 160) /(assets->width)))
	- ((float)i / 50) * ((WIN_X - 160) / (assets->width));
      SDL_BlitSurface(assets->bg2, NULL, assets->screen, NULL);
      SDL_BlitSurface(gif[j], NULL, assets->screen, &pos);
      SDL_Flip(assets->screen);
      usleep(10000);
      i++;
      j = (i % 5 == 0) ? j + 1 : j;
    }
  return (0);
}

int		animate_units(t_anims *anims, char **map,
		      t_assets *assets, int event[3])
{
  int		(*fptr[10])(t_anims *anims, t_assets *assets, int event[3],
			    char **map);
  t_coords	coords;

  coords.x = event[0];
  coords.y = event[1];
  if (!init_get_bg(map, assets, anims, coords))
    return (my_puterr_int("Could not get background, aborted\n", 0));
  fptr[0] = &do_mtop;
  fptr[1] = &do_mright;
  fptr[2] = &do_mdown;
  fptr[3] = &do_mleft;
  fptr[4] = &do_atop;
  fptr[5] = &do_adown;
  fptr[6] = &do_aright;
  fptr[7] = &do_aleft;
  fptr[8] = &do_die;
  fptr[9] = &do_stand;
  fptr[event[2]](anims, assets, event, map);
  SDL_BlitSurface(assets->bg2, NULL, assets->screen, NULL);
  SDL_Flip(assets->screen);
  return (1);
}
