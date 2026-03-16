/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:29:32 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/16 16:31:53 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrix	*combine_transformations(t_matrix *transposed,
		t_matrix *rotated, t_matrix *scaled)
{
	t_matrix	*temp;
	t_matrix	*final_transform;

	temp = matrix_multiplication(rot, scale);
	final_transform = matrix_multiplication(trans, temp);

	free(temp); 
	
	return (final_transform);
}
