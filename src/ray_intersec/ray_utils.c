/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:47:17 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/03/16 23:59:47 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_ray	create_ray(t_matrix *origin, t_matrix *direction)
{
	t_ray	ray;

	ray.ori = origin;
	ray.direc = direction;
	return (ray);
}

t_sphere	create_sphere(int id) //acho que essa é mais para teste
{
	t_sphere	sp;

	sp.diameter = 2.0;
	sp.id = id;
	return (sp);
}

double	delta_calc(t_sphere sp, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_matrix	*sphere_ray;

	sphere_ray = subtract_tuple(ray.ori, create_point(0, 0, 0)); //está só com o centro 0,0,0
	a = dot_product(ray.direc, ray.direc);
	b = 2 * dot_product(ray.direc, sphere_ray);
	c = (dot_product(sphere_ray, sphere_ray)) - pow(sp.diameter / 2, 2);
	return ((b * b) - (4 * a * c));
}
