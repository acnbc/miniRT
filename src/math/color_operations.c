/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:53:23 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/05 15:12:20 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_rgb   add_colors(t_rgb a, t_rgb b)
{
    t_rgb   result;
    
    result.r = a.r + b.r;
    result.g = a.g + b.g;
    result.b = a.b + b.b;
    return (result);
}

t_rgb   subtract_colors(t_rgb a, t_rgb b)
{
    t_rgb   result;
    
    result.r = a.r - b.r;
    result.g = a.g - b.g;
    result.b = a.b - b.b;
    return (result);
}

t_rgb   scalar_multiplication(t_rgb a, unsigned char scalar)
{
    t_rgb   result;

    result.r = a.r * scalar;
    result.g = a.g * scalar;
    result.b = a.b * scalar;
    return (result);
}

t_rgb   color_multiplication(t_rgb a, t_rgb b)
{
    t_rgb   result;
    
    result.r = a.r * b.r;
    result.g = a.g * b.g;
    result.b = a.b * b.b;
    return (result);
}