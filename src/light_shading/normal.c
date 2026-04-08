/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:52:41 by jessica           #+#    #+#             */
/*   Updated: 2026/04/08 10:32:31 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	local_normal_at_plane(t_matrix *normal, t_object *object);
static void	local_normal_at_cylinder(t_matrix *normal, t_matrix *local_point);
static void	local_normal_at_sphere(t_matrix *local_normal,
				t_matrix *local_point);

void	normal_at(t_matrix *normal, t_object *object, t_matrix *point)
{
	t_matrix	transpose_inverse;
	t_matrix	local_point;
	t_matrix	local_n;
	t_matrix	world_n;

	matrix_tuple_multiplication(&local_point, &object->inverse_matrix, point);
	if (object->id == sp)
		local_normal_at_sphere(&local_n, &local_point);
	if (object->id == pl)
		local_normal_at_plane(&local_n, object);
	if (object->id == cy)
		local_normal_at_cylinder(&local_n, &local_point);
	matrix_transposition(&transpose_inverse, &object->inverse_matrix);
	matrix_tuple_multiplication(&world_n, &transpose_inverse, &local_n);
	world_n.m_4x1[3] = 0.0;
	vector_normalization(normal, &world_n);
}

static void	local_normal_at_plane(t_matrix *normal, t_object *object)
{
	*normal = object->object.plane.normalized_vector;
}

static void	local_normal_at_sphere(t_matrix *local_normal,
		t_matrix *local_point)
{
	t_matrix	center;

	init_point(&center, 0, 0, 0);
	subtract_tuple(local_normal, local_point, &center);
}

void	local_normal_at_cylinder(t_matrix *normal, t_matrix *local_point)
{
	double	distance;

	distance = pow(local_point->m_4x1[0], 2) + pow(local_point->m_4x1[2], 2);
	if (distance < 1.0 && local_point->m_4x1[1] >= 0.5 - EPSILON)
		init_vector(normal, 0, 1, 0);
	if (distance < 1.0 && local_point->m_4x1[1] <= -0.5 + EPSILON)
		init_vector(normal, 0, -1, 0);
	else
		init_vector(normal, local_point->m_4x1[0], 0, local_point->m_4x1[2]);
}
