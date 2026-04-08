/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 02:44:21 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/04/08 10:39:14 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static double	cy_dot_product(const t_matrix *a, const t_matrix *b)
{
	return ((a->m_4x1[0] * b->m_4x1[0]) + (a->m_4x1[2] * b->m_4x1[2]));
}

static double	check_cap(t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->ori.m_4x1[0] + (t * ray->direc.m_4x1[0]);
	z = ray->ori.m_4x1[2] + (t * ray->direc.m_4x1[2]);
	return ((pow(x, 2) + pow(z, 2)) <= 1.0 + EPSILON);
}

static void	cy_body_intersect(t_intersect inter[2], t_object *ob, t_ray *ray)
{
	double	t0;
	double	t1;
	double	y;
	double	delta;
	t_tuple	n;

	inter[0].obj = NULL;
	inter[1].obj = NULL;
	inter[0].t = 0;
	inter[1].t = 0;

	n.x = cy_dot_product(&ray->direc, &ray->direc);

	// evita divisão por zero
	if (fabs(n.x) < EPSILON)
		return ;

	n.y = 2 * cy_dot_product(&ray->direc, &ray->ori);
	n.z = cy_dot_product(&ray->ori, &ray->ori) - 1;

	delta = n.y * n.y - 4 * n.x * n.z;
	if (delta < 0)
		return ;

	// caso tangente
	if (fabs(delta) < EPSILON)
	{
		t0 = -n.y / (2 * n.x);
		y = ray->ori.m_4x1[1] + t0 * ray->direc.m_4x1[1];

		if (t0 > EPSILON && -0.5 < y && y < 0.5)
		{
			inter[0].t = t0;
			inter[0].obj = ob;
		}
		return;
	}

	t0 = (-n.y - sqrt(delta)) / (2 * n.x);
	t1 = (-n.y + sqrt(delta)) / (2 * n.x);

	// ordenar
	if (t0 > t1)
	{
		double tmp = t0;
		t0 = t1;
		t1 = tmp;
	}

	y = ray->ori.m_4x1[1] + t0 * ray->direc.m_4x1[1];
	if (t0 > EPSILON && -0.5 < y && y < 0.5)
	{
		inter[0].t = t0;
		inter[0].obj = ob;
	}

	y = ray->ori.m_4x1[1] + t1 * ray->direc.m_4x1[1];
	if (t1 > EPSILON && -0.5 < y && y < 0.5)
	{
		inter[1].t = t1;
		inter[1].obj = ob;
	}
}

static void	cy_tap_intersect(t_intersect inter[2], t_object *ob, t_ray *ray)
{
	double	t;

	inter[0].obj = NULL;
	inter[0].t = 0;
	inter[1].obj = NULL;
	inter[1].t = 0;

	if (fabs(ray->direc.m_4x1[1]) < EPSILON)
		return ;

	t = (-0.5 - ray->ori.m_4x1[1]) / ray->direc.m_4x1[1];
	if (t > EPSILON && check_cap(ray, t))
	{
		inter[0].t = t;
		inter[0].obj = ob;
	}

	t = (0.5 - ray->ori.m_4x1[1]) / ray->direc.m_4x1[1];
	if (t > EPSILON && check_cap(ray, t))
	{
		inter[1].t = t;
		inter[1].obj = ob;
	}
}

void	cy_intersect(t_intersect inter[4], t_object *ob, t_ray *ray)
{
	t_intersect	pair_1[2];
	t_intersect	pair_2[2];

	cy_body_intersect(pair_1, ob, ray);
	cy_tap_intersect(pair_2, ob, ray);
	inter[0] = pair_1[0];
	inter[1] = pair_1[1];
	inter[2] = pair_2[0];
	inter[3] = pair_2[1];
}
