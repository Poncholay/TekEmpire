/*
** tab_len.c for tab_len in /home/wilmot_g/.ssh/BocalEmblem/1 : The Sacred Stones
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 15 22:29:58 2015 guillaume wilmot
** Last update Fri May 15 23:02:32 2015 guillaume wilmot
*/

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    i++;
  return (i);
}
