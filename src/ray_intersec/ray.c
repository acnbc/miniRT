/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:58:38 by jessica           #+#    #+#             */
/*   Updated: 2026/04/01 12:31:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	sphere_transform_ray(t_ray *transformed, t_object *ob, t_ray *ray);

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
	t_ray		transformed_ray;

	inter[0].obj = NULL;
	inter[1].obj = NULL;
	inter[0].t = 0;
	inter[1].t = 0;
	sphere_transform_ray(&transformed_ray, ob, ray);
	init_point(&sphere_origin, 0, 0, 0);
	subtract_tuple(&sphere_ray, &transformed_ray.ori, &sphere_origin);
	numbers.x = dot_product(&transformed_ray.direc, &transformed_ray.direc);
	numbers.y = 2 * dot_product(&transformed_ray.direc, &sphere_ray);
	numbers.z = dot_product(&sphere_ray, &sphere_ray) - 1;
	delta = (numbers.y * numbers.y) - (4 * numbers.x * numbers.z);
	if (delta < 0)
		return ;
	inter[0].obj = ob;
	inter[1].obj = ob;
	inter[0].t = ((-1 * numbers.y) - sqrt(delta)) / (2 * numbers.x);
	inter[1].t = ((-1 * numbers.y) + sqrt(delta)) / (2 * numbers.x);
}

t_intersect	*hit(t_intersections *inters)
{
	int	i;
	int	min;

	i = 0;
	min = -1;
	while (i < inters->n_inter)
	{
		if (inters->inter[i].t >= 0)
		{
			if (min == -1 || inters->inter[i].t < inters->inter[min].t)
				min = i;
		}
		i++;
	}
	if (min == -1)
		return (NULL);
	return (&inters->inter[min]);
}

static void	sphere_transform_ray(t_ray *transformed, t_object *ob, t_ray *ray)
{
	double		r;
	t_matrix	diff;
	t_matrix	inv_matrix;

	if (ob->coord.rows == 4 && ob->coord.cols == 4)
	{
		inverse_matrix(&inv_matrix, &ob->coord);
		matrix_tuple_multiplication(&transformed->ori, &inv_matrix, &ray->ori);
		matrix_tuple_multiplication(&transformed->direc,
			&inv_matrix, &ray->direc);
		return ;
	}
	r = ob->object.sphere->diameter * 0.5;
	if (r < EPSILON)
		r = EPSILON;
	subtract_tuple(&diff, &ray->ori, &ob->coord);
	scalar_multiplication(&transformed->ori, &diff, 1.0 / r);
	scalar_multiplication(&transformed->direc, &ray->direc, 1.0 / r);
}
