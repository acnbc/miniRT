/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 21:59:30 by jessica           #+#    #+#             */
/*   Updated: 2026/04/08 17:49:56 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	rgb_addition(t_tuple *result, const t_tuple *a, const t_tuple *b)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
}

void	rgb_multiplication(t_tuple *result, const t_tuple *a,
			const t_tuple *b)
{
	result->x = a->x * b->x;
	result->y = a->y * b->y;
	result->z = a->z * b->z;
}

void	rgb_scalar_multiplication(t_tuple *result, const t_tuple *a,
				double scalar)
{
	result->x = a->x * scalar;
	result->y = a->y * scalar;
	result->z = a->z * scalar;
}
