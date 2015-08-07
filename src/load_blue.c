/*
** load_blue.c for load_blue in /home/wilmot_g/Rush3/SDL_Tests/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 16 21:07:26 2015 guillaume wilmot
** Last update Sun May 17 09:54:56 2015 guillaume wilmot
*/

#include "sdl.h"

int		get_anims_blue_k(t_gifs *gifs)
{
  if (get_gif("assets/knight/blue/attack/top/k", gifs->atop) == NULL ||
      get_gif("assets/knight/blue/attack/bottom/k", gifs->adown) == NULL ||
      get_gif("assets/knight/blue/attack/right/k", gifs->aright) == NULL ||
      get_gif("assets/knight/blue/attack/left/k", gifs->aleft) == NULL ||
      get_gif("assets/knight/blue/move/top/k", gifs->mtop) == NULL ||
      get_gif("assets/knight/blue/move/bottom/k", gifs->mdown) == NULL ||
      get_gif("assets/knight/blue/move/right/k", gifs->mright) == NULL ||
      get_gif("assets/knight/blue/move/left/k", gifs->mleft) == NULL ||
      get_gif("assets/knight/blue/die/k", gifs->die) == NULL ||
      get_gif("assets/knight/blue/stand/k", gifs->stand) == NULL)
    return (my_puterr_int("A blue knight sprite is missing\n", 0));
  put_transparency(gifs->atop);
  put_transparency(gifs->adown);
  put_transparency(gifs->aright);
  put_transparency(gifs->aleft);
  put_transparency(gifs->mtop);
  put_transparency(gifs->mdown);
  put_transparency(gifs->mright);
  put_transparency(gifs->mleft);
  put_transparency(gifs->die);
  put_transparency(gifs->stand);
  return (1);
}

int		get_anims_blue_b(t_gifs *gifs)
{
  if (get_gif("assets/bowman/blue/attack/top/b", gifs->atop) == NULL ||
      get_gif("assets/bowman/blue/attack/bottom/b", gifs->adown) == NULL ||
      get_gif("assets/bowman/blue/attack/right/b", gifs->aright) == NULL ||
      get_gif("assets/bowman/blue/attack/left/b", gifs->aleft) == NULL ||
      get_gif("assets/bowman/blue/move/top/b", gifs->mtop) == NULL ||
      get_gif("assets/bowman/blue/move/bottom/b", gifs->mdown) == NULL ||
      get_gif("assets/bowman/blue/move/right/b", gifs->mright) == NULL ||
      get_gif("assets/bowman/blue/move/left/b", gifs->mleft) == NULL ||
      get_gif("assets/bowman/blue/die/b", gifs->die) == NULL ||
      get_gif("assets/bowman/blue/stand/b", gifs->stand) == NULL)
    return (my_puterr_int("A blue bowman sprite is missing\n", 0));
  put_transparency(gifs->atop);
  put_transparency(gifs->adown);
  put_transparency(gifs->aright);
  put_transparency(gifs->aleft);
  put_transparency(gifs->mtop);
  put_transparency(gifs->mdown);
  put_transparency(gifs->mright);
  put_transparency(gifs->mleft);
  put_transparency(gifs->die);
  put_transparency(gifs->stand);
  return (1);
}

int		get_anims_blue_s(t_gifs *gifs)
{
  if (get_gif("assets/soldier/blue/attack/top/s", gifs->atop) == NULL ||
      get_gif("assets/soldier/blue/attack/bottom/s", gifs->adown) == NULL ||
      get_gif("assets/soldier/blue/attack/right/s", gifs->aright) == NULL ||
      get_gif("assets/soldier/blue/attack/left/s", gifs->aleft) == NULL ||
      get_gif("assets/soldier/blue/move/top/s", gifs->mtop) == NULL ||
      get_gif("assets/soldier/blue/move/bottom/s", gifs->mdown) == NULL ||
      get_gif("assets/soldier/blue/move/right/s", gifs->mright) == NULL ||
      get_gif("assets/soldier/blue/move/left/s", gifs->mleft) == NULL ||
      get_gif("assets/soldier/blue/die/s", gifs->die) == NULL ||
      get_gif("assets/soldier/blue/stand/s", gifs->stand) == NULL)
    return (my_puterr_int("A blue soldier sprite is missing\n", 0));
  put_transparency(gifs->atop);
  put_transparency(gifs->adown);
  put_transparency(gifs->aright);
  put_transparency(gifs->aleft);
  put_transparency(gifs->mtop);
  put_transparency(gifs->mdown);
  put_transparency(gifs->mright);
  put_transparency(gifs->mleft);
  put_transparency(gifs->die);
  put_transparency(gifs->stand);
  return (1);
}

int		get_assets(t_assets *assets)
{
  if ((assets->grass = SDL_LoadBMP("assets/textures/grass.bmp")) == NULL)
    return (my_puterr_int("grass.bmp is missing", 0));
  if ((assets->tree = SDL_LoadBMP("assets/textures/tree.bmp")) == NULL)
    return (my_puterr_int("tree.bmp is missing", 0));
  if ((assets->wall1 = SDL_LoadBMP("assets/textures/wall1.bmp")) == NULL)
    return (my_puterr_int("wall1.bmp is missing", 0));
  if ((assets->wall2 = SDL_LoadBMP("assets/textures/wall2.bmp")) == NULL)
    return (my_puterr_int("wall2.bmp is missing", 0));
  SDL_SetColorKey(assets->tree, SDL_SRCCOLORKEY,
		  SDL_MapRGB(assets->tree->format, 255, 0, 255));
  SDL_SetColorKey(assets->wall1, SDL_SRCCOLORKEY,
		  SDL_MapRGB(assets->tree->format, 255, 0, 255));
  SDL_SetColorKey(assets->wall2, SDL_SRCCOLORKEY,
		  SDL_MapRGB(assets->tree->format, 255, 0, 255));
  return (1);
}
