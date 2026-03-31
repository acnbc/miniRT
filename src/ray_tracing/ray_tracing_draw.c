/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 00:00:00 by anogueir         #+#    #+#             */
/*   Updated: 2026/03/31 00:00:00 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	rt_ray_show_image(t_window *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->ptr, 0, 0);
}

void	rt_ray_trace_scanline(t_scene *scene, t_ray_gen *ctx, int y,
		unsigned int amb_c)
{
	t_ndc			ndc;
	t_ray			ray;
	t_intersect		hit;
	int				x;
	unsigned int	px;

	x = 0;
	while (x < scene->window->size_x)
	{
		rt_map_pixel_ndc(scene, x, y, &ndc);
		rt_make_primary_ray(ctx, &ndc, &ray);
		px = amb_c;
		if (rt_closest_hit_spheres(scene->objects, &ray, &hit))
			px = rt_shade_sphere_pixel(scene, &ray, &hit);
		pixel_put(scene->window, x, y, px);
		x++;
	}
}

void	rt_ray_trace_loop(t_scene *scene, t_ray_gen *ctx, t_tuple *amb)
{
	unsigned int		c;
	int					y;

	c = convert_color(amb);
	y = 0;
	while (y < scene->window->size_y)
	{
		rt_ray_trace_scanline(scene, ctx, y, c);
		y++;
	}
}

void	ray_tracer(t_scene *scene)
{
	t_ray_gen	ctx;
	t_tuple		amb;

	if (!scene || !scene->camera || !scene->window)
		return ;
	rt_ray_gen_init(&ctx, scene);
	rt_amb_tuple(scene, &amb);
	rt_ray_trace_loop(scene, &ctx, &amb);
	rt_ray_show_image(scene->window);
}
