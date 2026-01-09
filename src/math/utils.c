/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:03:49 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/02 13:04:10 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple create_point(double x, double y, double z)
{
    t_tuple point;

    point.x = x;
    point.y = y;
    point.z = z;
    point.is_point = true;
    return (point);
}

t_tuple create_vector(double x, double y, double z)
{
    t_tuple vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;
    vector.is_point = false;
    return (vector);
}

bool    is_equal(double a, double b)
{
    if (fabs(a - b) < EPSILON)
        return (true);
    return (false);
}