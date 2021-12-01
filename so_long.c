/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:44:36 by spax              #+#    #+#             */
/*   Updated: 2021/12/01 07:57:32 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loadmap(t_vars *vars)
{
	int	flag;
	int	i;

	vars->xpos = 10;
	vars->ypos = 10;
	i = 0;
	while (vars->map[i])
	{
		vars->img.img = (void *)0;
		flag = 0;
		loadmap1(vars, i);
		if (vars->map[i] == '\n')
		{
			flag++;
			vars->ypos += 60;
			vars->xpos = 10;
			toobig(vars);
		}
		i++;
		if (vars->img.img)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img.img, vars->xpos, vars->ypos);
		if (flag == 0)
			vars->xpos += 60;
	}
}

int	exit_game(int keycode, t_vars *vars)
{
	exit(1);
}

int	checkmap(t_vars *vars)
{	
	vars->row = (ft_strchr(vars->map, '\n') - vars->map);
	vars->lastrow = (ft_strrchr(vars->map, '\n') - vars->map);
	vars->row++;
	checkfirstrow(vars);
	checklastrow(vars);
	checkmiddlerows(vars);
	checkobjects(vars);
	checkrectangular(vars);
	return (1);
}

int	maperror(t_vars *vars)
{	
	if (vars->error == 1)
		printf("Error:\npassed map is not rectangular");
	if (vars->error == 2)
		printf("Error:\npassed map has no starting position (P)");
	if (vars->error == 3)
		printf("Error:\npassed map has no Exit");
	if (vars->error == 4)
		printf("Error:\npassed map has no collectible");
	if (vars->error == 5)
		printf("Error:\npassed map is too big");
	printf("\nError:\npassed map does not meet requierements.");
	free(vars->map);
	free(vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}

int	main(int argc, char **argv )
{
	t_vars	vars;
	int		fd;
	int		i;

	vars.map = NULL;
	vars.win = NULL;
	vars.mlx = NULL;
	vars.img.img = NULL;
	checkarg(&vars, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1440, 850, "So Long");
	vars.map = ft_calloc(BUFFER_SIZE, 1);
	fd = open(argv[1], O_RDONLY);
	vars.mapsize = read(fd, vars.map, BUFFER_SIZE);
	vars.map[vars.mapsize + 1] = '\0';
	checkmap(&vars);
	vars.steps = 0;
	printf("%s", vars.map);
	close(fd);
	loadmap(&vars);
	mlx_hook(vars.win, 17, 0, exit_game, &vars);
	mlx_hook(vars.win, 2, 1L << 0, moveplayer, &vars);
	mlx_loop(vars.mlx);
}
