/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:41:22 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 16:22:59 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom(t_program *fdf);
void	move(t_program *fdf);
void	turn(t_program *fdf);
void	turn_axis(int axis, int deg, t_program *fdf);

void	zoom(t_program *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
	{
		fdf->camera.scale = (fdf->camera.scale + 0.01) * 1.03;
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
	{
		fdf->camera.scale = (fdf->camera.scale - 0.01) * 0.97;
		draw(fdf);
	}
}

void	move(t_program *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
	{
		fdf->camera.offset[Y] -= 5;
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
	{
		fdf->camera.offset[Y] += 5;
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
	{
		fdf->camera.offset[X] -= 5;
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
	{
		fdf->camera.offset[X] += 5;
		draw(fdf);
	}
}

void	turn(t_program *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		turn_axis(Y, -5, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		turn_axis(Y, 5, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		turn_axis(X, -5, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		turn_axis(X, 5, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		turn_axis(Z, -5, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		turn_axis(Z, 5, fdf);
}

void	turn_axis(int axis, int deg, t_program *fdf)
{
	fdf->camera.rotation[axis] += deg;
	if (fdf->camera.rotation[axis] > 360)
		fdf->camera.rotation[axis] -= 360;
	draw(fdf);
}
