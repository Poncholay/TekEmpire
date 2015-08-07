/*
** my_puterr.c for my_puterr in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 21:37:34 2015 guillaume wilmot
** Last update Sat May 16 14:07:50 2015 guillaume wilmot
*/

#include "sdl.h"

void	*my_puterr(char *error, void *value)
{
  write(2, error, my_strlen(error));
  return (value);
}

int	my_puterr_int(char *error, int value)
{
  write(2, error, my_strlen(error));
  return (value);
}
