/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_shade.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 00:00:00 by anogueir         #+#    #+#             */
/*   Updated: 2026/03/31 00:00:00 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	rt_rgb_to_tuple(t_tuple *out, const t_rgb *rgb)
{
	out->x = rgb->r / 255.0;
	out->y = rgb->g / 255.0;
	out->z = rgb->b / 255.0;
	out->is_point = false;
}

void	rt_scene_amb_times_material(t_tuple *out, t_scene *scene,
		const t_tuple *mat_color)
{
	double	ratio;

	if (!scene->amb_light)
	{
		*out = (t_tuple){0, 0, 0, 0};
		return ;
	}
	ratio = scene->amb_light->light_ratio;
	out->x = (scene->amb_light->colors.r / 255.0) * ratio * mat_color->x;
	out->y = (scene->amb_light->colors.g / 255.0) * ratio * mat_color->y;
	out->z = (scene->amb_light->colors.b / 255.0) * ratio * mat_color->z;
	out->is_point = false;
}

void	rt_shade_orient_normal(t_matrix *norm, t_ray *ray)
{
	t_matrix	eye;
	t_matrix	flipped;

	negate_tuple(&eye, &ray->direc);
	if (dot_product(norm, &eye) < 0.0)
	{
		negate_tuple(&flipped, norm);
		*norm = flipped;
	}
}

t_tuple	rt_shade_lit_color(t_hit_shade *in)
{
	t_tuple			amb;
	t_tuple			final;
	t_light_base	base;
	t_tuple			lit;
	t_matrix		eye;

	rt_scene_amb_times_material(&amb, in->sc, &in->mt->color);
	if (!in->sc->light)
		return (amb);
	negate_tuple(&eye, &in->ray->direc);
	base = calc_light_base(in->sc->light, in->pt, in->mt, in->nm);
	lit = lighting(&base, in->mt, &eye, in->nm);
	tuple_addition(&final, &amb, &lit);
	return (final);
}

unsigned int	rt_shade_sphere_pixel(t_scene *scene, t_ray *ray,
		t_intersect *hit)
{
	t_matrix		hit_pt;
	t_matrix		norm_v;
	t_material		mat;
	t_hit_shade		sh;
	t_tuple			color;

	position(&hit_pt, ray, hit->t);
	normal_at(&norm_v, hit->obj, &hit_pt);
	rt_shade_orient_normal(&norm_v, ray);
	mat = hit->obj->material;
	rt_rgb_to_tuple(&mat.color, &hit->obj->colors);
	mat.ambient = 0.0;
	sh.sc = scene;
	sh.ray = ray;
	sh.pt = &hit_pt;
	sh.nm = &norm_v;
	sh.mt = &mat;
	color = rt_shade_lit_color(&sh);
	return (convert_color(&color));
}
