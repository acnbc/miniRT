/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:46:42 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/16 23:18:18 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrix	*create_identity_matrix(int dim)
{
	t_matrix	*identity;
	int			row;
	int			col;

	if (dim < 2)
		return (NULL);
	identity = creat_new_matrix(dim, dim);
	row = -1;
	while (++row < dim)
	{
		col = -1;
		while (++col < dim)
		{
			if (row == col)
				mat_set(identity, row, col, 1.0);
			else
				mat_set(identity, row, col, 0.0);
		}
	}
	return (identity);
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

t_matrix	*creat_new_matrix(int rows, int cols)
{
	t_matrix	*new;
	int			i;

	new = (t_matrix *)safe_malloc(sizeof(t_matrix));
	new->rows = rows;
	new->cols = cols;
	i = -1;
	while (++i < rows * cols)
		new->m_4x4[i] = 0.0;
	return (new);
}
