/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inversion_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:48:59 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/13 18:49:02 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	get_2x2_determinant(t_matrix *a)
{
	double	ac;
	double	bd;

	ac = mat_get(a, 0, 0) * mat_get(a, 1, 1);
	bd = mat_get(a, 0, 1) * mat_get(a, 1, 0);
	return (ac - bd);
}

double	get_minor(t_matrix *m, int row, int col)
{
	t_matrix	*sub;
	double		minor;

	sub = get_submatrix(m, row, col);
	if (sub->rows == 2 && sub->cols == 2)
		minor = get_2x2_determinant(sub);
	else
		minor = matrix_determinant(sub);
	return (minor);
}

double	get_cofactor(t_matrix *m, int row, int col)
{
	double	cofactor;
	double	minor;

	minor = get_minor(m, row, col);
	if ((row + col) % 2 == 0)
		cofactor = minor;
	else
		cofactor = -minor;
	return (cofactor);
}

double	matrix_determinant(t_matrix *m)
{
	double	det;
	int		i;

	if (m->rows == 2 && m->cols == 2)
		return (get_2x2_determinant(m));
	det = 0.0;
	i = -1;
	while (++i < m->cols)
		det += mat_get(m, 0, i) * get_cofactor(m, 0, i);
	return (det);
}

t_matrix	*inverse_matrix(t_matrix *m)
{
	t_matrix	*inverted;
	int			row;
	int			col;
	double		det;
	double		c;

	if (!is_invertible(m))
		return (NULL);
	inverted = creat_new_matrix(m->rows, m->cols);
	det = matrix_determinant(m);
	row = -1;
	while (++row < m->rows)
	{
		col = -1;
		while (++col < m->cols)
		{
			c = get_cofactor(m, col, row);
			mat_set(inverted, row, col, c / det);
		}
	}
	return (inverted);
}
