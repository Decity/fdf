/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:17:07 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 16:13:59 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define SUCCESS 1
# define FAIL 0

# define X 0
# define Y 1
# define Z 2

# ifndef HEX_BASE
#  define HEX_BASE	"0123456789ABCDEF"
# endif

# define FLAT		0
# define ISO		1
# define PAR		2

# define PI			3.14159265358979323846

# define BLACK		0x151515FF
# define WHITE		0xFFFFFFFF
# define RED		0xFF0000FF
# define GREY_LIGHT	0xBDBDBDFF
# define GREY		0x505050FF
# define GREY_DARK	0x212121FF

typedef struct s_point
{
	float		axis[3];
	float		p_axis[3];
	uint32_t	color;
}	t_point;

typedef struct s_camera
{
	double		rotation[3];
	double		offset[2];
	float		scale;
}	t_camera;

typedef struct s_map_data
{
	char	*map_path;
	int		fd;
	char	**map;
	t_point	**points;
	int		total_points;
	int		max_x;
	int		max_y;
	int		lowest_z;
	int		highest_z;
}	t_map_data;

typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map_data	*map_data;
	t_camera	camera;
	int			argc;
	char		**argv;
}	t_program;

#endif
