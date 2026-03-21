/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:29:32 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/21 14:59:14 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	combine_transformations(t_matrix *matrix, t_matrix *transposed,
		t_matrix *rotated, t_matrix *scaled)
{
	t_matrix	temp;

	if (!matrix)
		return ;
	matrix_multiplication(&temp, rotated, scaled);
	matrix_multiplication(matrix, transposed, &temp);
}
