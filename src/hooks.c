/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:42:56 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 12:44:22 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	controls(void *param);
void	change_view(t_program *fdf);
void	exit_hook(void *param);

void	controls(void *param)
{
	t_program	*fdf;

	fdf = param;
	change_view(fdf);
	zoom(fdf);
	turn(fdf);
	move(fdf);
}

void	change_view(t_program *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
	{
		set_projection_type(FLAT, fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
	{
		set_projection_type(ISO, fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_3))
	{
		set_projection_type(PAR, fdf);
		draw(fdf);
	}
}

void	exit_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("User pressed ESC - closing the window.");
		mlx_close_window(mlx);
	}
}
