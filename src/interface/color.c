/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:18:47 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 01:22:48 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static unsigned int	convert_color_pixel(const t_tuple *rgb)
{
	unsigned int	color;
	int				r;
	int				g;
	int				b;

	r = (int)fmax(0.0, fmin(rgb->r * 255.0, 255.0));
	g = (int)fmax(0.0, fmin(rgb->g * 255.0, 255.0));
	b = (int)fmax(0.0, fmin(rgb->b * 255.0, 255.0));
	color = 0;
	color += b;
	color += (g << 8);
	color += (r << 16);
	return (color);
}

void	pixel_put(t_window *win, int x, int y, t_tuple *rgb)
{
	char			*dest;
	int				point_x;
	int				point_y;
	unsigned int	color;

	if (x < 0 || x >= win->size_x || y < 0 || y >= win->size_y)
		return ;
	point_x = x * (win->img->bits_per_pixel / 8);
	point_y = y * win->img->size_line;
	dest = win->img->addr + (point_y + point_x);
	color = convert_color_pixel(rgb);
	*(unsigned int *)dest = color;
}
