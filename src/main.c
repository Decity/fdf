/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:16:07 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 16:19:46 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_program	fdf;

	init_fdf(&fdf, argc, argv);
	set_map_data(&fdf);
	set_camera(&fdf);
	set_point_data(&fdf);
	init_mlx(&fdf);
	draw(&fdf);
	mlx_loop_hook(fdf.mlx, exit_hook, fdf.mlx);
	mlx_loop_hook(fdf.mlx, controls, &fdf);
	mlx_loop(fdf.mlx);
	free_all(&fdf);
	return (EXIT_SUCCESS);
}
