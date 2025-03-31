/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:27:42 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 11:38:31 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	apply_transforms(t_map_data *map_data, t_camera camera);
void	scale(t_map_data *map_data, t_camera camera);
void	translate(t_map_data *map_data, t_camera camera);

void	apply_transforms(t_map_data *map_data, t_camera camera)
{
	scale(map_data, camera);
	rotate(map_data, camera);
	translate(map_data, camera);
}

void	scale(t_map_data *map_data, t_camera camera)
{
	int		i;
	int		j;
	t_point	**p;

	p = map_data->points;
	i = 0;
	while (i < map_data->max_y)
	{
		j = 0;
		while (j < map_data->max_x)
		{
			p[i][j].p_axis[X] = p[i][j].axis[X] * camera.scale;
			p[i][j].p_axis[Y] = p[i][j].axis[Y] * camera.scale;
			p[i][j].p_axis[Z] = p[i][j].axis[Z] * (camera.scale / 4);
			j++;
		}
		i++;
	}
}

void	translate(t_map_data *map_data, t_camera camera)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->max_y)
	{
		j = 0;
		while (j < map_data->max_x)
		{
			map_data->points[i][j].p_axis[X] += camera.offset[X];
			map_data->points[i][j].p_axis[Y] += camera.offset[Y];
			j++;
		}
		i++;
	}
}
