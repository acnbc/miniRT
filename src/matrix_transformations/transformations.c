/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:41:22 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/16 14:09:16 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrix	*translation(t_matrix *offset)
{
	t_matrix	*m;

	m = create_identity_matrix(4);
	if (!m || !offset)
		return (m);
	mat_set(m, 0, 3, offset->m_4x1[0]);
	mat_set(m, 1, 3, offset->m_4x1[1]);
	mat_set(m, 2, 3, offset->m_4x1[2]);
	mat_set(m, 3, 3, offset->m_4x1[3]);
	return (m);
}

t_matrix	*scaling(t_matrix *offset)
{
	t_matrix	*m;

	m = create_identity_matrix(4);
	if (!m || !offset)
		return (m);
	mat_set(m, 0, 0, offset->m_4x1[0]);
	mat_set(m, 1, 1, offset->m_4x1[1]);
	mat_set(m, 2, 2, offset->m_4x1[2]);
	return (m);
}

t_matrix	*x_axis_rotation(double rotation_value)
{
	t_matrix	*transform;

	transform = create_identity_matrix(4);
	mat_set(transform, 1, 1, cos(rotation_value));
	mat_set(transform, 1, 2, -sin(rotation_value));
	mat_set(transform, 2, 1, sin(rotation_value));
	mat_set(transform, 2, 2, cos(rotation_value));

	return (transform);
}