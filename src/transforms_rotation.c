/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:27:42 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 11:38:31 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotate(t_map_data *map_data, t_camera camera);
void	rotate_x(float *y, float *z, double x_angle_degrees);
void	rotate_y(float *x, float *z, double y_angle_degrees);
void	rotate_z(float *x, float *y, double z_angle_degrees);

void	rotate(t_map_data *map_data, t_camera camera)
{
	int		i;
	int		j;
	t_point	**points;

	points = map_data->points;
	i = 0;
	while (i < map_data->max_y)
	{
		j = 0;
		while (j < map_data->max_x)
		{
			rotate_x(&points[i][j].p_axis[Y], &points[i][j].p_axis[Z],
				camera.rotation[X]);
			rotate_y(&points[i][j].p_axis[X], &points[i][j].p_axis[Z],
				camera.rotation[Y]);
			rotate_z(&points[i][j].p_axis[X], &points[i][j].p_axis[Y],
				camera.rotation[Z]);
			j++;
		}
		i++;
	}
}

void	rotate_x(float *y, float *z, double x_angle_degrees)
{
	const double	x_angle_radians = x_angle_degrees * PI / 180.0;
	const float		prev_y = *y;

	*y = prev_y * cos(x_angle_radians) + *z * sin(x_angle_radians);
	*z = prev_y * -sin(x_angle_radians) + *z * cos(x_angle_radians);
}

void	rotate_y(float *x, float *z, double y_angle_degrees)
{
	const double	y_angle_radians = y_angle_degrees * PI / 180.0;
	const float		prev_x = *x;

	*x = prev_x * cos(y_angle_radians) + *z * sin(y_angle_radians);
	*z = prev_x * -sin(y_angle_radians) + *z * cos(y_angle_radians);
}

void	rotate_z(float *x, float *y, double z_angle_degrees)
{
	const double	z_angle_radians = z_angle_degrees * PI / 180.0;
	const float		prev_x = *x;
	const float		prev_y = *y;

	*x = prev_x * cos(z_angle_radians) - prev_y * sin(z_angle_radians);
	*y = prev_x * sin(z_angle_radians) + prev_y * cos(z_angle_radians);
}
