/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inversion_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:51:00 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/21 15:07:44 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	is_invertible(const t_matrix *m)
{
	if (fabs(matrix_determinant(m)) < EPSILON)
		return (false);
	return (true);
}

void	get_submatrix(t_matrix *matrix, const t_matrix *m, int row, int col)
{
	int	i;
	int	j;
	int	k;
	int	l;

	if (!matrix)
		return ;
	init_matrix(matrix, m->rows - 1, m->cols - 1);
	i = -1;
	k = 0;
	while (++i < m->rows)
	{
		if (i == row)
			continue ;
		j = -1;
		l = 0;
		while (++j < m->cols)
		{
			if (j == col)
				continue ;
			mat_set(matrix, k, l++, mat_get(m, i, j));
		}
		k++;
	}
}
