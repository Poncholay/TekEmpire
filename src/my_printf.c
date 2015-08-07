/*
** my_printf.c for my_printf in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 23:15:50 2015 guillaume wilmot
** Last update Sat May 16 22:24:26 2015 guillaume wilmot
*/

#include "sdl.h"

void		do_flags(char *flags, va_list arguments, int i)
{
  if (flags[i + 1] == 's')
    my_putstr(va_arg(arguments, char *));
  else if (flags[i + 1] == 'd' || flags[i + 1] == 'i')
    my_put_nbr(va_arg(arguments, int));
  else if (flags[i + 1] == 'c')
    my_putchar((char)va_arg(arguments, int));
}

void		my_printf(char *flags, ...)
{
  va_list	arguments;
  int		i;

  va_start(arguments, flags);
  i = 0;
  while (flags && flags[i])
    {
      if (flags[i] == '%')
        {
	  do_flags(flags, arguments, i);
          i = i + 1;
        }
      else
        my_putchar(flags[i]);
      i = i + 1;
    }
  va_end(arguments);
}
