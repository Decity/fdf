/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:27:52 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 16:14:38 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/inc/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./definitions.h"

// init
void		init_fdf(t_program *fdf, int argc, char **argv);
void		init_mlx(t_program *fdf);
int			init_map_data(t_program *fdf);

// camera
void		set_camera(t_program *fdf);
void		set_scale(t_map_data *map_data, t_camera *camera);
void		set_offset(t_camera *camera);

// set projection
void		set_projection_type(uint16_t view, t_program *fdf);
void		set_flat_view(t_camera *camera);
void		set_isometric_view(t_camera *camera);
void		set_parallel_view(t_camera *camera);

// map
int			set_map_data(t_program *fdf);
int			set_map_name_and_path(t_program *fdf);
int			set_map_fd(t_map_data *map_data);
int			copy_map(t_map_data *map_data);
int			copy_row_strs(t_map_data *map_data);

// limits
int			set_limits(t_map_data *map_data);
int			get_max_x(char *line);
int			get_max_y(char	**line, t_map_data *map_data);

// points
int			set_point_data(t_program *fdf);
int			malloc_points(t_map_data *map_data);
int			set_all_rows(t_map_data *map_data);
void		set_row_of_points(t_map_data *map_data, char **points, int column);
int			set_point(t_map_data *map_data, char *point_str, int row, int col);

// transforms
void		apply_transforms(t_map_data *map_data, t_camera camera);
void		scale(t_map_data *map_data, t_camera camera);
void		translate(t_map_data *map_data, t_camera camera);
void		rotate(t_map_data *map_data, t_camera camera);
void		rotate_x(float *y, float *z, double x_angle_degrees);
void		rotate_y(float *x, float *z, double y_angle_degrees);
void		rotate_z(float *x, float *y, double z_angle_degrees);

// colors
uint32_t	get_hex_color(char *str);
void		set_color(t_point *point, char *point_as_str);

// draw
void		draw(t_program *fdf);
void		draw_wireframe(t_map_data *map_data, mlx_image_t *img);
void		draw_line(mlx_image_t *img, t_point start, t_point end);
void		draw_pixel(mlx_image_t *img,
				uint32_t x, uint32_t y, uint32_t color);
void		set_background(mlx_image_t *img, uint32_t color);

// free
void		free_all(t_program *fdf);
void		free_map_name_and_path(t_map_data *map_data);
void		free_point_row(t_point **point);
void		free_points(t_map_data *map_data);

// hooks
void		controls(void *param);
void		change_view(t_program *fdf);
void		exit_hook(void *param);

// transform hooks
void		zoom(t_program *fdf);
void		move(t_program *fdf);
void		turn(t_program *fdf);
void		turn_axis(int axis, int deg, t_program *fdf);

// utils
bool		is_valid_coordinate(t_point point);
void		fdf_exit(t_program *fdf, const char *error_str);
void		exit_hook(void *param);
void		mlx_err_exit(t_program *fdf);

#endif
