/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:17:42 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/13 14:29:53 by anogueir         ###   ########.fr       */
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

t_matrix	*matrix_multiplication(t_matrix *a, t_matrix *b)
{
	t_matrix	*product;
	int			row;
	int			col;
	int			k;
	double		sum;

	if (a->cols != b->rows)
		return (NULL);
	row = -1;
	col = -1;
	product = createnew_matrix(a->rows, b->cols);
	while (++row < a->rows)
	{
		col = -1;
		while (++col < a->cols)
		{
			sum = 0;
			k = -1;
			while (++k < b->cols)
				sum += mat_get(a, row, k) * mat_get(b, k, col);
			mat_set(product, row, col, sum);
		}
	}
	return (product);
}

t_matrix	*matrix_tuple_multiplication(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			row;
	int			k;
	double		*ptr_a;
	double		*ptr_b;

	if (b->cols != 1)
		return (NULL);
	if (a->cols != b->rows)
		return (NULL);
	result = createnew_matrix(a->rows, b->cols);
	ptr_a = get_matrix(a);
	ptr_b = get_matrix(b);
	row = -1;
	while (++row < a->rows)
	{
		k = -1;
		while (++k < a->cols)
			result->m_4x1[row] += ptr_a[row * a->rows + k] * ptr_b[k];
	}
	return (result);
}

t_matrix	*matrix_transposition(t_matrix *m)
{
	t_matrix	*transposed;
	double		*ptr;
	double		*ptr_tr;
	int			row;
	int			col;

	transposed = createnew_matrix(m->rows, m->cols);
	ptr = get_matrix(m);
	ptr_tr = get_matrix(transposed);
	row = -1;
	while (++row < m->rows)
	{
		col = -1;
		while (++col < m->rows)
			ptr_tr[col * m->rows + row] = ptr[row * m->rows + col];
	}
	return (transposed);
}
