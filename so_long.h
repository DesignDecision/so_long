/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:20:19 by spax              #+#    #+#             */
/*   Updated: 2021/12/01 09:45:27 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif

# ifndef FD_MAX
#  define FD_MAX 4098
# endif

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vars {
	char	*map;
	int		mapsize;
	int		row;
	int		lastrow;
	int		open;
	int		exit;
	void	*mlx;
	void	*win;
	int		xpos;
	int		ypos;
	int		player;
	int		steps;
	int		error;
	t_img	img;
}				t_vars;

void	loadmap(t_vars *vars);
void	loadmap1(t_vars *vars, int i);
void	checkarg(t_vars *vars, char **argv);
int		checkmap(t_vars *vars);
void	checkrectangular(t_vars *vars);
int		checkfirstrow(t_vars *vars);
int		checkmiddlerows(t_vars *vars);
int		checklastrow(t_vars *vars);
int		checkobjects(t_vars *vars);
void	checkobjects2(t_vars *vars);
int		maperror(t_vars *vars);
int		load_image(t_vars *vars);
int		move(t_vars *vars);
char	*get_next_line(int fd);
void	*load_floor(t_vars *vars);
void	*load_wall(t_vars *vars);
void	*load_player(t_vars *vars);
void	*load_exit(t_vars *vars);
void	*load_coin(t_vars *vars);
int		exit_game(t_vars *vars);
int		moveplayer(int keycode, t_vars *vars);
void	scanstring(t_vars *vars);
void	exitopen(int keycode, t_vars *vars);
void	exitopen1(int keycode, t_vars *vars);
void	exitopen2(int keycode, t_vars *vars);
void	exitclosed(int keycode, t_vars *vars);
void	exitclosed1(int keycode, t_vars *vars);
void	exitclosed2(int keycode, t_vars *vars);
void	toobig(t_vars *vars);
#endif
