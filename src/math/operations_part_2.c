/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:56:07 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/13 18:56:10 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	vector_magnitude(t_tuple tuple)
{
	double	magnitude;
	double	temp;

	temp = pow(tuple.x, 2) + pow(tuple.y, 2) + pow(tuple.z, 2);
	magnitude = sqrt(temp);
	return (magnitude);
}

t_tuple	vector_normalization(t_tuple vector)
{
	t_tuple	normalized;
	double	magnitude;

	magnitude = vector_magnitude(vector);
	normalized.x = vector.x / magnitude;
	normalized.y = vector.y / magnitude;
	normalized.z = vector.z / magnitude;
	normalized.is_point = vector.is_point;
	return (normalized);
}

double	dot_product(t_tuple a, t_tuple b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.is_point
			* b.is_point));
}

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	t_tuple	vector;

	vector.x = (a.y * b.z) - (a.z * b.y);
	vector.y = (a.z * b.x) - (a.x * b.z);
	vector.z = (a.x * b.y) - (a.y * b.x);
	vector.is_point = false;
	return (vector);
}
