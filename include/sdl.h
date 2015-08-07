/*
** strategic.h for strategic.h in /home/wilmot_g/.ssh/BocalEmblem/I : The Sacred Stones/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 16 02:49:03 2015 guillaume wilmot
** Last update Sun May 17 15:18:15 2015 guillaume wilmot
*/

#ifndef SDL_H_
# define SDL_H_

/*
** INCLUDES
*/
# include <SDL/SDL.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

/*
** STRUCTURES
*/
typedef struct  s_gifs
{
  SDL_Surface	*mtop[11];
  SDL_Surface	*mdown[11];
  SDL_Surface	*mright[11];
  SDL_Surface	*mleft[11];
  SDL_Surface	*atop[11];
  SDL_Surface	*adown[11];
  SDL_Surface	*aright[11];
  SDL_Surface	*aleft[11];
  SDL_Surface	*die[11];
  SDL_Surface	*stand[11];
}		t_gifs;

typedef struct  s_anims
{
  t_gifs	red_k;
  t_gifs	blue_k;
  t_gifs	red_b;
  t_gifs	blue_b;
  t_gifs	red_s;
  t_gifs	blue_s;
}               t_anims;

typedef struct  s_assets
{
  int		width;
  int		length;
  SDL_Surface	*bg;
  SDL_Surface	*bg2;
  SDL_Surface	*grass;
  SDL_Surface	*tree;
  SDL_Surface	*wall1;
  SDL_Surface	*wall2;
  SDL_Surface	*screen;
}               t_assets;

typedef	struct	s_coords
{
  int		x;
  int		x2;
  int		y;
  int		y2;

}		t_coords;

typedef struct  s_line
{
  int           x1;
  int           x2;
  int           y1;
  int           y2;
}		t_line;

typedef struct	s_sdl
{
  char		*file;
  char		**map;
  t_anims	*anims;
  t_assets	*assets;
}		t_sdl;

/*
** DEFINES
*/
# include "defines.h"

/*
** PROTOTYPES
*/
# include "types.h"

#endif /* !SDL_H_ */
