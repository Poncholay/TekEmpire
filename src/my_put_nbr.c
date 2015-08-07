/*
** my_put_nbr.c for my_put_nbr in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 23:20:03 2015 guillaume wilmot
** Last update Sat May 16 22:24:34 2015 guillaume wilmot
*/

#include "sdl.h"

void	my_put_nbr(int nbr)
{
  int	i;

  i = 1;
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  while (nbr / i > 9)
    i *= 10;
  while (i > 0)
    {
      my_putchar((nbr / i % 10) + 48);
      i /= 10;
    }
}
