/*
** my_printf.c for my_printf in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 23:15:50 2015 guillaume wilmot
** Last update Sun May 17 21:24:49 2015 Jean BARRIERE
*/

#include "sdl.h"

void		my_fputchar(char c)
{
  write(2, &c, 1);
}

void		my_fput_nbr(int nbr)
{
  int   i;

  i = 1;
  if (nbr < 0)
    {
      my_fputchar('-');
      nbr = -nbr;
    }
  while (nbr / i > 9)
    i *= 10;
  while (i > 0)
    {
      my_fputchar((nbr / i % 10) + 48);
      i /= 10;
    }
}

void		do_fflags(char *flags, va_list arguments, int i)
{
  if (flags[i + 1] == 's')
    my_puterr(va_arg(arguments, char *), NULL);
  else if (flags[i + 1] == 'd' || flags[i + 1] == 'i')
    my_fput_nbr(va_arg(arguments, int));
  else if (flags[i + 1] == 'c')
    my_fputchar((char)va_arg(arguments, int));
}

void		my_fprintf(char *flags, ...)
{
  va_list	arguments;
  int		i;

  va_start(arguments, flags);
  i = 0;
  while (flags[i])
    {
      if (flags[i] == '%')
        {
	  do_fflags(flags, arguments, i);
          i = i + 1;
        }
      else
        my_fputchar(flags[i]);
      i = i + 1;
    }
  va_end(arguments);
}
