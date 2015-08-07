/*
** my_atoi.c for my_atoi in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 23:31:42 2015 guillaume wilmot
** Last update Sat May 16 22:24:17 2015 guillaume wilmot
*/

#include "sdl.h"

int	is_number(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	is_neg(char *str)
{
  int	i;
  int	neg;

  i = 0;
  neg = 0;
  while (str && str[i] != 0 && !is_number(str[i]))
    {
      if (str[i] == '-')
	++neg;
      ++i;
    }
  return (neg % 2);
}

int	my_atoi(char *str)
{
  int   i;
  int   number;

  i = 0;
  number = 0;
  while (str && str[i] != 0 && !is_number(str[i]))
    ++i;
  while (str && str[i] != 0 && is_number(str[i]))
    {
      number *= 10;
      number += ((int)str[i] - 48);
      i++;
    }
  if (is_neg(str))
    return (-number);
  return (number);
}
