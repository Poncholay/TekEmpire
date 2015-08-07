/*
** loop_animation.c for loop_animation in /home/wilmot_g/Rush3/SDL_Tests/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 17 09:13:39 2015 guillaume wilmot
** Last update Sun May 17 23:08:19 2015 Jean BARRIERE
*/

#include "sdl.h"

int	loop_animation(SDL_Rect pos, UNUSED int event[3], t_assets *assets,
		       SDL_Surface **gif)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (i < 50)
    {
      SDL_BlitSurface(assets->bg2, NULL, assets->screen, NULL);
      SDL_BlitSurface(gif[j], NULL, assets->screen, &pos);
      SDL_Flip(assets->screen);
      usleep(10000);
      i++;
      j = (i % 5 == 0) ? j + 1 : j;
    }
  return (0);
}
