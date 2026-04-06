/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_fills.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 16:58:02 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/04/06 09:31:06 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

size_t	fill_sphere_hits(t_object *objects, t_ray *ray, t_intersect *buf,
		t_intersect pair[2])
{
	size_t	n;
	t_ray	transf_ray;

	n = 0;
	transform_ray(&transf_ray, objects, ray);
	sp_intersect(pair, objects, &transf_ray);
	if (pair[0].obj && pair[1].obj)
	{
		buf[n] = pair[0];
		buf[n + 1] = pair[1];
		n += 2;
	}
	return (n);
}

size_t	fill_pl_hits(t_object *objects, t_ray *ray, t_intersect *buf,
	t_intersect pair[1])
{
	size_t	n;
	t_ray	transf_ray;

	n = 0;
	transform_ray(&transf_ray, objects, ray);
	pl_intersect(pair, objects, &transf_ray);
	if (pair[0].obj)
	{
		buf[n] = pair[0];
		n++;
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
	transform_ray(&transf_ray, objects, ray);
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
	return (n);
}

size_t	fill_hits(t_object *objects, t_ray *ray, t_intersect *buf,
	t_intersect pair[4])
{
	size_t	n;

	n = 0;
	while (objects)
	{
		if (objects->id == sp && objects->object.sphere)
			n += fill_sphere_hits(objects, ray, buf, pair);
		else if (objects->id == pl && objects->object.plane)
			n += fill_pl_hits(objects, ray, buf, pair);
		else if (objects->id == cy && objects->object.cylinder)
			n += fill_cy_hits(objects, ray, buf, pair);
		objects = objects->next;
	}
	return (n);
}
