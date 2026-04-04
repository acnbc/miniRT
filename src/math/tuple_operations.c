/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 21:59:30 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 00:47:05 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	tuple_addition(t_tuple *result, const t_tuple *a, const t_tuple *b)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
	result->is_point = a->is_point + b->is_point;
}

void	tuple_multiplication(t_tuple *result, const t_tuple *a,
			const t_tuple *b)
{
	result->x = a->x * b->x;
	result->y = a->y * b->y;
	result->z = a->z * b->z;
	result->is_point = a->is_point && b->is_point;
}

void	tuple_scalar_multiplication(t_tuple *result, const t_tuple *a,
				double scalar)
{
	result->x = a->x * scalar;
	result->y = a->y * scalar;
	result->z = a->z * scalar;
	result->is_point = a->is_point;
}
