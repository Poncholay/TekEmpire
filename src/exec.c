/*
** exec.c for  in /home/barrie_j/Documents/rendu/BocalEmblem/III : Radiant Down
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 15:45:05 2015 Jean BARRIERE
** Last update Sun May 17 16:01:44 2015 guillaume wilmot
*/

#include "sdl.h"

void	exec_move(char *line, int turn, char **tab, t_sdl *sdl)
{
  int	nb;

  if ((nb = match_move(line, 0)) > 0 && is_turn(nb, turn))
    try_move(nb, match_move(line, 1), tab, sdl);
  else if ((nb = match_move(line, 0)) <= 10 || nb > 70)
    my_putstr("There is an error on your command\n");
  else
    my_putstr("It's not your turn\n");
}

void	exec_attack(char *line, int turn, char **tab, t_sdl *sdl)
{
  int	nb;

  if ((match_attack(line, 0) >= 11 && match_attack(line, 0) <= 40 &&
       match_attack(line, 1) >= 11 && match_attack(line, 1) <= 40) ||
      (match_attack(line, 0) >= 41 && match_attack(line, 0) <= 70 &&
       match_attack(line, 1) >= 41 && match_attack(line, 1) <= 70))
    my_putstr("Can't attack a unit from the same side sir\n");
  else if ((nb = match_attack(line, 0)) > 0 && is_turn(nb, turn))
    try_attack(nb, match_attack(line, 1), tab, sdl);
  else
    if ((nb = match_attack(line, 0)) <= 10 || nb > 70)
      my_putstr("There is an error on your command\n");
    else
      my_putstr("It's not your turn\n");
}

void	check_exec(char *line, char **tab, int turn, t_sdl *sdl)
{
  if (match(line, "display") || match(line, "display --extend"))
    display_board(tab, ((match(line, "display")) ? (3) : (1)));
  else if (match_move(line, 0) > 0)
    exec_move(line, turn, tab, sdl);
  else
    if (match_attack(line, 0) > 0)
      exec_attack(line, turn, tab, sdl);
    else
      my_putstr("There is an error on your command\n");
}

void	exec_cmd(char *line, char **tab, int *turn, t_sdl *sdl)
{
  if (match(line, "strategic"))
    display_content(tab, sdl->file);
  else if (match(line, "pass"))
    {
      *turn = ((*turn == 0) ? (1) : (0));
      reinit_board(tab, *turn);
    }
  else
    check_exec(line, tab, *turn, sdl);
}
