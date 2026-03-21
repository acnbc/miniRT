/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inversion_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:48:59 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static double	matrix_determinant_with_scratch(t_matrix *m, t_matrix *s1, t_matrix *s2);

double	get_2x2_determinant(t_matrix *a)
{
	double	ac;
	double	bd;

	ac = mat_get(a, 0, 0) * mat_get(a, 1, 1);
	bd = mat_get(a, 0, 1) * mat_get(a, 1, 0);
	return (ac - bd);
}

double	get_minor(t_matrix *m, int row, int col, t_matrix *s1, t_matrix *s2)
{
	double	minor;

	get_submatrix(m, row, col, s1);
	if (s1->rows == 2 && s1->cols == 2)
		minor = get_2x2_determinant(s1);
	else
		minor = matrix_determinant_with_scratch(s1, s2, s1);
	return (minor);
}

double	get_cofactor(t_matrix *m, int row, int col, t_matrix *s1, t_matrix *s2)
{
	double	cofactor;
	double	minor;

	minor = get_minor(m, row, col, s1, s2);
	if ((row + col) % 2 == 0)
		cofactor = minor;
	else
		cofactor = -minor;
	return (cofactor);
}

double	matrix_determinant_with_scratch(t_matrix *m, t_matrix *s1, t_matrix *s2)
{
	double	det;
	int		i;

	if (m->rows == 2 && m->cols == 2)
		return (get_2x2_determinant(m));
	det = 0.0;
	i = -1;
	while (++i < m->cols)
		det += mat_get(m, 0, i) * get_cofactor(m, 0, i, s1, s2);
	return (det);
}

double	matrix_determinant(t_matrix *m)
{
	t_matrix	scratch1;
	t_matrix	scratch2;

	return (matrix_determinant_with_scratch(m, &scratch1, &scratch2));
}

void	inverse_matrix(t_matrix *m, t_matrix *out)
{
	int		row;
	int		col;
	double	det;
	double	c;
	t_matrix	s1;
	t_matrix	s2;

	if (!out || !is_invertible(m))
		return ;
	init_matrix(out, m->rows, m->cols);
	det = matrix_determinant(m);
	row = -1;
	while (++row < m->rows)
	{
		col = -1;
		while (++col < m->cols)
		{
			c = get_cofactor(m, col, row, &s1, &s2);
			mat_set(out, row, col, c / det);
		}
	}
}
