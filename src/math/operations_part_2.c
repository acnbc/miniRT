/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:56:07 by anogueir          #+#    #+#             */
/*   Updated: 2026/04/03 15:10:49 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	vector_magnitude(const t_matrix *tuple)
{
	double	magnitude;
	double	temp;

	temp = pow(tuple->m_4x1[0], 2) + pow(tuple->m_4x1[1], 2)
		+ pow(tuple->m_4x1[2], 2);
	magnitude = sqrt(temp);
	return (magnitude);
}

void	vector_normalization(t_matrix *matrix, const t_matrix *vector)
{
	double		magnitude;

	magnitude = vector_magnitude(vector);
	if (!matrix || magnitude < EPSILON)
		return ;
	init_matrix(matrix, 4, 1);
	matrix->m_4x1[0] = vector->m_4x1[0] / magnitude;
	matrix->m_4x1[1] = vector->m_4x1[1] / magnitude;
	matrix->m_4x1[2] = vector->m_4x1[2] / magnitude;
	matrix->m_4x1[3] = vector->m_4x1[3];
}

double	dot_product(const t_matrix *a, const t_matrix *b)
{
	return ((a->m_4x1[0] * b->m_4x1[0]) + (a->m_4x1[1] * b->m_4x1[1])
		+ (a->m_4x1[2] * b->m_4x1[2]));
}

void	cross_product(t_matrix *matrix, const t_matrix *a, const t_matrix *b)
{
	if (!matrix)
		return ;
	init_matrix(matrix, 4, 1);
	matrix->m_4x1[0] = (a->m_4x1[1] * b->m_4x1[2])
		- (a->m_4x1[2] * b->m_4x1[1]);
	matrix->m_4x1[1] = (a->m_4x1[2] * b->m_4x1[0])
		- (a->m_4x1[0] * b->m_4x1[2]);
	matrix->m_4x1[2] = (a->m_4x1[0] * b->m_4x1[1])
		- (a->m_4x1[1] * b->m_4x1[0]);
	matrix->m_4x1[3] = 0.0;
}
