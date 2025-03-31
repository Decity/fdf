/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:44:04 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 16:26:23 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	set_map_data(t_program *fdf);
int	set_map_name_and_path(t_program *fdf);
int	set_map_fd(t_map_data *map_data);
int	copy_map(t_map_data *map_data);
int	copy_row_strs(t_map_data *map_data);

int	set_map_data(t_program *fdf)
{
	if (set_map_name_and_path(fdf) == FAIL)
		fdf_exit(fdf, "Set map name and path");
	if (set_limits(fdf->map_data) == FAIL)
		fdf_exit(fdf, "Set limits");
	if (copy_map(fdf->map_data) == FAIL)
		fdf_exit(fdf, "Copy map");
	return (SUCCESS);
}

int	set_map_name_and_path(t_program *fdf)
{
	if (fdf->argc != 2)
	{
		errno = EINVAL;
		ft_putendl_fd("Invalid amount of arguments given", 2);
		return (FAIL);
	}
	fdf->map_data->map_path = ft_strjoin("./maps/", fdf->argv[1]);
	if (!fdf->map_data->map_path)
		return (FAIL);
	return (SUCCESS);
}

int	set_map_fd(t_map_data *map_data)
{
	int	fd;

	fd = open(map_data->map_path, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	map_data->fd = fd;
	return (SUCCESS);
}

int	copy_map(t_map_data *map_data)
{
	if (set_map_fd(map_data) == FAIL)
		return (FAIL);
	map_data->map = ft_calloc(map_data->max_y + 1, sizeof(char *));
	if (map_data->map == NULL)
	{
		close(map_data->fd);
		return (FAIL);
	}
	if (copy_row_strs(map_data) == FAIL)
	{
		ft_free_strs(&map_data->map);
		close(map_data->fd);
		return (FAIL);
	}
	close(map_data->fd);
	return (SUCCESS);
}

int	copy_row_strs(t_map_data *map_data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(map_data->fd);
	while (line)
	{
		map_data->map[i] = ft_strdup(line);
		if (!map_data->map[i])
		{
			ft_free_and_null(&line);
			return (FAIL);
		}
		ft_free_and_null(&line);
		line = get_next_line(map_data->fd);
		i++;
	}
	return (SUCCESS);
}
