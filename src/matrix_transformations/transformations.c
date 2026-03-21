/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:41:22 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	translation(t_matrix *offset, t_matrix *out)
{
	if (!out || !offset)
		return ;
	init_identity_matrix(out, 4);
	mat_set(out, 0, 3, offset->m_4x1[0]);
	mat_set(out, 1, 3, offset->m_4x1[1]);
	mat_set(out, 2, 3, offset->m_4x1[2]);
	mat_set(out, 3, 3, offset->m_4x1[3]);
}

void	scaling(t_matrix *offset, t_matrix *out)
{
	if (!out || !offset)
		return ;
	init_identity_matrix(out, 4);
	mat_set(out, 0, 0, offset->m_4x1[0]);
	mat_set(out, 1, 1, offset->m_4x1[1]);
	mat_set(out, 2, 2, offset->m_4x1[2]);
}

void	x_axis_rotation(double rotation_value, t_matrix *out)
{
	if (!out)
		return ;
	init_identity_matrix(out, 4);
	mat_set(out, 1, 1, cos(rotation_value));
	mat_set(out, 1, 2, -sin(rotation_value));
	mat_set(out, 2, 1, sin(rotation_value));
	mat_set(out, 2, 2, cos(rotation_value));
}

void	y_axis_rotation(double rotation_value, t_matrix *out)
{
	if (!out)
		return ;
	init_identity_matrix(out, 4);
	mat_set(out, 0, 0, cos(rotation_value));
	mat_set(out, 0, 2, sin(rotation_value));
	mat_set(out, 2, 0, -sin(rotation_value));
	mat_set(out, 2, 2, cos(rotation_value));
}

void	z_axis_rotation(double rotation_value, t_matrix *out)
{
	if (!out)
		return ;
	init_identity_matrix(out, 4);
	mat_set(out, 0, 0, cos(rotation_value));
	mat_set(out, 0, 1, -sin(rotation_value));
	mat_set(out, 1, 0, sin(rotation_value));
	mat_set(out, 1, 1, cos(rotation_value));
}
