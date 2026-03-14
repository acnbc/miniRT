/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:14:01 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/03/14 18:59:49 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	create_ray(t_matrix origin, t_matrix direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;

	return(ray);
}

t_matrix	position(t_ray ray, double t)
{
	return(add_tuples(ray.origin, scalar_multiplication(ray.direction, t)));
}
