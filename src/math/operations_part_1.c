/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:56:47 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	add_tuples(t_matrix *a, t_matrix *b, t_matrix *out)
{
	if (!out)
		return ;
	init_matrix(out, 4, 1);
	out->m_4x1[0] = a->m_4x1[0] + b->m_4x1[0];
	out->m_4x1[1] = a->m_4x1[1] + b->m_4x1[1];
	out->m_4x1[2] = a->m_4x1[2] + b->m_4x1[2];
	out->m_4x1[3] = a->m_4x1[3] + b->m_4x1[3];
}

void	subtract_tuple(t_matrix *a, t_matrix *b, t_matrix *out)
{
	if (!out)
		return ;
	init_matrix(out, 4, 1);
	out->m_4x1[0] = a->m_4x1[0] - b->m_4x1[0];
	out->m_4x1[1] = a->m_4x1[1] - b->m_4x1[1];
	out->m_4x1[2] = a->m_4x1[2] - b->m_4x1[2];
	out->m_4x1[3] = a->m_4x1[3] - b->m_4x1[3];
}

void	negate_tuple(t_matrix *tuple, t_matrix *out)
{
	if (!out)
		return ;
	init_matrix(out, 4, 1);
	out->m_4x1[0] = -(tuple->m_4x1[0]);
	out->m_4x1[1] = -(tuple->m_4x1[1]);
	out->m_4x1[2] = -(tuple->m_4x1[2]);
	out->m_4x1[3] = tuple->m_4x1[3];
}

void	scalar_multiplication(t_matrix *tuple, double scalar, t_matrix *out)
{
	if (!out)
		return ;
	init_matrix(out, 4, 1);
	out->m_4x1[0] = tuple->m_4x1[0] * scalar;
	out->m_4x1[1] = tuple->m_4x1[1] * scalar;
	out->m_4x1[2] = tuple->m_4x1[2] * scalar;
	out->m_4x1[3] = tuple->m_4x1[3];
}

void	scalar_division(t_matrix *tuple, double scalar, t_matrix *out)
{
	if (!out)
		return ;
	init_matrix(out, 4, 1);
	out->m_4x1[0] = tuple->m_4x1[0] / scalar;
	out->m_4x1[1] = tuple->m_4x1[1] / scalar;
	out->m_4x1[2] = tuple->m_4x1[2] / scalar;
	out->m_4x1[3] = tuple->m_4x1[3];
}
