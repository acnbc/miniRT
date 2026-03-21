/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:03:49 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_point(t_matrix *out, double x, double y, double z)
{
	if (!out)
		return ;
	init_matrix(out, 4, 1);
	out->m_4x1[0] = x;
	out->m_4x1[1] = y;
	out->m_4x1[2] = z;
	out->m_4x1[3] = 1.0;
}

void	init_vector(t_matrix *out, double x, double y, double z)
{
	if (!out)
		return ;
	init_matrix(out, 4, 1);
	out->m_4x1[0] = x;
	out->m_4x1[1] = y;
	out->m_4x1[2] = z;
	out->m_4x1[3] = 0.0;
}

bool	is_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}
