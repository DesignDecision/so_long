/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:18:53 by sergiopax         #+#    #+#             */
/*   Updated: 2021/12/01 09:30:11 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loadmap1(t_vars *vars, int i)
{
	if (vars->map[i] == '0')
		load_floor(vars);
	if (vars->map[i] == '1')
		load_wall(vars);
	if (vars->map[i] == 'C')
	{	
		load_floor(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.img, vars->xpos, vars->ypos);
		load_coin(vars);
	}
	if (vars->map[i] == 'P')
	{
		vars->player = i;
		load_floor(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.img, vars->xpos, vars->ypos);
		load_player(vars);
	}
	if (vars->map[i] == 'E')
		load_exit(vars);
}

void	checkobjects2(t_vars *vars)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == 'P' || vars->map[i] == 'E')
			c++;
		i++;
	}
	if (c > 2)
	{
		printf("Error:\nonly one Player and one Exit are allowed");
		maperror(vars);
	}
}

void	checkarg(t_vars *vars, char **argv)
{
	int	len;

	(void)vars;
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e' ||
	argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
	{
		printf("Error:\nthe map needs to be passed as a .ber file");
		exit(1);
	}
}
