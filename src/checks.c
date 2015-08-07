/*
** checks.c for checks in /home/wilmot_g/Rush3/Etape1
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 20:19:04 2015 guillaume wilmot
** Last update Sun May 17 22:03:46 2015 guillaume wilmot
*/

#include "sdl.h"

int	check_nbr(char **map)
{
  int	y;
  int	x;

  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x])
	{
	  if ((map[y][x] < '0' || map[y][x] > '9') && map[y][x] != ' ')
	    {
	      write(2, &map[y][x], 1);
	      return (my_puterr_int(" is not an allowed character\n", 0));
	    }
	  x++;
	}
      y++;
    }
  return (1);
}

int	check_units(char **map, int x, int y)
{
  int	pl1;
  int	pl2;
  char	**tab;

  pl1 = ((pl2 = 0) == 0) ? 0 : 0;
  while (map[y])
    {
      x = 0;
      tab = str_to_word_tab(map[y]);
      while (tab[x])
	{
	  if (my_atoi(tab[x]) > 10 && my_atoi(tab[x]) <= 40)
	    pl1++;
	  if (my_atoi(tab[x]) > 40 && my_atoi(tab[x]) <= 70)
	    pl2++;
	  x++;
	}
      free_double_tab(tab);
      y++;
    }
  if (pl1 == 0)
    return (my_puterr_int("Warning, player blue has no units\n", 0));
  if (pl2 == 0)
    return (my_puterr_int("Warning, player red has no units\n", 0));
  return (1);
}

int	check_content(char *file, char ***map)
{
  int	fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (my_puterr_int("Open : error\nCould not check content\n", 0));
  if ((*map = get_map(fd)) == NULL)
    return (my_puterr_int("Could not check content\n", 0));
  if (*map[0] == '\0')
    return (my_puterr_int("The map is empty\n", 0));
  if (check_spaces(*map) && check_nbr(*map) && check_values(*map)
      && check_units(*map, 0, 0) && check_borders(*map) && check_doublon(*map))
    return (1);
  return (0);
}

int	check_extension(char *file)
{
  int	i;

  i = 0;
  while (file[i])
    i++;
  while (file[i] != '.')
    i--;
  if (i == 0)
    return (my_puterr_int("Extension is not OK\n", 0));
  if (!match(&file[i], ".map"))
    return (my_puterr_int("Extension is not OK\n", 0));
  return (1);
}

int	check_existing(char *file)
{
  int	fd;

  if ((fd = open(file, O_RDONLY)) != -1)
    close(fd);
  else
    return (my_puterr_int("File does not exist\n", 0));
  return (1);
}
