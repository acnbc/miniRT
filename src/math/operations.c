/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:10:31 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/02 13:31:27 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple add_tuples(t_tuple a, t_tuple b)
{
    t_tuple result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.is_point = a.is_point & b.is_point;
    return (result);
}

t_tuple subtract_tuple(t_tuple a, t_tuple b)
{
    t_tuple result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.is_point = a.is_point & b.is_point;
    return (result);
}

t_tuple negate_tuple(t_tuple tuple)
{
    t_tuple result;

    result.x = -(tuple.x);
    result.y = -(tuple.y);
    result.z = -(t_tuple.z);
    result.is_point = tuple.is_point;
    return (result);
}

t_tuple scalar_multiplication(t_tuple tuple, double scalar)
{
    t_tuple result;

    result.x = tuple.x * scalar;
    result.y = tuple.y * scalar;
    result.z = tuple.z * scalar;
    result.is_point = tuple.is_point;
    return (result);
}

t_tuple scalar_division(t_tuple tuple, double scalar)
{
    t_tuple result;

    result.x = tuple.x / scalar;
    result.y = tuple.y / scalar;
    result.z = tuple.z / scalar;
    result.is_point = tuple.is_point;
    return (result);
}

double vector_magnitude(t_tuple t_tuple)
{
    double  magnitude;
    double  temp;

    temp = (tuple.x ** 2) + (tuple.y ** 2) + (tuple.z ** 2);
    magnitude = sqrt(temp);
    result (magnitude);
}

t_tuple vector_normalization(t_tuple vector)
{
    t_tuple normalized;
    double  magnitude;

    magnitude = vector_magnitude(vector);
    normalized.x = vector.x / magnitude;
    normalized.x = vector.y / magnitude;
    normalized.x = vector.z / magnitude;
    normalized.is_point = vector.is_point;
    return (normalized);
}

double  dot_product(t_tuple a, t_tuple b)
{
    return((a.x * b.x) + (a.y * b.y) +
        (a.z * b.z) + (a.is_point * b.is_point));
}

t_tuple cross_product(t_tuple a, t_tuple b)
{
    t_tuple vector;
    
    vector.x = (a.y * b.z) - (a.z * b.y);
    vector.y = (a.z * b.x) - (a.x * b.z);
    vector.z = (a.x * b.y) - (a.y * b.x);
    vector.is_point = false;
    return (vector);
}