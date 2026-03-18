/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inversion_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:51:00 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/13 14:29:53 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	is_invertible(t_matrix *m)
{
	if (fabs(matrix_determinant(m)) < EPSILON)
		return (false);
	return (true);
}

t_matrix	*get_submatrix(t_matrix *m, int row, int col)
{
	int			i;
	int			j;
	int			k;
	int			l;
	t_matrix	*sub;

	i = -1;
	k = 0;
	sub = creat_new_matrix(m->rows - 1, m->cols - 1);
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
			mat_set(sub, k, l++, mat_get(m, i, j));
		}
		k++;
	}
	return (sub);
}
