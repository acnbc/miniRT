/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:56:47 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/16 14:05:13 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static t_matrix	*alloc_4x1(void)
{
	return (create_new_matrix(4, 1));
}

t_matrix	*add_tuples(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;

	result = alloc_4x1();
	if (!result)
		return (NULL);
	result->m_4x1[0] = a->m_4x1[0] + b->m_4x1[0];
	result->m_4x1[1] = a->m_4x1[1] + b->m_4x1[1];
	result->m_4x1[2] = a->m_4x1[2] + b->m_4x1[2];
	result->m_4x1[3] = a->m_4x1[3] + b->m_4x1[3];
	return (result);
}

t_matrix	*subtract_tuple(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;

	result = alloc_4x1();
	if (!result)
		return (NULL);
	result->m_4x1[0] = a->m_4x1[0] - b->m_4x1[0];
	result->m_4x1[1] = a->m_4x1[1] - b->m_4x1[1];
	result->m_4x1[2] = a->m_4x1[2] - b->m_4x1[2];
	result->m_4x1[3] = a->m_4x1[3] - b->m_4x1[3];
	return (result);
}

t_matrix	*negate_tuple(t_matrix *tuple)
{
	t_matrix	*result;

	result = alloc_4x1();
	if (!result)
		return (NULL);
	result->m_4x1[0] = -(tuple->m_4x1[0]);
	result->m_4x1[1] = -(tuple->m_4x1[1]);
	result->m_4x1[2] = -(tuple->m_4x1[2]);
	result->m_4x1[3] = tuple->m_4x1[3];
	return (result);
}

t_matrix	*scalar_multiplication(t_matrix *tuple, double scalar)
{
	t_matrix	*result;

	result = alloc_4x1();
	if (!result)
		return (NULL);
	result->m_4x1[0] = tuple->m_4x1[0] * scalar;
	result->m_4x1[1] = tuple->m_4x1[1] * scalar;
	result->m_4x1[2] = tuple->m_4x1[2] * scalar;
	result->m_4x1[3] = tuple->m_4x1[3];
	return (result);
}

t_matrix	*scalar_division(t_matrix *tuple, double scalar)
{
	t_matrix	*result;

	result = alloc_4x1();
	if (!result)
		return (NULL);
	result->m_4x1[0] = tuple->m_4x1[0] / scalar;
	result->m_4x1[1] = tuple->m_4x1[1] / scalar;
	result->m_4x1[2] = tuple->m_4x1[2] / scalar;
	result->m_4x1[3] = tuple->m_4x1[3];
	return (result);
}
