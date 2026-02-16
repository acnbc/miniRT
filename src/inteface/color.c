/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:18:47 by jessica           #+#    #+#             */
/*   Updated: 2026/02/16 19:04:35 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// default value opacity = 255
unsigned int	conver_color(void *mlx_ptr, t_rgb *rgb, unsigned char opacity)
{
	unsigned int	color;
	int				rgba;

	rgba = (int)rgb->b;
	rgba += ((int)rgb->g << 8);
	rgba += ((int)rgb->r << 16);
	rgba += ((int)opacity << 24);
	color = mlx_get_color_value(mlx_ptr, rgba);
	return (color);
}
