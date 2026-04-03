/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:56:47 by anogueir          #+#    #+#             */
/*   Updated: 2026/04/03 15:09:46 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	add_tuples(t_matrix *matrix, const t_matrix *a, const t_matrix *b)
{
	if (!matrix)
		return ;
	init_matrix(matrix, 4, 1);
	matrix->m_4x1[0] = a->m_4x1[0] + b->m_4x1[0];
	matrix->m_4x1[1] = a->m_4x1[1] + b->m_4x1[1];
	matrix->m_4x1[2] = a->m_4x1[2] + b->m_4x1[2];
	matrix->m_4x1[3] = a->m_4x1[3] + b->m_4x1[3];
}

void	subtract_tuple(t_matrix *matrix, const t_matrix *a, const t_matrix *b)
{
	if (!matrix)
		return ;
	init_matrix(matrix, 4, 1);
	matrix->m_4x1[0] = a->m_4x1[0] - b->m_4x1[0];
	matrix->m_4x1[1] = a->m_4x1[1] - b->m_4x1[1];
	matrix->m_4x1[2] = a->m_4x1[2] - b->m_4x1[2];
	matrix->m_4x1[3] = a->m_4x1[3] - b->m_4x1[3];
}

void	negate_tuple(t_matrix *matrix, const t_matrix *tuple)
{
	if (!matrix)
		return ;
	init_matrix(matrix, 4, 1);
	matrix->m_4x1[0] = -(tuple->m_4x1[0]);
	matrix->m_4x1[1] = -(tuple->m_4x1[1]);
	matrix->m_4x1[2] = -(tuple->m_4x1[2]);
	matrix->m_4x1[3] = tuple->m_4x1[3];
}

void	scalar_multiplication(t_matrix *matrix, const t_matrix *tuple,
	const double scalar)
{
	if (!matrix)
		return ;
	init_matrix(matrix, 4, 1);
	matrix->m_4x1[0] = tuple->m_4x1[0] * scalar;
	matrix->m_4x1[1] = tuple->m_4x1[1] * scalar;
	matrix->m_4x1[2] = tuple->m_4x1[2] * scalar;
	matrix->m_4x1[3] = tuple->m_4x1[3];
}

void	scalar_division(t_matrix *matrix, const t_matrix *tuple,
	const double scalar)
{
	if (!matrix)
		return ;
	init_matrix(matrix, 4, 1);
	if (scalar < EPSILON)
		return ;
	matrix->m_4x1[0] = tuple->m_4x1[0] / scalar;
	matrix->m_4x1[1] = tuple->m_4x1[1] / scalar;
	matrix->m_4x1[2] = tuple->m_4x1[2] / scalar;
	matrix->m_4x1[3] = tuple->m_4x1[3];
}
