/*
** animation_fight.c for animation_fight in /home/wilmot_g/Rush3/SDL_Tests/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 17 03:20:09 2015 guillaume wilmot
** Last update Sun May 17 23:09:49 2015 Jean BARRIERE
*/

#include "sdl.h"

int		do_atop(t_anims *anims, t_assets *assets, int event[3],
			char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.atop : anims->blue_s.atop;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.atop : anims->red_b.atop;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.atop : anims->red_k.atop;
  return (loop_animation(pos, event, assets, gif));
}

int		do_adown(t_anims *anims, t_assets *assets, int event[3],
			 char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.adown : anims->blue_s.adown;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.adown : anims->red_b.adown;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.adown : anims->red_k.adown;
  return (loop_animation(pos, event, assets, gif));
}

int		do_aright(t_anims *anims, t_assets *assets, int event[3],
			  char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.aright : anims->blue_s.aright;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.aright : anims->red_b.aright;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.aright : anims->red_k.aright;
  return (loop_animation(pos, event, assets, gif));
}

int		do_aleft(t_anims *anims, t_assets *assets, int event[3],
			 char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.aleft : anims->blue_s.aleft;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.aleft : anims->red_b.aleft;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.aleft : anims->red_k.aleft;
  return (loop_animation(pos, event, assets, gif));
}

int		do_die(t_anims *anims, t_assets *assets, int event[3],
		       char **map)
{
  SDL_Surface	**gif;
  SDL_Rect	pos;

  pos.x = 80 + ((event[0] / 3 - 1 + 0.2) * ((WIN_X - 160) / (assets->width)));
  pos.y = 143 + ((event[1] - 1 - 0.2) * ((WIN_Y - 286) / (assets->length)));
  gif = anims->blue_b.stand;
  if (map[event[1]][event[0]] > 10 && map[event[1]][event[0]] <= 30)
    gif = (map[event[1]][event[0]] <= 20) ?
      anims->blue_b.die : anims->blue_s.die;
  if (map[event[1]][event[0]] > 30 && map[event[1]][event[0]] <= 50)
    gif = (map[event[1]][event[0]] <= 40) ?
      anims->blue_k.die : anims->red_b.die;
  if (map[event[1]][event[0]] > 50 && map[event[1]][event[0]] <= 70)
    gif = (map[event[1]][event[0]] <= 60) ?
      anims->red_s.die : anims->red_k.die;
  return (loop_animation(pos, event, assets, gif));
}
