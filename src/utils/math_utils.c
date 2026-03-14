/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:03:49 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/13 15:04:47 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrix	*create_point(double x, double y, double z)
{
	t_matrix	*point;

	point = creat_new_matrix(4, 1);
	point->m_4x1[0] = x;
	point->m_4x1[1] = y;
	point->m_4x1[2] = z;
	point->m_4x1[3] = 1.0;
	return (point);
}

t_matrix	*create_vector(double x, double y, double z)
{
	t_matrix	*vector;

	vector = creat_new_matrix(4, 1);
	vector->m_4x1[0] = x;
	vector->m_4x1[1] = y;
	vector->m_4x1[2] = z;
	vector->m_4x1[3] = 0.0;
	return (vector);
}

bool	is_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}
