/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:05:19 by sergiopax         #+#    #+#             */
/*   Updated: 2021/12/01 09:30:56 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkrectangular(t_vars *vars)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	vars->error = 1;
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == '\n')
			lines++;
		i++;
	}
	if (vars->map[vars->lastrow + vars->row] != '\0')
		maperror(vars);
	i = 2;
	while (i <= lines)
	{
		if (vars->map[(vars->row * i) - 1] != '\n')
			maperror(vars);
		i++;
	}
	vars->error = 0;
}

int	checkfirstrow(t_vars *vars)
{
	int	row;
	int	j;

	j = 0;
	row = vars->row - 1;
	while (j < row)
	{
		if (vars->map[j] != '1')
			maperror(vars);
		j++;
	}
	if (row > 23)
	{
		printf("map is too big\n");
		maperror(vars);
	}
	return (1);
}

int	checklastrow(t_vars *vars)
{
	int	j;
	int	i;

	j = vars->lastrow + 1;
	i = j + vars->row - 2;
	while (j < i)
	{
		if (vars->map[j] != '1')
			maperror(vars);
		j++;
	}
	if (vars->map[j + 1] != '\0')
		maperror(vars);
	return (1);
}

int	checkmiddlerows(t_vars *vars)
{
	int	row;
	int	lastrow;

	row = vars->row;
	lastrow = vars->lastrow;
	while (row < lastrow)
	{
		if (vars->map[row] == '\n')
		{
			if (vars->map[row + 1] != '1' || vars->map[row - 1] != '1')
				maperror(vars);
		}
		row++;
	}
	return (1);
}

int	checkobjects(t_vars *vars)
{
	if (!ft_strchr(vars->map, 'C'))
	{
		vars->error = 4;
		maperror(vars);
	}
	if (!ft_strchr(vars->map, 'E'))
	{
		vars->error = 3;
		maperror(vars);
	}
	if (!ft_strchr(vars->map, 'P'))
	{
		vars->error = 2;
		maperror(vars);
	}
	checkobjects2(vars);
	return (1);
}
