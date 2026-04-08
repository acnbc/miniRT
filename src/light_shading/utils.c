/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:20:23 by jessica           #+#    #+#             */
/*   Updated: 2026/04/08 17:52:50 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	reflect(t_matrix *result, t_matrix *vector, t_matrix *normal)
{
	double		dot_matrix;
	t_matrix	mult;

	dot_matrix = dot_product(vector, normal);
	scalar_multiplication(&mult, normal, 2 * dot_matrix);
	subtract_tuple(result, vector, &mult);
}

void	default_material(t_material *material)
{
	material->color = (t_rgb){.r = 1, .g = 1, .b = 1};
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200;
}

t_light_base	calc_light_base(const t_hit_shade *in)
{
	t_light_base	base;
	t_matrix		tmp;

	rgb_scalar_multiplication(&base.ambient, &in->sc->amb_light->colors,
		in->sc->amb_light->light_ratio);
	rgb_multiplication(&base.effective_color, &in->mt->color,
		&in->sc->light->intensity);
	subtract_tuple(&tmp, &in->sc->light->point, in->o_pt);
	vector_normalization(&base.light_v, &tmp);
	base.light_dot_normal = dot_product(&base.light_v, in->nm);
	base.intensity = in->sc->light->intensity;
	base.in_shadow = is_shadowed(in);
	return (base);
}
