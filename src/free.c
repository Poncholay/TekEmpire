/*
** free.c for free in /home/wilmot_g/.ssh/BocalEmblem/I : The Sacred Stones/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 16 02:41:45 2015 guillaume wilmot
** Last update Sat May 16 22:23:14 2015 guillaume wilmot
*/

#include "sdl.h"

void	final_free(char *name, char **tab)
{
  if (name != NULL)
    free(name);
  free_double_tab(tab);
}

void	free_double_tab(char **tab)
{
  int	i;

  if (tab != NULL)
    {
      i = 0;
      while (tab[i])
	{
	  if (tab[i] != NULL)
	    free(tab[i]);
	  i++;
	}
      free(tab);
    }
}
