/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:56:26 by elie              #+#    #+#             */
/*   Updated: 2024/07/23 13:12:50 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

uint32_t	get_hex_color(char *str);
void		set_color(t_point *point, char *point_as_str);

uint32_t	get_hex_color(char *str)
{
	char		*color_as_hex;
	int			len;
	uint32_t	return_color;
	int			i;
	int			j;

	i = 0;
	while (str[i] != ',')
		i++;
	i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	len = ft_strlen(&str[i]);
	if (len >= 8)
		return (ft_hex_to_uint(str));
	color_as_hex = ft_strdup("000000FF");
	j = 0;
	while (len++ < 6)
		j++;
	while (str[i] && str[i] != '\n' && j <= 6)
		color_as_hex[j++] = str[i++];
	return_color = ft_hex_to_uint(color_as_hex);
	ft_free_and_null(&color_as_hex);
	return (return_color);
}

void	set_color(t_point *point, char *point_as_str)
{
	uint32_t	color;

	color = GREY_DARK;
	if (ft_strchr(point_as_str, ','))
		color = get_hex_color(point_as_str);
	point->color = color;
}
