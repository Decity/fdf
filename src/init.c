/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:42:56 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 16:19:32 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_fdf(t_program *fdf, int argc, char **argv);
void	init_mlx(t_program *fdf);
int		init_map_data(t_program *fdf);

void	init_fdf(t_program *fdf, int argc, char **argv)
{
	fdf->argc = argc;
	fdf->argv = argv;
	init_map_data(fdf);
	fdf->mlx = NULL;
}

void	init_mlx(t_program *fdf)
{
	mlx_set_setting(MLX_DECORATED, true);
	fdf->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "fdf", false);
	if (!fdf->mlx)
		mlx_err_exit(fdf);
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!fdf->img)
		mlx_err_exit(fdf);
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0)
		mlx_err_exit(fdf);
	return ;
}

int	init_map_data(t_program *fdf)
{
	fdf->map_data = malloc(sizeof(t_map_data));
	if (!fdf->map_data)
	{
		perror("Init map data");
		exit(errno);
	}
	fdf->map_data->map_path = NULL;
	fdf->map_data->map = NULL;
	fdf->map_data->points = NULL;
	fdf->map_data->total_points = 0;
	fdf->map_data->max_x = 0;
	fdf->map_data->max_y = 0;
	fdf->map_data->lowest_z = 0;
	fdf->map_data->highest_z = 0;
	return (SUCCESS);
}
