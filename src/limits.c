/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:48:27 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 10:38:43 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	set_limits(t_map_data *map_data);
int	get_max_x(char *line);
int	get_max_y(char	**line, t_map_data *map_data);

int	set_limits(t_map_data *map_data)
{
	char	*line;

	if (set_map_fd(map_data) == FAIL)
		return (FAIL);
	line = get_next_line(map_data->fd);
	if (line == NULL)
		return (FAIL);
	map_data->max_x = get_max_x(line);
	if (map_data->max_x == -1)
	{
		ft_free_and_null(&line);
		close(map_data->fd);
		return (FAIL);
	}
	map_data->max_y = get_max_y(&line, map_data);
	map_data->total_points = map_data->max_x * map_data->max_y;
	close(map_data->fd);
	return (SUCCESS);
}

int	get_max_x(char *line)
{
	int		i;
	char	**array;

	i = 0;
	array = ft_split(line, ' ');
	if (array == NULL)
		return (-1);
	while (array[i])
		i++;
	ft_free_strs(&array);
	return (i);
}

int	get_max_y(char	**line, t_map_data *map_data)
{
	int	i;

	i = 0;
	while (*line)
	{
		i++;
		ft_free_and_null(line);
		*line = get_next_line(map_data->fd);
	}
	return (i);
}
