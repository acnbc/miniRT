/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:56:07 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	vector_magnitude(t_matrix *tuple)
{
	double	magnitude;
	double	temp;

	temp = pow(tuple->m_4x1[0], 2) + pow(tuple->m_4x1[1], 2)
		+ pow(tuple->m_4x1[2], 2);
	magnitude = sqrt(temp);
	return (magnitude);
}

void	vector_normalization(t_matrix *vector, t_matrix *out)
{
	double	magnitude;

	if (!out || vector_magnitude(vector) == 0.0)
		return ;
	magnitude = vector_magnitude(vector);
	init_matrix(out, 4, 1);
	out->m_4x1[0] = vector->m_4x1[0] / magnitude;
	out->m_4x1[1] = vector->m_4x1[1] / magnitude;
	out->m_4x1[2] = vector->m_4x1[2] / magnitude;
	out->m_4x1[3] = vector->m_4x1[3];
}

double	dot_product(t_matrix *a, t_matrix *b)
{
	return ((a->m_4x1[0] * b->m_4x1[0]) + (a->m_4x1[1] * b->m_4x1[1])
		+ (a->m_4x1[2] * b->m_4x1[2]));
}

void	cross_product(t_matrix *a, t_matrix *b, t_matrix *out)
{
	if (!out)
		return ;
	init_matrix(out, 4, 1);
	out->m_4x1[0] = (a->m_4x1[1] * b->m_4x1[2])
		- (a->m_4x1[2] * b->m_4x1[1]);
	out->m_4x1[1] = (a->m_4x1[2] * b->m_4x1[0])
		- (a->m_4x1[0] * b->m_4x1[2]);
	out->m_4x1[2] = (a->m_4x1[0] * b->m_4x1[1])
		- (a->m_4x1[1] * b->m_4x1[0]);
	out->m_4x1[3] = 0.0;
}
