/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:47:17 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/03/24 03:44:12 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_ray	create_ray(t_matrix origin, t_matrix direction)
{
	t_ray	ray;

	ray.ori = origin;
	ray.direc = direction;
	return (ray);
}

double	delta_calc(t_object ob, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_matrix	sphere_ray;

	subtract_tuple(&sphere_ray, &ray.ori, &ob.coord); //distancia do raio até o centro da esfera
	a = dot_product(&ray.direc, &ray.direc);
	b = 2 * dot_product(&ray.direc, &sphere_ray);
	c = (dot_product(&sphere_ray, &sphere_ray)) - 1;
	return ((b * b) - (4 * a * c));
}

