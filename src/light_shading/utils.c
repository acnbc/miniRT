/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:20:23 by jessica           #+#    #+#             */
/*   Updated: 2026/03/30 01:39:44 by jessica          ###   ########.fr       */
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
