/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:30:13 by W2Wizard          #+#    #+#             */
/*   Updated: 2024/03/12 09:59:16 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

// BUG: Linux may experience a red hue instead due to endianness
void mlx_draw_pixel(uint8_t* pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);

	// // Extract individual components (Red, Green, Blue, Alpha) from the hex value
    // uint8_t red = (uint8_t)((color_hex >> 24) & 0xFF);
    // uint8_t green = (uint8_t)((color_hex >> 16) & 0xFF);
    // uint8_t blue = (uint8_t)((color_hex >> 8) & 0xFF);
    // uint8_t alpha = (uint8_t)(color_hex & 0xFF);

    // // Fill in missing values with 00s for colors and FF for alpha
    // red = (red == 0xFF) ? 0x00 : red;
    // green = (green == 0xFF) ? 0x00 : green;
    // blue = (blue == 0xFF) ? 0x00 : blue;
    // alpha = (alpha == 0xFF) ? 0xFF : alpha;

    // // Store the complete RGBA values in the pixel buffer
    // *(pixel++) = red;
    // *(pixel++) = green;
    // *(pixel++) = blue;
    // *(pixel++) = alpha;

}

//= Public =//

void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color)
{
	MLX_NONNULL(image);
	MLX_ASSERT(x < image->width, "Pixel is out of bounds");
	MLX_ASSERT(y < image->height, "Pixel is out of bounds");

	uint8_t* pixelstart = &image->pixels[(y * image->width + x) * BPP];
	mlx_draw_pixel(pixelstart, color);
}
