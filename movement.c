/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:49:31 by sergiopax         #+#    #+#             */
/*   Updated: 2021/11/30 12:33:59 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moveplayer(int keycode, t_vars *vars)
{	
	if (vars->open == 1)
		exitopen(keycode, vars);
	else
		exitclosed(keycode, vars);
	printf("\nsteps needed so far: %i", vars->steps);
	loadmap(vars);
	scanstring(vars);
	return (1);
}

void	exitclosed(int keycode, t_vars *vars)
{
	exitclosed1(keycode, vars);
	exitclosed2(keycode, vars);
}

void	exitopen(int keycode, t_vars *vars)
{
	exitopen1(keycode, vars);
	exitopen2(keycode, vars);
}

void	scanstring(t_vars *vars)
{	
	if (!ft_strchr(vars->map, 'C'))
		vars->open = 1;
	if (!ft_strchr(vars->map, 'E') && vars->open == 1)
		vars->exit = 1;
	if (vars->exit == 1 && vars->open == 1)
	{
		printf("\nyour score is: %i", vars->steps);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map);
		free(vars->img.img);
		exit(1);
	}
}
