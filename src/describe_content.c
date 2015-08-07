/*
** describe_content.c for describe_content in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 22:39:00 2015 guillaume wilmot
** Last update Sat May 16 22:22:50 2015 guillaume wilmot
*/

#include "sdl.h"

int	describe_content(char **map, char *name)
{
  char	**tab;
  int	x;
  int	y;

  tab = str_to_word_tab(map[0]);
  my_printf("The %s is %d on %d\n", name, my_strlen(tab[0]), tab_len(map));
  y = 0;
  while (map[y])
    {
      x = 0;
      tab = (y == 0) ? tab : str_to_word_tab(map[y]);
      while (tab[x])
	{
	  if (my_atoi(tab[x]) >= 11 && my_atoi(tab[x]) <= 40)
	    my_printf("The blue unit %d is in %d/%d\n", my_atoi(tab[x]), y, x);
	  else if (my_atoi(tab[x]) >= 41 && my_atoi(tab[x]) <= 70)
	    my_printf("The red unit %d is in %d/%d\n", my_atoi(tab[x]), y, x);
	  x++;
	}
      free_double_tab(tab);
      y++;
    }
  my_putstr("--end--\n");
  final_free(name, map);
  return (1);
}
