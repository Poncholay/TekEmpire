/*
** types.h for  in /home/barrie_j/Documents/rendu/BocalEmblem/I : The Sacred Stones
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sat May 16 02:56:40 2015 Jean BARRIERE
** Last update Sun May 17 22:02:19 2015 Jean BARRIERE
*/

#ifndef TYPES_H_
# define TYPES_H_

t_coords	*get_target_pos(char **board, int target);
t_coords	*get_enemy_closer(char **board, int y, int x);
t_coords	*get_ia_target(char **board, t_coords *pos);
char		**create_board(char **tab);
char		**get_map(int fd);
char		**str_to_word_tab(char *str);
char		*get_gif(char *, SDL_Surface *[11]);
char		*concatenate(char *, char *, char);
char		*get_file_name(char *fd);
char		*get_next_line(int fd);
char		*my_strcpy(char *dest, char *src);
char		*my_strdup(char *str);
void		*my_puterr(char *str, void *ret);
void		display_board(char **board, int delay);
void		display_content(char **map, char *file);
void		draw_line(t_coords coords, SDL_Surface *screen, Uint32 color);
void		exec_cmd(char *line, char **tab, int *turn, t_sdl *sdl);
void		final_free(char *str, char **tab);
void		free_double_tab(char **tab);
void		my_printf(char *flags, ...);
void		my_fprintf(char *flags, ...);
void		my_put_nbr(int nbr);
void		my_fput_nbr(int nbr);
void		my_putchar(char c);
void		my_fputchar(char c);
void		my_putstr(char *str);
void		play_ia(char **board, int *flag, t_sdl *sdl);
void		putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
void		put_transparency(SDL_Surface *gif[11]);
void		reinit_board(char **board, int turn);
void		try_attack(int unit, int target, char **board, t_sdl *);
void		try_ia_attack(char **b, t_coords *p, t_coords *t, t_sdl *s);
void		try_ia_move(char **b, t_coords *p, t_coords *t, t_sdl *s);
void		try_move(int unit, int dir, char **board, t_sdl *sdl);
int		*make_event(t_coords coords, int *event, int i);
int		*get_event(int  unit, int target, char **board, int i);
int		test(t_anims *, char **, t_assets *, char *);
int		access_target(t_sdl *sdl, t_coords *upos, int, int target);
int             animate_units(t_anims *anims, char **map,
			      t_assets *assets, int event[3]);
int		can_move(char **board, int y, int x, t_coords *pos);
int		check_borders(char **tab);
int		check_content(char *str, char ***tab);
int		check_doublon(char **map);
int		check_existing(char *str);
int		check_extension(char *str);
int		check_map(char *str);
int		check_nbr(char **tab);
int		check_spaces(char **tab);
int		check_units(char **tab, int x, int y);
int		check_values(char **tab);
int		describe_content(char **tab, char *str);
int		display_end_attack(int msg, int unit, int target, char **brd);
int		do_mtop(t_anims *anims, t_assets *assets, int [3], char **);
int		do_mdown(t_anims *anims, t_assets *assets, int [3], char **);
int		do_mright(t_anims *anims, t_assets *assets, int [3], char **);
int		do_mleft(t_anims *anims, t_assets *assets, int [3], char **);
int		do_atop(t_anims *anims, t_assets *assets, int [3], char **);
int		do_adown(t_anims *anims, t_assets *assets, int [3], char **);
int		do_aright(t_anims *anims, t_assets *assets, int [3], char **);
int		do_aleft(t_anims *anims, t_assets *assets, int [3], char **);
int		do_die(t_anims *anims, t_assets *assets, int [3], char **);
int		do_stand(t_anims *anims, t_assets *assets, int [3], char **);
int		draw_cas_un(t_coords coords, SDL_Surface *screen, Uint32 clr);
int		draw_cas_deux(t_coords coords, SDL_Surface *screen, Uint32);
int		events(int);
int		enemy_around(char **board, int y, int x);
int		friend_around(char **board, int y, int x);
int		get_anims_red_k(t_gifs *gifs);
int		get_anims_red_b(t_gifs *gifs);
int		get_anims_red_s(t_gifs *gifs);
int		get_anims_blue_k(t_gifs *gifs);
int		get_anims_blue_b(t_gifs *gifs);
int		get_anims_blue_s(t_gifs *gifs);
int		get_assets(t_assets *);
int		get_damage(int unit, int target, int *flag);
int		get_hp(char **board, int unit);
int		has_to_move(char **board, int y, int x, int *dir);
int		init_draw_board(char **map, SDL_Surface **bg, t_assets *ast);
int		init_get_bg(char **map, t_assets *assets, t_anims *anims,
			    t_coords except);
int		is_good_direction(char *str);
int		is_my_unit(char c, int flag);
int		is_number(char c);
int		is_turn(int nb, int turn);
int		loop_animation(SDL_Rect pos, int event[3], t_assets *assets,
			       SDL_Surface **gif);
int		loop_animation_mtop(SDL_Rect pos, int event[3],
				    t_assets *assets,
			       SDL_Surface **gif);
int		loop_animation_mdown(SDL_Rect pos, int event[3],
				     t_assets *assets,
			       SDL_Surface **gif);
int		loop_animation_mright(SDL_Rect pos, int event[3],
				      t_assets *assets,
			       SDL_Surface **gif);
int		loop_animation_mleft(SDL_Rect pos, int event[3],
				     t_assets *assets,
			       SDL_Surface **gif);
int		match(char *str1, char *str2);
int		match_attack(char *line, int flag);
int		match_move(char *line, int flag);
int		move_unit(t_sdl *sdl, int y, int x, int dir);
int		my_atoi(char *str);
int		my_puterr_int(char *str, int ret);
int		my_strlen(char *str);
int		nmatch(char *sa, char *sb, int len);
int		radiance(char **tab, int turn, t_sdl *sdl, t_coords *coords);
int		tab_len(char **tab);

#endif /* !TYPES_H_ */
