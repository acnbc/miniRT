/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 02:44:21 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/04/05 07:12:30 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static double	cy_dot_product(const t_matrix *a, const t_matrix *b)
{
	return ((a->m_4x1[0] * b->m_4x1[0]) + (a->m_4x1[2] * b->m_4x1[2]));
}

static double	check_cap(t_ray *ray, double t, double diameter)
{
	double	x;
	double	z;

	x = ray->ori.m_4x1[0] + (t * ray->direc.m_4x1[0]);
	z = ray->ori.m_4x1[2] + (t * ray->direc.m_4x1[2]);
	return ((pow(x, 2) + pow(z, 2)) <= pow((diameter / 2), 2));
}

static void	cy_body_intersect(t_intersect inter[2], t_object *ob, t_ray *ray,
	double *min_max)
{
	double	t;
	double	y;
	double	delta;
	t_tuple	numbers;

	inter[0].obj = NULL;
	inter[1].obj = NULL;
	inter[0].t = 0;
	inter[1].t = 0;
	numbers.x = cy_dot_product(&ray->direc, &ray->direc);
	numbers.y = 2 * cy_dot_product(&ray->direc, &ray->ori);
	numbers.z = cy_dot_product(&ray->ori, &ray->ori) - 1;
	delta = (numbers.y * numbers.y) - (4 * numbers.x * numbers.z);
	if (delta < 0)
		return ;
	t = ((-1 * numbers.y) - sqrt(delta)) / (2 * numbers.x);
	y = ray->ori.m_4x1[1] + (t * ray->direc.m_4x1[1]);
	inter[0].obj = ob;
	if (min_max[0] < y && y < min_max[1])
		inter[0].t = ((-1 * numbers.y) - sqrt(delta)) / (2 * numbers.x);
	inter[1].obj = ob;
	t = ((-1 * numbers.y) + sqrt(delta)) / (2 * numbers.x);
	y = ray->ori.m_4x1[1] + (t * ray->direc.m_4x1[1]);
	if (min_max[0] < y && y < min_max[1])
		inter[1].t = ((-1 * numbers.y) + sqrt(delta)) / (2 * numbers.x);
}

static void	cy_tap_intersect(t_intersect inter[2], t_object *ob, t_ray *ray,
	double *min_max)
{
	double	t;
	double	n;

	n = ray->direc.m_4x1[1];
	inter[0].obj = NULL;
	inter[0].t = 0;
	inter[1].obj = NULL;
	inter[1].t = 0;
	/*if (closed || (n < EPSILON && n > -EPSILON))
		return ;*/
	inter[0].obj = ob;
	t = (min_max[0] - ray->ori.m_4x1[1]) / ray->direc.m_4x1[1];
	if (check_cap(ray, t, ob->object.cylinder->diameter))
		inter[0].t = t;
	inter[1].obj = ob;
	t = (min_max[1] - ray->ori.m_4x1[1]) / ray->direc.m_4x1[1];
	if (check_cap(ray, t, ob->object.cylinder->diameter))
		inter[1].t = t;
}

void	cy_intersect(t_intersect inter[4], t_object *ob, t_ray *ray)
{
	double		*min_max;
	t_intersect	pair_1[2];
	t_intersect	pair_2[2];

	min_max = safe_malloc(2 * sizeof(double));
	min_max[0] = (-1 * ob->object.cylinder->height) / 2;
	min_max[1] = (ob->object.cylinder->height) / 2;
	cy_body_intersect(pair_1, ob, ray, min_max);
	cy_tap_intersect(pair_2, ob, ray, min_max);
	inter[0] = pair_1[0];
	inter[1] = pair_1[1];
	inter[2] = pair_2[0];
	inter[3] = pair_2[1];
	free(min_max);
}
