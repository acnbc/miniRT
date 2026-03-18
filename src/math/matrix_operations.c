/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:17:42 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	matrix_comparison(t_matrix *a, t_matrix *b)
{
	int		i;
	int		dimension;
	double	*ptr_a;
	double	*ptr_b;

	i = -1;
	if ((a->rows != b->rows) || (a->cols != b->cols))
		return (false);
	dimension = a->rows * a->cols;
	ptr_a = get_matrix(a);
	ptr_b = get_matrix(b);
	while (++i < dimension)
	{
		if (!is_equal(ptr_a[i], ptr_b[i]))
			return (false);
	}
	return (true);
}

void	matrix_multiplication(t_matrix *a, t_matrix *b, t_matrix *out)
{
	int		row;
	int		col;
	int		k;
	double	sum;

	if (!out || a->cols != b->rows)
		return ;
	init_matrix(out, a->rows, b->cols);
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
			mat_set(out, row, col, sum);
		}
	}
}

void	matrix_tuple_multiplication(t_matrix *a, t_matrix *b, t_matrix *out)
{
	int		row;
	int		k;
	double	*ptr_a;
	double	*ptr_b;

	if (!out || b->cols != 1 || a->cols != b->rows)
		return ;
	init_matrix(out, a->rows, b->cols);
	ptr_a = get_matrix(a);
	ptr_b = get_matrix(b);
	row = -1;
	while (++row < a->rows)
	{
		k = -1;
		while (++k < a->cols)
			out->m_4x1[row] += ptr_a[row * a->cols + k] * ptr_b[k];
	}
}

void	matrix_transposition(t_matrix *m, t_matrix *out)
{
	double	*ptr;
	double	*ptr_tr;
	int		row;
	int		col;

	if (!out)
		return ;
	init_matrix(out, m->cols, m->rows);
	ptr = get_matrix(m);
	ptr_tr = get_matrix(out);
	row = -1;
	while (++row < m->rows)
	{
		col = -1;
		while (++col < m->cols)
			ptr_tr[col * m->rows + row] = ptr[row * m->cols + col];
	}
}
