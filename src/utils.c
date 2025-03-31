/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:41:42 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 16:20:49 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

bool	is_valid_coordinate(t_point point);
void	fdf_exit(t_program *fdf, const char *error_str);
void	exit_hook(void *param);
void	mlx_err_exit(t_program *fdf);

bool	is_valid_coordinate(t_point point)
{
	if (point.p_axis[X] < 0 || point.p_axis[Y] < 0)
		return (false);
	if (point.p_axis[X] >= WINDOW_WIDTH || point.p_axis[Y] >= WINDOW_HEIGHT)
		return (false);
	return (true);
}

void	fdf_exit(t_program *fdf, const char *error_str)
{
	perror(error_str);
	if (fdf->mlx)
		mlx_terminate(fdf->mlx);
	free_map_name_and_path(fdf->map_data);
	ft_free_strs(&fdf->map_data->map);
	if (&(*fdf->map_data->points))
		free_points(fdf->map_data);
	free(fdf->map_data);
	fdf->map_data = NULL;
	exit (errno);
}

void	mlx_err_exit(t_program *fdf)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	mlx_terminate(fdf->mlx);
	free(fdf->map_data);
	exit(mlx_errno);
}
