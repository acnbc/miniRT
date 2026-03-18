/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:56:07 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/13 18:56:10 by anogueir         ###   ########.fr       */
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

t_matrix	*vector_normalization(t_matrix *vector)
{
	t_matrix	*normalized;
	double		magnitude;

	magnitude = vector_magnitude(vector);
	if (magnitude == 0.0)
		return (NULL);
	normalized = creat_new_matrix(4, 1);
	if (!normalized)
		return (NULL);
	normalized->m_4x1[0] = vector->m_4x1[0] / magnitude;
	normalized->m_4x1[1] = vector->m_4x1[1] / magnitude;
	normalized->m_4x1[2] = vector->m_4x1[2] / magnitude;
	normalized->m_4x1[3] = vector->m_4x1[3];
	return (normalized);
}

double	dot_product(t_matrix *a, t_matrix *b)
{
	return ((a->m_4x1[0] * b->m_4x1[0]) + (a->m_4x1[1] * b->m_4x1[1])
		+ (a->m_4x1[2] * b->m_4x1[2]));
}

t_matrix	*cross_product(t_matrix *a, t_matrix *b)
{
	t_matrix	*vector;

	vector = creat_new_matrix(4, 1);
	if (!vector)
		return (NULL);
	vector->m_4x1[0] = (a->m_4x1[1] * b->m_4x1[2])
		- (a->m_4x1[2] * b->m_4x1[1]);
	vector->m_4x1[1] = (a->m_4x1[2] * b->m_4x1[0])
		- (a->m_4x1[0] * b->m_4x1[2]);
	vector->m_4x1[2] = (a->m_4x1[0] * b->m_4x1[1])
		- (a->m_4x1[1] * b->m_4x1[0]);
	vector->m_4x1[3] = 0.0;
	return (vector);
}
