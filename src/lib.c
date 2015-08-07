/*
** lib.c for lib in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 23:26:31 2015 guillaume wilmot
** Last update Sat May 16 22:20:52 2015 guillaume wilmot
*/

#include "sdl.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != 0)
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
