/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:57:31 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 12:31:56 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_camera(t_program *fdf);
void	set_scale(t_map_data *map_data, t_camera *camera);
void	set_offset(t_camera *camera);

void	set_camera(t_program *fdf)
{
	set_scale(fdf->map_data, &fdf->camera);
	set_offset(&fdf->camera);
	set_projection_type(ISO, fdf);
}

void	set_scale(t_map_data *map_data, t_camera *camera)
{
	const int	x_squared = map_data->max_x * map_data->max_x;
	const int	y_squared = map_data->max_y * map_data->max_y;
	const int	num = x_squared + y_squared;

	camera->scale = WINDOW_HEIGHT / sqrt(num);
}

void	set_offset(t_camera *camera)
{
	camera->offset[X] = WINDOW_WIDTH / 2;
	camera->offset[Y] = WINDOW_HEIGHT / 2;
}
