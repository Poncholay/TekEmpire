/*
** my_strdup.c for my_strdup in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 23:36:31 2015 guillaume wilmot
** Last update Sat May 16 14:07:13 2015 guillaume wilmot
*/

#include "sdl.h"

char	*my_strdup(char *str)
{
  char	*dest;

  if (str == NULL)
    return (NULL);
  if ((dest = malloc((my_strlen(str) + 1) * sizeof(char *))) == NULL)
    return (my_puterr("Malloc : error\n", NULL));
  my_strcpy(dest, str);
  dest[my_strlen(str)] = '\0';
  return (dest);
}
