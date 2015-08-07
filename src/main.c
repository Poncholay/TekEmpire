/*
** main.c for main in /home/wilmot_g/Rush3/SDL_Tests/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 16 20:45:45 2015 guillaume wilmot
** Last update Sun May 17 18:54:54 2015 guillaume wilmot
*/

#include "sdl.h"

int		get_anims_red_k(t_gifs *gifs)
{
  if (get_gif("assets/knight/red/attack/top/k", gifs->atop) == NULL ||
      get_gif("assets/knight/red/attack/bottom/k", gifs->adown) == NULL ||
      get_gif("assets/knight/red/attack/right/k", gifs->aright) == NULL ||
      get_gif("assets/knight/red/attack/left/k", gifs->aleft) == NULL ||
      get_gif("assets/knight/red/move/top/k", gifs->mtop) == NULL ||
      get_gif("assets/knight/red/move/bottom/k", gifs->mdown) == NULL ||
      get_gif("assets/knight/red/move/right/k", gifs->mright) == NULL ||
      get_gif("assets/knight/red/move/left/k", gifs->mleft) == NULL ||
      get_gif("assets/knight/red/die/k", gifs->die) == NULL ||
      get_gif("assets/knight/red/stand/k", gifs->stand) == NULL)
    return (my_puterr_int("A red knight sprite is missing\n", 0));
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

int		get_anims_red_b(t_gifs *gifs)
{
  if (get_gif("assets/bowman/red/attack/top/b", gifs->atop) == NULL ||
      get_gif("assets/bowman/red/attack/bottom/b", gifs->adown) == NULL ||
      get_gif("assets/bowman/red/attack/right/b", gifs->aright) == NULL ||
      get_gif("assets/bowman/red/attack/left/b", gifs->aleft) == NULL ||
      get_gif("assets/bowman/red/move/top/b", gifs->mtop) == NULL ||
      get_gif("assets/bowman/red/move/bottom/b", gifs->mdown) == NULL ||
      get_gif("assets/bowman/red/move/right/b", gifs->mright) == NULL ||
      get_gif("assets/bowman/red/move/left/b", gifs->mleft) == NULL ||
      get_gif("assets/bowman/red/die/b", gifs->die) == NULL ||
      get_gif("assets/bowman/red/stand/b", gifs->stand) == NULL)
    return (my_puterr_int("A red bowman sprite is missing\n", 0));
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

int		get_anims_red_s(t_gifs *gifs)
{
  if (get_gif("assets/soldier/red/attack/top/s", gifs->atop) == NULL ||
      get_gif("assets/soldier/red/attack/bottom/s", gifs->adown) == NULL ||
      get_gif("assets/soldier/red/attack/right/s", gifs->aright) == NULL ||
      get_gif("assets/soldier/red/attack/left/s", gifs->aleft) == NULL ||
      get_gif("assets/soldier/red/move/top/s", gifs->mtop) == NULL ||
      get_gif("assets/soldier/red/move/bottom/s", gifs->mdown) == NULL ||
      get_gif("assets/soldier/red/move/right/s", gifs->mright) == NULL ||
      get_gif("assets/soldier/red/move/left/s", gifs->mleft) == NULL ||
      get_gif("assets/soldier/red/die/s", gifs->die) == NULL ||
      get_gif("assets/soldier/red/stand/s", gifs->stand) == NULL)
    return (my_puterr_int("A red soldier sprite is missing\n", 0));
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

int		get_anims(t_anims *anims, t_assets *assets)
{
  if (!get_anims_red_k(&anims->red_k) ||
      !get_anims_red_b(&anims->red_b) ||
      !get_anims_red_s(&anims->red_s) ||
      !get_anims_blue_k(&anims->blue_k) ||
      !get_anims_blue_b(&anims->blue_b) ||
      !get_anims_blue_s(&anims->blue_s))
    return (0);
  if (!get_assets(assets))
    return (0);
  return (1);
}

int		main(int argc, char **argv)
{
  char		**tab;
  char		**board;
  int		fd;
  t_assets	assets;
  t_anims	anims;

  if (argc ==  1 || !check_map(argv[1]))
    return (my_puterr_int("Usage: ./playRadiance [file.map]\n", 1));
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    return (my_puterr_int("Error: open failed\n", 1));
  if (!get_anims(&anims, &assets))
    return (my_puterr_int("Could not get the anims\n", -1));
  tab = get_map(fd);
  close(fd);
  board = create_board(tab);
  free_double_tab(tab);
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (my_puterr_int("Can't init SDL\n", -1));
  if ((assets.screen = SDL_SetVideoMode(WIN_X, WIN_Y, BPP, SDL_HWSURFACE))
      == NULL)
    return (my_puterr_int("Can't set video mode\n", -1));
  SDL_WM_SetCaption("Tek Empires", NULL);
  fd = test(&anims, board, &assets, argv[1]);
  free_double_tab(board);
  return (fd);
}
