/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 00:00:00 by anogueir         #+#    #+#             */
/*   Updated: 2026/03/31 00:00:00 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

size_t	count_spheres(t_object *objects)
{
	size_t	n;

	n = 0;
	while (objects)
	{
		if (objects->id == sp && objects->object.sphere)
			n++;
		objects = objects->next;
	}
	return (n);
}

size_t	fill_sphere_hits(t_object *objects, t_ray *ray, t_intersect *buf,
		t_intersect pair[2])
{
	size_t	n;

	n = 0;
	while (objects)
	{
		if (objects->id == sp && objects->object.sphere)
		{
			sp_intersect(pair, objects, ray);
			if (pair[0].obj && pair[1].obj)
			{
				buf[n] = pair[0];
				buf[n + 1] = pair[1];
				n += 2;
			}
		}
		objects = objects->next;
	}
	return (n);
}

bool	resolve_closest_hit(t_intersect *buf, size_t n, t_intersect *out_hit)
{
	t_intersections	inters;
	t_intersect		*winner;

	if (n == 0)
	{
		free(buf);
		return (false);
	}
	inters.inter = buf;
	inters.n_inter = (int)n;
	winner = hit(&inters);
	if (winner)
		*out_hit = *winner;
	free(buf);
	return (winner != NULL);
}

bool	closest_hit_spheres(t_object *objects, t_ray *ray,
		t_intersect *out_hit)
{
	t_intersect	pair[2];
	t_intersect	*buf;
	size_t		cap;
	size_t		n;

	cap = count_spheres(objects);
	if (cap == 0)
		return (false);
	buf = (t_intersect *)safe_malloc(2 * cap * sizeof(t_intersect));
	n = fill_sphere_hits(objects, ray, buf, pair);
	return (resolve_closest_hit(buf, n, out_hit));
}

void	amb_tuple(t_scene *scene, t_tuple *out)
{
	if (!scene->amb_light)
	{
		out->x = 0;
		out->y = 0;
		out->z = 0;
		out->is_point = false;
		return ;
	}
	out->x = (scene->amb_light->colors.r / 255.0)
		* scene->amb_light->light_ratio;
	out->y = (scene->amb_light->colors.g / 255.0)
		* scene->amb_light->light_ratio;
	out->z = (scene->amb_light->colors.b / 255.0)
		* scene->amb_light->light_ratio;
	out->is_point = false;
}
