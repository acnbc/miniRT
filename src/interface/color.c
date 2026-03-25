/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:18:47 by jessica           #+#    #+#             */
/*   Updated: 2026/03/23 22:48:32 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// default value opacity = 0
unsigned int	convert_color(t_rgb *rgb, unsigned char opacity)
{
	unsigned int	color;

	color = 0;
	color += (int)rgb->b;
	color += ((int)rgb->g << 8);
	color += ((int)rgb->r << 16);
	color += ((int)opacity << 24);
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
