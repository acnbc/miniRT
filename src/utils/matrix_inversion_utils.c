/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inversion_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:51:00 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	is_invertible(t_matrix *m)
{
	if (fabs(matrix_determinant(m)) < EPSILON)
		return (false);
	return (true);
}

void	get_submatrix(t_matrix *m, int row, int col, t_matrix *out)
{
	int	i;
	int	j;
	int	k;
	int	l;

	if (!out)
		return ;
	init_matrix(out, m->rows - 1, m->cols - 1);
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
			mat_set(out, k, l++, mat_get(m, i, j));
		}
		k++;
	}
}
