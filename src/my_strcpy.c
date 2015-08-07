/*
** my_strcpy.c for my_strcpy in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 23:36:49 2015 guillaume wilmot
** Last update Sat May 16 14:06:09 2015 guillaume wilmot
*/

#include "sdl.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
