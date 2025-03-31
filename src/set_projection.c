/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_projection_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:31:14 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 12:31:16 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_projection_type(uint16_t view, t_program *fdf);
void	set_flat_view(t_camera *camera);
void	set_isometric_view(t_camera *camera);
void	set_parallel_view(t_camera *camera);

void	set_projection_type(uint16_t view, t_program *fdf)
{
	if (view == FLAT)
		set_flat_view(&fdf->camera);
	if (view == ISO)
		set_isometric_view(&fdf->camera);
	if (view == PAR)
		set_parallel_view(&fdf->camera);
}

void	set_flat_view(t_camera *camera)
{
	camera->rotation[X] = 0;
	camera->rotation[Y] = 0;
	camera->rotation[Z] = 0;
}

void	set_isometric_view(t_camera *camera)
{
	camera->rotation[X] = -35.264389682754654;
	camera->rotation[Y] = -30.000000000000004;
	camera->rotation[Z] = 35.26438968275465;
}

void	set_parallel_view(t_camera *camera)
{
	camera->rotation[X] = -90;
	camera->rotation[Y] = 0;
	camera->rotation[Z] = 0;
}
