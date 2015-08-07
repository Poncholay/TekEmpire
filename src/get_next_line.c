/*
** get_next_line.c for  in /home/barrie_j/Documents/rendu/BocalEmblem
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Fri May 15 21:17:35 2015 Jean BARRIERE
** Last update Sat May 16 22:23:38 2015 guillaume wilmot
*/

#include "sdl.h"

int	strlen_act_line(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

int	copy_act_line(char *new_l, char *actual_line, int i, int len)
{
  while (i < len)
    {
      new_l[i] = actual_line[i];
      i++;
    }
  return (i);
}

char	*my_new_line(char *line, char buff[BUFSIZ + 1], int *st, int end)
{
  char	*new_l;
  int	i;
  int	j;
  int	len;

  j = 0;
  len = strlen_act_line(line);
  if ((new_l = malloc((len + end + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = copy_act_line(new_l, line, 0, len);
  while (j < end)
    {
      new_l[i + j] = buff[*st + j];
      j++;
    }
  new_l[i + j] = 0;
  if (line != NULL)
    free(line);
  *st = *st + end + 1;
  return (new_l);
}

char		*get_next_line(const int fd)
{
  char		*actual_line;
  static char	buff[BUFSIZ + 1];
  static int	start;
  static int	size_buff;
  int		end;

  actual_line = NULL;
  end = 0;
  while ("zizou")
    {
      if (start >= size_buff)
	{
	  end = 0;
	  start = 0;
	  if ((size_buff = read(fd, buff, BUFSIZ)) <= 0)
	    return (actual_line);
	}
      if (buff[start + end] == '\n')
	return (my_new_line(actual_line, buff, &start, end));
      if (start + end == size_buff - 1)
	actual_line = my_new_line(actual_line, buff, &start, end + 1);
      end++;
    }
}
