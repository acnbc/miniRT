/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:18:47 by jessica           #+#    #+#             */
/*   Updated: 2026/03/30 01:06:14 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

unsigned int	convert_color(const t_tuple *tuple)
{
	unsigned int	color;
	t_rgb			rgb;

	rgb.r = fmax(0.0, fmin(tuple->x, 1.0)) * 255;
	rgb.g = fmax(0.0, fmin(tuple->y, 1.0)) * 255;
	rgb.b = fmax(0.0, fmin(tuple->z, 1.0)) * 255;
	color = 0;
	color += (int)rgb.b;
	color += ((int)rgb.g << 8);
	color += ((int)rgb.r << 16);
	return (color);
}

void	pixel_put(t_window *win, int x, int y, unsigned int color)
{
	char			*dest;
	int				point_x;
	int				point_y;

	if (x < 0 || x >= win->size_x || y < 0 || y >= win->size_y)
		return ;
	point_x = x * (win->img->bits_per_pixel / 8);
	point_y = y * win->img->size_line;
	dest = win->img->addr + (point_y + point_x);
	*(unsigned int *)dest = color;
}
