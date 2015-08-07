## Makefile for  in /home/barrie_j/Documents/rendu/BocalEmblem/1 : The Sacred Stones
##
## Made by Jean BARRIERE
## Login   <barrie_j@epitech.net>
##
## Started on  Fri May 15 23:26:36 2015 Jean BARRIERE
## Last update Sun May 17 23:37:35 2015 Jean BARRIERE
##

CC	= gcc

CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -pedantic
CFLAGS	+= -I./include/

LDFLAGS	+= -lSDL

SRCDIR	= src

OBJDIR	= obj

MKDIR	= mkdir

RM	= rm -f

RMDIR	= rm -rf

NAME	= tek_empires

SRC	= main.c 		\
	  ia.c			\
	  ia_try.c		\
	  ia_update.c		\
	  get_event.c		\
	  loop_animation.c	\
	  animate.c		\
	  animation_move.c	\
	  animation_fight.c	\
	  gif.c			\
	  concatenate.c		\
	  my_strcpy.c 		\
	  load_blue.c		\
	  my_strdup.c 		\
	  lib.c 		\
	  attack.c		\
	  check_content.c	\
	  check_state.c		\
	  check_doublon.c	\
	  check_map.c		\
	  checks.c		\
	  create_board.c	\
	  describe_content.c	\
	  draw_board.c		\
	  draw_functs.c		\
	  display_board.c	\
	  exec.c		\
	  free.c		\
	  get_infos.c		\
	  get_next_line.c	\
	  match.c		\
	  move.c		\
	  my_atoi.c		\
	  my_printf.c		\
	  my_put_nbr.c		\
	  radiance.c		\
	  tab_len.c		\
	  test.c		\
	  my_fprintf.c 		\
	  my_puterr.c

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@if [ ! -d $(OBJDIR) ] ; then $(MKDIR) $(OBJDIR) ; fi
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<
	@echo -e "Object created :\t"$<" > "$@

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@if [ -d $(OBJDIR) ] ; then $(RMDIR) $(OBJDIR) ; fi

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
