/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inversion_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:48:59 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/21 15:01:07 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	get_minor(const t_matrix *m, int row, int col);
double	get_cofactor(const t_matrix *m, int row, int col);

double	get_2x2_determinant(const t_matrix *a)
{
	double	ac;
	double	bd;

	ac = mat_get(a, 0, 0) * mat_get(a, 1, 1);
	bd = mat_get(a, 0, 1) * mat_get(a, 1, 0);
	return (ac - bd);
}

double	get_minor(const t_matrix *m, int row, int col)
{
	t_matrix	sub;

	get_submatrix(&sub, m, row, col);
	return (matrix_determinant(&sub));
}

double	get_cofactor(const t_matrix *m, int row, int col)
{
	double	minor;

	minor = get_minor(m, row, col);
	if ((row + col) % 2 == 0)
		return (minor);
	else
		return (-minor);
}

double	matrix_determinant(const t_matrix *m)
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

void	inverse_matrix(t_matrix *matrix, const t_matrix *m)
{
	int		row;
	int		col;
	double	det;
	double	c;

	if (!matrix || !is_invertible(m))
		return ;
	init_matrix(matrix, m->rows, m->cols);
	det = matrix_determinant(m);
	row = -1;
	while (++row < m->rows)
	{
		col = -1;
		while (++col < m->cols)
		{
			c = get_cofactor(m, col, row);
			mat_set(matrix, row, col, c / det);
		}
	}
}
