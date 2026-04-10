/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:17:42 by anogueir          #+#    #+#             */
/*   Updated: 2026/04/08 08:59:20 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	matrix_multiplication(t_matrix *matrix, const t_matrix *a,
	const t_matrix *b)
{
	int			row;
	int			col;
	int			k;
	double		sum;

	if (!matrix || a->cols != b->rows)
		return ;
	init_matrix(matrix, a->rows, b->cols);
	row = -1;
	while (++row < a->rows)
	{
		col = -1;
		while (++col < b->cols)
		{
			sum = 0;
			k = -1;
			while (++k < a->cols)
				sum += mat_get(a, row, k) * mat_get(b, k, col);
			mat_set(matrix, row, col, sum);
		}
	}
}

void	matrix_tuple_multiplication(t_matrix *res, const t_matrix *m,
	const t_matrix *t)
{
	int		r;
	double	sum;

	res->rows = 4;
	res->cols = 1;
	r = -1;
	while (++r < 4)
	{
		sum = m->m_4x4[r * 4 + 0] * t->m_4x1[0]
			+ m->m_4x4[r * 4 + 1] * t->m_4x1[1]
			+ m->m_4x4[r * 4 + 2] * t->m_4x1[2]
			+ m->m_4x4[r * 4 + 3] * t->m_4x1[3];
		res->m_4x1[r] = sum;
	}
}

void	matrix_transposition(t_matrix *matrix, const t_matrix *m)
{
	double		*ptr;
	double		*ptr_tr;
	int			row;
	int			col;

	if (!matrix)
		return ;
	init_matrix(matrix, m->cols, m->rows);
	ptr = get_matrix(m);
	ptr_tr = get_matrix(matrix);
	row = -1;
	while (++row < m->rows)
	{
		col = -1;
		while (++col < m->cols)
			ptr_tr[col * m->rows + row] = ptr[row * m->cols + col];
	}
}
