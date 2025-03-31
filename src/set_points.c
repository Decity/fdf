/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:39:37 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 11:44:20 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	set_all_rows(t_map_data *map_data)
{
	int		column;
	char	**points_arr;

	column = 0;
	while (map_data->map[column])
	{
		points_arr = ft_split(map_data->map[column], ' ');
		if (!points_arr)
			return (FAIL);
		if (ft_array_len((const char **)points_arr) != (size_t)map_data->max_x)
		{
			errno = EINVAL;
			ft_free_strs(&points_arr);
			return (FAIL);
		}
		set_row_of_points(map_data, points_arr, column);
		ft_free_strs(&points_arr);
		column++;
	}
	return (SUCCESS);
}

void	set_row_of_points(t_map_data *map_data, char **points_arr, int column)
{
	int	row;

	row = 0;
	while (points_arr[row] && row < map_data->max_x)
	{
		set_point(map_data, points_arr[row], row, column);
		row++;
	}
}

int	set_point(t_map_data *map_data, char *point_as_str, int row, int column)
{
	t_point	**p;

	p = map_data->points;
	p[column][row].axis[X] = (float)(row) - (float)(map_data->max_x / 2);
	p[column][row].axis[Y] = (float)column - (float)(map_data->max_y / 2);
	p[column][row].axis[Z] = (float)ft_atoi(point_as_str);
	p[column][row].p_axis[X] = p[column][row].axis[X];
	p[column][row].p_axis[Y] = p[column][row].axis[Y];
	p[column][row].p_axis[Z] = p[column][row].axis[Z];
	set_color(&map_data->points[column][row], point_as_str);
	if (p[column][row].axis[Z] > map_data->highest_z)
		map_data->highest_z = p[column][row].axis[Z];
	if (map_data->points[column][row].axis[Z] < map_data->lowest_z)
		map_data->lowest_z = p[column][row].axis[Z];
	return (SUCCESS);
}
