/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:20:23 by jessica           #+#    #+#             */
/*   Updated: 2026/03/31 15:25:31 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	local_normal_at(t_matrix *object_normal,
				t_matrix *object_point);

void	normal_at(t_matrix *normal, t_object *object, t_matrix *point)
{
	t_matrix	inverse;
	t_matrix	transpose_inverse;
	t_matrix	object_point;
	t_matrix	object_normal;
	t_matrix	world_normal;
	t_matrix	tmp;

	if (object->id == sp && object->coord.rows == 4 && object->coord.cols == 1)
	{
		subtract_tuple(&tmp, point, &object->coord);
		vector_normalization(normal, &tmp);
		return ;
	}
	inverse_matrix(&inverse, &object->coord);
	matrix_tuple_multiplication(&object_point, &inverse, point);
	matrix_transposition(&transpose_inverse, &inverse);
	local_normal_at(&object_normal, &object_point);
	matrix_tuple_multiplication(&world_normal, &transpose_inverse,
		&object_normal);
	world_normal.m_4x1[3] = 0.0;
	vector_normalization(normal, &world_normal);
}

static void	local_normal_at(t_matrix *object_normal,
				t_matrix *object_point)
{
	t_matrix	origin;

	init_point(&origin, 0, 0, 0);
	subtract_tuple(object_normal, object_point, &origin);
}

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
	material->color = (t_tuple){1, 1, 1, 0};
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200;
}

t_light_base	calc_light_base(const t_light *light, const t_matrix *position,
					const t_material *material, const t_matrix *norm_v)
{
	t_light_base	base;
	t_matrix		tmp;

	tuple_multiplication(&base.effective_color, &material->color,
		&light->intensity);
	subtract_tuple(&tmp, &light->point, position);
	vector_normalization(&base.light_v, &tmp);
	base.light_dot_normal = dot_product(&base.light_v, norm_v);
	base.intensity = light->intensity;
	return (base);
}
