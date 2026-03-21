/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:46:42 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_matrix(t_matrix *out, int rows, int cols)
{
	int	i;

	if (!out)
		return ;
	out->rows = rows;
	out->cols = cols;
	i = -1;
	while (++i < rows * cols)
		out->m_4x4[i] = 0.0;
}

void	init_identity_matrix(t_matrix *out, int dim)
{
	int	row;
	int	col;

	if (!out || dim < 2)
		return ;
	init_matrix(out, dim, dim);
	row = -1;
	while (++row < dim)
	{
		col = -1;
		while (++col < dim)
		{
			if (row == col)
				mat_set(out, row, col, 1.0);
			else
				mat_set(out, row, col, 0.0);
		}
	}
}

double	*get_matrix(t_matrix *m)
{
	double	*ptr;

	if (m->rows == 4 && m->cols == 4)
		ptr = m->m_4x4;
	else if (m->rows == 4 && m->cols == 1)
		ptr = m->m_4x1;
	else if (m->rows == 3)
		ptr = m->m_3x3;
	else if (m->rows == 2)
		ptr = m->m_2x2;
	else
	{
		if (m->rows * m->cols <= 16)
			return (m->m_4x4);
		else
			return (NULL);
	}
	return (ptr);
}

double	mat_get(t_matrix *m, int row, int col)
{
	double	*ptr;

	ptr = get_matrix(m);
	return (ptr[row * m->cols + col]);
}

void	mat_set(t_matrix *m, int row, int col, double value)
{
	double	*ptr;

	ptr = get_matrix(m);
	ptr[row * m->cols + col] = value;
}

