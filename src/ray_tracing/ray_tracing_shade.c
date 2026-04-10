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

void	shade_orient_normal(t_matrix *norm, t_ray *ray)
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

t_rgb	shade_lit_color(t_hit_shade *in)
{
	t_light_base	base;
	t_rgb			lit;
	t_matrix		eye;

	negate_tuple(&eye, &in->ray->direc);
	base = calc_light_base(in);
	lit = lighting(&base, in->mt, &eye, in->nm);
	return (lit);
}

t_rgb	shade_pixel(t_scene *scene, t_ray *ray, t_intersect *hit)
{
	t_matrix	hit_pt;
	t_matrix	norm_v;
	t_matrix	over_point;
	t_material	mat;
	t_hit_shade	sh;

	position(&hit_pt, ray, hit->t);
	normal_at(&norm_v, hit->obj, &hit_pt);
	shade_orient_normal(&norm_v, ray);
	calc_over_point(&over_point, &norm_v, &hit_pt);
	mat = hit->obj->material;
	sh.sc = scene;
	sh.ray = ray;
	sh.pt = &hit_pt;
	sh.nm = &norm_v;
	sh.mt = &mat;
	sh.o_pt = &over_point;
	return (shade_lit_color(&sh));
}

void	calc_over_point(t_matrix *over_point, const t_matrix *norm_v,
		const t_matrix *hit_pt)
{
	t_matrix	tmp;

	scalar_multiplication(&tmp, norm_v, EPSILON);
	add_tuples(over_point, hit_pt, &tmp);
}
