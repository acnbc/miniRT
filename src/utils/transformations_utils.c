/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:29:32 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	combine_transformations(t_matrix *transposed,
		t_matrix *rotated, t_matrix *scaled, t_matrix *out)
{
	t_matrix	temp;

	if (!out)
		return ;
	matrix_multiplication(rotated, scaled, &temp);
	matrix_multiplication(transposed, &temp, out);
}
