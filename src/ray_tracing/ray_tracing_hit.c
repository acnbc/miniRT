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

size_t	count_objects(t_object *objects)
{
	size_t	n;

	n = 0;
	while (objects)
	{
		n++;
		objects = objects->next;
	}
	return (n);
}

size_t	fill_sphere_hits(t_object *objects, t_ray *ray, t_intersect *buf,
		t_intersect pair[2])
{
	size_t	n;
	t_ray	transf_ray;

	n = 0;
	while (objects)
	{
		if (objects->id == sp && objects->object.sphere)
		{
			transform_ray(&transf_ray, &objects, &ray);
			sp_intersect(pair, objects, &transf_ray);
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

size_t	fill_pl_hits(t_object *objects, t_ray *ray, t_intersect *buf,
	t_intersect pair[1])
{
	size_t	n;
	t_ray	transf_ray;

	n = 0;
	while (objects)
	{
		if (objects->id == pl && objects->object.plane)
		{
			transform_ray(&transf_ray, &objects, &ray);
			pl_intersect(pair, objects, &transf_ray);
			if (pair[0].obj)
			{
				buf[n] = pair[0];
				n++;
			}
		}
		objects = objects->next;
	}
	return (n);
}

size_t	fill_cy_hits(t_object *objects, t_ray *ray, t_intersect *buf,
	t_intersect pair[4])
{
	size_t	n;
	size_t	i;
	t_ray	transf_ray;

	n = 0;
	while (objects)
	{
		if (objects->id == cy && objects->object.cylinder)
		{
			transform_ray(&transf_ray, &objects, &ray);
			cy_intersect(pair, objects, &transf_ray);
			i = 0;
			while (i < 4)
			{
				if (pair[i].obj)
				{
					buf[n] = pair[i];
					n++;
				}
				i++;
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

	cap = count_objects(objects);
	if (cap == 0)
		return (false);
	buf = (t_intersect *)safe_malloc(2 * cap * sizeof(t_intersect));
	n += fill_sphere_hits(objects, ray, buf, pair);
	return (resolve_closest_hit(buf, n, out_hit));
}
