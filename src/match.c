/*
** match.c for match in /home/wilmot_g/my_select
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue Dec 30 15:55:11 2014 guillaume wilmot
** Last update Sat May 16 22:24:00 2015 guillaume wilmot
*/

#include "sdl.h"

int	nmatch(char *sa, char *sb, int len)
{
  int	i;

  i = 0;
  while (sa && sb && sa[i] == sb[i] && i < len)
    ++i;
  if (i == len)
    return (1);
  return (0);
}

int	match(char *str1, char *str2)
{
  int	i;

  if (str1 == NULL || str2 == NULL)
    return (0);
  i = 0;
  if (my_strlen(str1) == my_strlen(str2))
    {
      while (str1[i] && str2[i])
	{
	  if (str1[i] == str2[i])
	    i = i + 1;
	  else
	    return (0);
	}
      return (1);
    }
  else
    return (0);
}

int	match_move(char *line, int flag)
{
  int	i;
  int	nb;
  int	valid;

  i = 0;
  nb = 0;
  valid = 0;
  while (line && line[i] != 0)
    {
      if ((line[i] == ' ' || line[i] == '\t') && nb == 0)
	nb = my_atoi(line);
      if ((line[i] == ' ' || line[i] == '\t') && nb != 0)
	{
	  if (is_good_direction(&line[i + 1]) > 0 && valid == 2)
	    return (((flag == 0) ? (nb) : (is_good_direction(&line[i + 1]))));
	  if ((nmatch(&line[i + 1], "move", 4) && valid == 0) ||
	      (nmatch(&line[i + 1], "to", 2) && valid == 1))
	    valid += 1;
	  else if (!nmatch(&line[i + 1], " ", 1) &&
		   !nmatch(&line[i + 1], "\t", 1))
	    return (0);
	}
      ++i;
    }
  return (0);
}

int	match_attack(char *line, int flag)
{
  int	i;
  int	nb;
  int	valid;

  i = 0;
  nb = 0;
  valid = 0;
  while (line && line[i] != 0)
    {
      if ((line[i] == ' ' || line[i] == '\t') && nb == 0)
	nb = my_atoi(line);
      if ((line[i] == ' ' || line[i] == '\t') && nb != 0)
	{
	  if (my_atoi(&line[i + 1]) > 0 && valid == 1)
	    return (((flag == 0) ? (nb) : (my_atoi(&line[i + 1]))));
	  if (nmatch(&line[i + 1], "attack", 6) && valid == 0)
	    valid += 1;
	  else if (!nmatch(&line[i + 1], " ", 1) &&
		   !nmatch(&line[i + 1], "\t", 1))
	    return (0);
	}
      ++i;
    }
  return (0);
}
