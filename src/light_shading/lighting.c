/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:30:22 by jessica           #+#    #+#             */
/*   Updated: 2026/03/30 02:46:50 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static t_tuple	calc_specular(t_material *material, t_light_base *light_calc,
					t_matrix *eye_v, t_matrix *norm_v);

t_tuple	lighting(t_light_base *base, t_material *material,
			t_matrix *eye_v, t_matrix *norm_v)
{
	t_tuple		ambient;
	t_tuple		diffuse;
	t_tuple		specular;
	double		mult;
	t_tuple		result;

	tuple_scalar_multiplication(&ambient, &base->effective_color,
		material->ambient);
	specular = calc_specular(material, base, eye_v, norm_v);
	diffuse = (t_tuple){0, 0, 0, 0};
	if (base->light_dot_normal >= 0)
	{
		mult = material->diffuse * base->light_dot_normal;
		tuple_scalar_multiplication(&diffuse, &base->effective_color,
			mult);
	}
	tuple_addition(&result, &ambient, &diffuse);
	tuple_addition(&result, &result, &specular);
	return (result);
}

static t_tuple	calc_specular(t_material *material, t_light_base *base,
					t_matrix *eye_v, t_matrix *norm_v)
{
	t_tuple		specular;
	t_matrix	neg_light_v;
	t_matrix	v_reflect;
	double		reflect_dot_eye;
	double		factor;

	specular = (t_tuple){0, 0, 0, 0};
	if (base->light_dot_normal < 0)
		return (specular);
	negate_tuple(&neg_light_v, &base->light_v);
	reflect(&v_reflect, &neg_light_v, norm_v);
	reflect_dot_eye = dot_product(&v_reflect, eye_v);
	if (reflect_dot_eye > 0)
	{
		factor = pow(reflect_dot_eye, material->shininess);
		tuple_scalar_multiplication(&specular, &base->intensity,
			material->specular * factor);
	}
	return (specular);
}
