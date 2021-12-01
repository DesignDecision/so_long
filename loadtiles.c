/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadtiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:45:39 by sergiopax         #+#    #+#             */
/*   Updated: 2021/11/30 16:21:17 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_floor(t_vars *vars)
{
	char	*path;
	int		width;
	int		height;

	path = "./floor.xpm";
	width = 49;
	height = 69;
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
	return (vars->img.img);
}

void	*load_wall(t_vars *vars)
{
	char	*path;
	int		width;
	int		height;

	path = "./wall.xpm";
	width = 49;
	height = 69;
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
	return (vars->img.img);
}

void	*load_coin(t_vars *vars)
{
	char	*path;
	int		width;
	int		height;

	path = "./blooddrop.xpm";
	width = 49;
	height = 69;
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
	return (vars->img.img);
}

void	*load_player(t_vars *vars)
{
	char	*path;
	int		width;
	int		height;

	width = 49;
	height = 69;
	path = "./bloody-bone.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
	return (vars->img.img);
}

void	*load_exit(t_vars *vars)
{
	char	*path;
	int		width;
	int		height;

	path = "./exit.xpm";
	width = 49;
	height = 69;
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
	return (vars->img.img);
}
