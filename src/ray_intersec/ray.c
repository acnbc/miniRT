/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:58:38 by jessica           #+#    #+#             */
/*   Updated: 2026/04/08 08:55:37 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	position(t_matrix *point, t_ray *ray, double t)
{
	t_matrix	mult;

	scalar_multiplication(&mult, &ray->direc, t);
	add_tuples(point, &ray->ori, &mult);
}

void	sp_intersect(t_intersect inter[2], t_object *ob, t_ray *ray)
{
	double		delta;
	t_matrix	sphere_ray;
	t_tuple		numbers;
	t_matrix	sphere_origin;

	inter[0].obj = NULL;
	inter[1].obj = NULL;
	inter[0].t = 0;
	inter[1].t = 0;
	init_point(&sphere_origin, 0, 0, 0);
	subtract_tuple(&sphere_ray, &ray->ori, &sphere_origin);
	numbers.x = dot_product(&ray->direc, &ray->direc);
	numbers.y = 2 * dot_product(&ray->direc, &sphere_ray);
	numbers.z = dot_product(&sphere_ray, &sphere_ray) - 1;
	delta = (numbers.y * numbers.y) - (4 * numbers.x * numbers.z);
	if (delta < 0)
		return ;
	inter[0].obj = ob;
	inter[1].obj = ob;
	inter[0].t = ((-1 * numbers.y) - sqrt(delta)) / (2 * numbers.x);
	inter[1].t = ((-1 * numbers.y) + sqrt(delta)) / (2 * numbers.x);
}

void	pl_intersect(t_intersect inter[1], t_object *ob, t_ray *ray)
{
	inter[0].obj = NULL;
	inter[0].t = 0;
	if (fabs(ray->direc.m_4x1[1]) < EPSILON)
		return ;
	inter[0].t = (-1 * ray->ori.m_4x1[1]) / ray->direc.m_4x1[1];
	inter[0].obj = ob;
}

void	transform_ray(t_ray *transformed, t_object *ob, t_ray *ray)
{
	matrix_tuple_multiplication(&transformed->ori, &ob->inverse_matrix,
		&ray->ori);
	matrix_tuple_multiplication(&transformed->direc, &ob->inverse_matrix,
		&ray->direc);
}
