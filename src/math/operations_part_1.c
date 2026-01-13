/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:56:47 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/13 18:56:52 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.is_point = a.is_point + b.is_point;
	return (result);
}

t_tuple	subtract_tuple(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.is_point = a.is_point & b.is_point;
	return (result);
}

t_tuple	negate_tuple(t_tuple tuple)
{
	t_tuple	result;

	result.x = -(tuple.x);
	result.y = -(tuple.y);
	result.z = -(tuple.z);
	result.is_point = tuple.is_point;
	return (result);
}

t_tuple	scalar_multiplication(t_tuple tuple, double scalar)
{
	t_tuple	result;

	result.x = tuple.x * scalar;
	result.y = tuple.y * scalar;
	result.z = tuple.z * scalar;
	result.is_point = tuple.is_point;
	return (result);
}

t_tuple	scalar_division(t_tuple tuple, double scalar)
{
	t_tuple	result;

	result.x = tuple.x / scalar;
	result.y = tuple.y / scalar;
	result.z = tuple.z / scalar;
	result.is_point = tuple.is_point;
	return (result);
}
