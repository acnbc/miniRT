/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:12:48 by anogueir          #+#    #+#             */
/*   Updated: 2026/04/08 18:46:08 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	ray_show_image(t_window *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->ptr, 0, 0);
}

void	ray_trace_scanline(t_scene *scene, t_ray_gen *context, int y)
{
	t_ndc		ndc;
	t_ray		ray;
	t_intersect	hit;
	int			x;
	t_tuple		px;

	x = 0;
	while (x < scene->window->size_x)
	{
		map_pixel_ndc(scene, x, y, &ndc);
		make_primary_ray(context, &ndc, &ray);
		px = (t_rgb){.r = 0, .g = 0, .b = 0};
		if (closest_hit(scene->objects, &ray, &hit))
			px = shade_pixel(scene, &ray, &hit);
		put_pixel(scene->window, x, y, &px);
		x++;
	}
}

void	ray_trace_loop(t_scene *scene, t_ray_gen *context)
{
	int	y;

	y = 0;
	while (y < scene->window->size_y)
	{
		ray_trace_scanline(scene, context, y);
		y++;
	}
}

void	ray_tracer(t_scene *scene)
{
	t_ray_gen	context;

	if (!scene || !scene->camera || !scene->window)
		return ;
	printf("desenhando imagem...\n");
	ray_gen_init(&context, scene);
	ray_trace_loop(scene, &context);
	ray_show_image(scene->window);
	printf("imagem desenhada!\n");
}
