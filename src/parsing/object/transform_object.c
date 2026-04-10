/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:34:25 by jessica           #+#    #+#             */
/*   Updated: 2026/04/08 07:36:16 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static void		rotate_object(t_matrix *rotate, t_matrix *normalized_vector);
static t_matrix	inverse_matrix_multiplication(t_object *object,
					t_matrix *rotate, t_matrix *scale, t_matrix *translate);
static void		copy_values(t_matrix *rotate, t_matrix *right,
					t_matrix *forward, t_matrix *up);

void	translation(t_matrix *matrix, const t_matrix *offset)
{
	if (!matrix || !offset)
	{
		init_identity_matrix(matrix, 4);
		return ;
	}
	init_identity_matrix(matrix, 4);
	mat_set(matrix, 0, 3, offset->m_4x1[0]);
	mat_set(matrix, 1, 3, offset->m_4x1[1]);
	mat_set(matrix, 2, 3, offset->m_4x1[2]);
}

void	transformation_matrix(t_object *object)
{
	t_matrix	scale;
	t_matrix	translate;
	t_matrix	rotate;
	t_matrix	*normalized_vector;
	double		ray;

	init_identity_matrix(&rotate, 4);
	normalized_vector = NULL;
	translation(&translate, &object->coord);
	if (object->id == sp)
	{
		ray = object->object.sphere.diameter / 2;
		init_scaling_matrix(&scale, ray, ray, ray);
	}
	if (object->id == pl)
		normalized_vector = &object->object.plane.normalized_vector;
	if (object->id == cy)
	{
		ray = object->object.cylinder.diameter / 2;
		init_scaling_matrix(&scale, ray, object->object.cylinder.height, ray);
		normalized_vector = &object->object.cylinder.normalized_vector;
	}
	if (normalized_vector)
		rotate_object(&rotate, normalized_vector);
	inverse_matrix_multiplication(object, &rotate, &scale, &translate);
}

static t_matrix	inverse_matrix_multiplication(t_object *object,
				t_matrix *rotate, t_matrix *scale, t_matrix *translate)
{
	t_matrix	tmp;
	t_matrix	base;

	if (object->id == cy)
		matrix_multiplication(&tmp, rotate, scale);
	else if (object->id == pl)
		tmp = *rotate;
	else if (object->id == sp)
		tmp = *scale;
	matrix_multiplication(&base, translate, &tmp);
	if (is_invertible(&base))
		inverse_matrix(&object->inverse_matrix, &base);
	else
		init_identity_matrix(&object->inverse_matrix, 4);
	return (base);
}

static void	rotate_object(t_matrix *rotate, t_matrix *normalized_vector)
{
	t_matrix	world_up;
	t_matrix	tmp;
	t_matrix	forward;
	t_matrix	right;
	t_matrix	up;

	vector_normalization(&forward, normalized_vector);
	init_vector(&world_up, 0, 1, 0);
	if (fabs(dot_product(&forward, &world_up)) > 1.0 - 1e-6)
		init_vector(&world_up, 0, 0, 1);
	cross_product(&tmp, &forward, &world_up);
	vector_normalization(&right, &tmp);
	cross_product(&tmp, &right, &forward);
	vector_normalization(&up, &tmp);
	init_matrix(rotate, 4, 4);
	copy_values(rotate, &right, &forward, &up);
}

static void	copy_values(t_matrix *rotate, t_matrix *right, t_matrix *forward,
				t_matrix *up)
{
	int			col;
	int			row;

	col = 0;
	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (col == 0)
				rotate->m_4x4[row * 4 + col] = right->m_4x1[row];
			if (col == 1)
				rotate->m_4x4[row * 4 + col] = forward->m_4x1[row];
			if (col == 2)
				rotate->m_4x4[row * 4 + col] = up->m_4x1[row];
			col++;
		}
		row++;
	}
	rotate->m_4x4[15] = 1.0;
}
