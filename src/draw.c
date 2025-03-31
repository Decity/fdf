/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:36:04 by ebayat            #+#    #+#             */
/*   Updated: 2024/07/23 12:28:21 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw(t_program *fdf);
void	draw_wireframe(t_map_data *map_data, mlx_image_t *img);
void	draw_line(mlx_image_t *img, t_point start, t_point end);
void	draw_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
void	set_background(mlx_image_t *img, uint32_t color);

void	draw(t_program *fdf)
{
	set_background(fdf->img, GREY);
	apply_transforms(fdf->map_data, fdf->camera);
	draw_wireframe(fdf->map_data, fdf->img);
}

void	draw_wireframe(t_map_data *map_data, mlx_image_t *img)
{
	int	i;
	int	j;

	j = 0;
	while (j < map_data->max_y - 1)
	{
		i = 0;
		while (i < map_data->max_x - 2)
		{
			draw_line(img, map_data->points[j][i], map_data->points[j][i + 1]);
			i++;
		}
		j++;
	}
	i = 0;
	while (i < map_data->max_x - 1)
	{
		j = 0;
		while (j < map_data->max_y - 2)
		{
			draw_line(img, map_data->points[j][i], map_data->points[j + 1][i]);
			j++;
		}
		i++;
	}
}

void	draw_line(mlx_image_t *img, t_point start, t_point end)
{
	t_point	delta;
	t_point	to_draw;
	float	amount_pixels_to_draw;
	float	delta_x_sq;
	float	delta_y_sq;

	delta.p_axis[X] = end.p_axis[X] - start.p_axis[X];
	delta.p_axis[Y] = end.p_axis[Y] - start.p_axis[Y];
	delta_x_sq = delta.p_axis[X] * delta.p_axis[X];
	delta_y_sq = delta.p_axis[Y] * delta.p_axis[Y];
	amount_pixels_to_draw = sqrt(delta_x_sq + delta_y_sq);
	delta.p_axis[X] /= amount_pixels_to_draw;
	delta.p_axis[Y] /= amount_pixels_to_draw;
	to_draw.p_axis[X] = start.p_axis[X];
	to_draw.p_axis[Y] = start.p_axis[Y];
	while (amount_pixels_to_draw > 0)
	{
		if (is_valid_coordinate(to_draw))
			draw_pixel(img, to_draw.p_axis[X], to_draw.p_axis[Y],
				start.color | end.color);
		to_draw.p_axis[X] += delta.p_axis[X];
		to_draw.p_axis[Y] += delta.p_axis[Y];
		amount_pixels_to_draw--;
	}
}

void	draw_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	uint8_t	*pixel;

	pixel = &img->pixels[(y * img->width + x) * sizeof(uint32_t)];
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color);
}

void	set_background(mlx_image_t *img, uint32_t color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
