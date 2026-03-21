/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:46:42 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/21 15:53:32 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_matrix(t_matrix *matrix, int rows, int cols)
{
	int	i;

	if (!matrix)
		return ;
	matrix->rows = rows;
	matrix->cols = cols;
	i = -1;
	while (++i < rows * cols)
		matrix->m_4x4[i] = 0.0;
}

void	init_identity_matrix(t_matrix *matrix, int dim)
{
	int	row;
	int	col;

	if (!matrix || dim < 2)
		return ;
	init_matrix(matrix, dim, dim);
	row = -1;
	while (++row < dim)
	{
		col = -1;
		while (++col < dim)
		{
			if (row == col)
				mat_set(matrix, row, col, 1.0);
			else
				mat_set(matrix, row, col, 0.0);
		}
	}
}

double	*get_matrix(const t_matrix *m)
{
	double	*ptr;

	if (m->rows == 4 && m->cols == 4)
		ptr = (double *)&m->m_4x4;
	else if (m->rows == 4 && m->cols == 1)
		ptr = (double *)&m->m_4x1;
	else if (m->rows == 3)
		ptr = (double *)&m->m_3x3;
	else if (m->rows == 2)
		ptr = (double *)&m->m_2x2;
	else
	{
		if (m->rows * m->cols <= 16)
			return ((double *)m->m_4x4);
		else
			return (NULL);
	}
	return (ptr);
}

double	mat_get(const t_matrix *m, int row, int col)
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
