/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 21:59:30 by jessica           #+#    #+#             */
/*   Updated: 2026/03/30 03:31:05 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	tuple_addition(t_tuple *result, const t_tuple *a, const t_tuple *b)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
	result->is_point = 1;
}

void	tuple_multiplication(t_tuple *result, const t_tuple *a,
			const t_tuple *b)
{
	result->x = a->x * b->x;
	result->y = a->y * b->y;
	result->z = a->z * b->z;
	result->is_point = 1;
}

void	tuple_scalar_multiplication(t_tuple *result, const t_tuple *color,
				double scalar)
{
	result->x = color->x * scalar;
	result->y = color->y * scalar;
	result->z = color->z * scalar;
	result->is_point = 1;
}
