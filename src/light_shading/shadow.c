/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:38:40 by jessica           #+#    #+#             */
/*   Updated: 2026/04/04 00:25:25 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	is_shadowed(const t_hit_shade *in)
{
	t_matrix	vector;
	double		distance;
	t_matrix	direction;
	t_ray		ray;
	t_intersect	intersect;

	subtract_tuple(&vector, &in->sc->light->point, in->o_pt);
	distance = vector_magnitude(&vector);
	vector_normalization(&direction, &vector);
	create_ray(&ray, *in->o_pt, direction);
	if (closest_hit_spheres(in->sc->objects, &ray, &intersect))
	{
		if (intersect.t < distance)
			return (true);
	}
	return (false);
}
