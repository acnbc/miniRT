/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:41:22 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/21 15:04:50 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	translation(t_matrix *matrix, const t_matrix *offset)
{
	if (!matrix || !offset)
	{
		init_identity_matrix(matrix, 4);
		return ;
	}
	init_identity_matrix(matrix, 4);
	mat_set(matrix, 0, 3, offset->m_4x1[0]);
	mat_set(matrix, 1, 3, offset->m_4x1[1]);
	mat_set(matrix, 2, 3, offset->m_4x1[2]);
}

void	scaling(t_matrix *matrix, const t_matrix *offset)
{
	if (!matrix || !offset)
	{
		init_identity_matrix(matrix, 4);
		return ;
	}
	init_identity_matrix(matrix, 4);
	mat_set(matrix, 0, 0, offset->m_4x1[0]);
	mat_set(matrix, 1, 1, offset->m_4x1[1]);
	mat_set(matrix, 2, 2, offset->m_4x1[2]);
}

void	x_axis_rotation(t_matrix *matrix, double rotation_value)
{
	if (!matrix)
		return ;
	init_identity_matrix(matrix, 4);
	mat_set(matrix, 1, 1, cos(rotation_value));
	mat_set(matrix, 1, 2, -sin(rotation_value));
	mat_set(matrix, 2, 1, sin(rotation_value));
	mat_set(matrix, 2, 2, cos(rotation_value));
}

void	y_axis_rotation(t_matrix *matrix, double rotation_value)
{
	if (!matrix)
		return ;
	init_identity_matrix(matrix, 4);
	mat_set(matrix, 0, 0, cos(rotation_value));
	mat_set(matrix, 0, 2, sin(rotation_value));
	mat_set(matrix, 2, 0, -sin(rotation_value));
	mat_set(matrix, 2, 2, cos(rotation_value));
}

void	z_axis_rotation(t_matrix *matrix, double rotation_value)
{
	if (!matrix)
		return ;
	init_identity_matrix(matrix, 4);
	mat_set(matrix, 0, 0, cos(rotation_value));
	mat_set(matrix, 0, 1, -sin(rotation_value));
	mat_set(matrix, 1, 0, sin(rotation_value));
	mat_set(matrix, 1, 1, cos(rotation_value));
}
