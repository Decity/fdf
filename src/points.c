/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:32:33 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 11:44:49 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		set_point_data(t_program *fdf);
int		malloc_points(t_map_data *map_data);
void	free_points(t_map_data *map_data);
void	free_point_row(t_point **point);

int	set_point_data(t_program *fdf)
{
	if (malloc_points(fdf->map_data) == FAIL)
		fdf_exit(fdf, "Malloc points");
	if (set_all_rows(fdf->map_data) == FAIL)
		fdf_exit(fdf, "Set all rows");
	apply_transforms(fdf->map_data, fdf->camera);
	return (SUCCESS);
}

int	malloc_points(t_map_data *map_data)
{
	int	i;

	i = 0;
	map_data->points = malloc((map_data->max_y + 1) * sizeof(t_point *));
	if (map_data->points == NULL)
		return (FAIL);
	while (i < map_data->max_y)
	{
		map_data->points[i] = malloc(map_data->max_x * sizeof(t_point));
		if (map_data->points[i] == NULL)
		{
			free_points(map_data);
			return (FAIL);
		}
		i++;
	}
	map_data->points[i] = NULL;
	return (SUCCESS);
}

void	free_points(t_map_data *map_data)
{
	int	i;

	i = 0;
	while (map_data->points[i])
	{
		free_point_row(&map_data->points[i]);
		i++;
	}
	free(map_data->points);
	map_data->points = NULL;
}

void	free_point_row(t_point **point)
{
	free(*point);
	*point = NULL;
}
