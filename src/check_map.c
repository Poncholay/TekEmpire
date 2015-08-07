/*
** check_map.c for check_map in /home/wilmot_g/Rush3/Etape1
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 20:28:21 2015 guillaume wilmot
** Last update Sat May 16 22:21:56 2015 guillaume wilmot
*/

#include "sdl.h"

char	**get_map(int fd)
{
  char	**ret;
  char	*line;
  int	i;

  i = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      ++i;
      free(line);
    }
  if (lseek(fd, 0, SEEK_SET) < 0)
    return (my_puterr("Error: cannot perform lseek\n", NULL));
  if ((ret = malloc((i + 1) * sizeof(char *))) == NULL)
    return (my_puterr("Error: cannot perform malloc\n", NULL));
  i = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      ret[i] = line;
      ++i;
    }
  ret[i] = NULL;
  return (ret);
}

char	*get_file_name(char *file)
{
  char	*name;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (file[i])
    i++;
  if ((name = malloc((i + 2) * sizeof(char))) == NULL)
    return (my_puterr("Malloc : error\n", NULL));
  while (i >= 0 && file[i] != '/')
    i--;
  if (file[i] == '/')
    i++;
  if (i == -1)
    {
      free(name);
      return (my_strdup(file));
    }
  while (file[i])
    name[j++] = file[i++];
  name[j] = '\0';
  return (name);
}

int	check_map(char *file)
{
  char	**map;
  char	*name;

  if ((name = get_file_name(file)) == NULL)
    return (my_puterr_int("\nAn error occured\n", 0));
  map = NULL;
  if (check_existing(file) && check_extension(file)
      && check_content(file, &map))
    {
      final_free(name, map);
      return (1);
    }
  final_free(name, map);
  return (my_puterr_int("An error occured\n", 0));
}
