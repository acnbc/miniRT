/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:03:49 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/21 15:06:50 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_point(t_matrix *matrix, double x, double y, double z)
{
	if (!matrix)
		return ;
	init_matrix(matrix, 4, 1);
	matrix->m_4x1[0] = x;
	matrix->m_4x1[1] = y;
	matrix->m_4x1[2] = z;
	matrix->m_4x1[3] = 1.0;
}

void	init_vector(t_matrix *matrix, double x, double y, double z)
{
	if (!matrix)
		return ;
	init_matrix(matrix, 4, 1);
	matrix->m_4x1[0] = x;
	matrix->m_4x1[1] = y;
	matrix->m_4x1[2] = z;
	matrix->m_4x1[3] = 0.0;
}

bool	is_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}
