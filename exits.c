/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:58:46 by sergiopax         #+#    #+#             */
/*   Updated: 2021/12/01 07:42:49 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exitclosed1(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{	
		free(vars->map);
		free(vars->img.img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	if (keycode == 13 && vars->map[vars->player - vars->row] != '1'
		&& vars->map[vars->player - vars->row] != 'E' )
	{
		vars->map[vars->player - vars->row] = 'P';
		vars->map[vars->player] = '0';
		vars->steps++;
	}
	if (keycode == 0 && vars->map[vars->player - 1] != '1'
		&& vars->map[vars->player - 1] != 'E')
	{
		vars->map[vars->player - 1] = 'P';
		vars->map[vars->player] = '0';
		vars->steps++;
	}
}

void	exitclosed2(int keycode, t_vars *vars)
{
	if (keycode == 1 && vars->map[vars->player + vars->row] != '1'
		& vars->map[vars->player + vars->row] != 'E')
	{
		vars->map[vars->player + vars->row] = 'P';
		vars->map[vars->player] = '0';
		vars->steps++;
	}
	if (keycode == 2 && vars->map[vars->player + 1] != '1'
		&& vars->map[vars->player + 1] != 'E')
	{
		vars->map[vars->player + 1] = 'P';
		vars->map[vars->player] = '0';
		vars->steps++;
	}
}

void	exitopen1(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		free(vars->map);
		free(vars->img.img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}	
	if (keycode == 13 && vars->map[vars->player - vars->row] != '1')
	{
		vars->map[vars->player - vars->row] = 'P';
		vars->map[vars->player] = '0';
		vars->steps++;
	}
	if (keycode == 0 && vars->map[vars->player - 1] != '1')
	{
		vars->map[vars->player - 1] = 'P';
		vars->map[vars->player] = '0';
		vars->steps++;
	}
}

void	exitopen2(int keycode, t_vars *vars)
{
	if (keycode == 1 && vars->map[vars->player + vars->row] != '1')
	{
		vars->map[vars->player + vars->row] = 'P';
		vars->map[vars->player] = '0';
		vars->steps++;
	}
	if (keycode == 2 && vars->map[vars->player + 1] != '1')
	{
		vars->map[vars->player + 1] = 'P';
		vars->map[vars->player] = '0';
		vars->steps++;
	}
}

void	toobig(t_vars *vars)
{
	if (vars->ypos > 850)
	{
		printf("map is too big\n");
		maperror(vars);
	}
}
