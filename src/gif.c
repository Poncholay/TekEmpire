/*
** gif.c for gif in /home/wilmot_g/Rush3/SDL_Tests
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 16 13:32:38 2015 guillaume wilmot
** Last update Mon Jun 15 19:34:24 2015 guillaume wilmot
*/

#include "sdl.h"

char		*get_gif(char *name, SDL_Surface *gif[11])
{
  int		i;
  char		*tmp;
  char		*tmp2;

  i = 0;
  if ((tmp2 = malloc((my_strlen(name) + 6) * sizeof(char))) == NULL)
    return (NULL);
  my_strcpy(tmp2, name);
  if ((tmp = concatenate(tmp2, ".bmp", ' ')) == NULL)
    return (NULL);
  free(tmp2);
  while (i < 10)
    {
      tmp[my_strlen(name)] = i + 48;
      if ((gif[i] = SDL_LoadBMP(tmp)) == NULL)
	{
	  my_fprintf("%s is missing\n", tmp);
	  free(tmp);
	  return (NULL);
	}
      i++;
    }
  gif[i] = '\0';
  free(tmp);
  return ("OK");
}

void		put_transparency(SDL_Surface *gif[11])
{
  int		i;

  i = 0;
  while (gif[i])
    {
      SDL_SetColorKey(gif[i], SDL_SRCCOLORKEY, SDL_MapRGB(gif[i]->format, 255,
							  0, 255));
      i++;
    }
}

int		events(int i)
{
  SDL_Event     ev;

  ev.type = 0;
  while (i)
    {
      SDL_PollEvent(&ev);
      if ((ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_ESCAPE) ||
          ev.type == SDL_QUIT)
	return (0);
    }
  SDL_PollEvent(&ev);
  if ((ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_ESCAPE) ||
      ev.type == SDL_QUIT)
    return (0);
  return (1);
}

SDL_Rect	pos(int x, int y)
{
  SDL_Rect	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}
