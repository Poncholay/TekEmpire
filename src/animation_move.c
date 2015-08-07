/*
** animation_move.c for animation_move in /home/wilmot_g/Rush3/SDL_Tests/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 17 03:19:53 2015 guillaume wilmot
** Last update Sun May 17 23:26:24 2015 Jean BARRIERE
*/

#include "sdl.h"

int		do_mtop(t_anims *anims, t_assets *assets, int event[3],
			char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.mtop : anims->blue_s.mtop;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.mtop : anims->red_b.mtop;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.mtop : anims->red_k.mtop;
  return (loop_animation_mtop(pos, event, assets, gif));
}

int		do_mdown(t_anims *anims, t_assets *assets, int event[3],
			 char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.mdown : anims->blue_s.mdown;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.mdown : anims->red_b.mdown;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.mdown : anims->red_k.mdown;
  return (loop_animation_mdown(pos, event, assets, gif));
}

int		do_mright(t_anims *anims, t_assets *assets, int event[3],
			  char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.mright : anims->blue_s.mright;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.mright : anims->red_b.mright;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.mright : anims->red_k.mright;
  return (loop_animation_mright(pos, event, assets, gif));
}

int		do_mleft(t_anims *anims, t_assets *assets, int event[3],
			 char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.mleft : anims->blue_s.mleft;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.mleft : anims->red_b.mleft;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.mleft : anims->red_k.mleft;
  return (loop_animation_mleft(pos, event, assets, gif));
}

int		do_stand(t_anims *anims, t_assets *assets, int event[3],
			 char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.stand : anims->blue_s.stand;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.stand : anims->red_b.stand;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.stand : anims->red_k.stand;
  return (loop_animation(pos, event, assets, gif));
}
