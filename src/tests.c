/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:38:20 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/05 13:12:17 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void    print_tuples(t_tuple tuple)
{
    printf("Tuple:\n\tx = %.2f\n\ty = %.2f\n\tz = %.2f\n", tuple.x, tuple.y, tuple.z);
    if (tuple.is_point)
        printf("The tuple is a point\n");
    else
        printf("The tuple is a vector\n");
}