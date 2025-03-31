/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:41:25 by elie              #+#    #+#             */
/*   Updated: 2024/07/20 12:12:41 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_all(t_program *fdf);
void	free_map_name_and_path(t_map_data *map_data);

void	free_map_name_and_path(t_map_data *map_data)
{
	ft_free_and_null(&map_data->map_path);
}

void	free_all(t_program *fdf)
{
	mlx_terminate(fdf->mlx);
	free_map_name_and_path(fdf->map_data);
	ft_free_strs(&fdf->map_data->map);
	free_points(fdf->map_data);
	free(fdf->map_data);
	fdf->map_data = NULL;
}
