/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:47:17 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/04/08 18:34:35 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	create_ray(t_ray *ray, t_matrix origin, t_matrix direction)
{
	ray->ori = origin;
	ray->direc = direction;
}

static double	cy_dot_product(const t_matrix *a, const t_matrix *b)
{
	return ((a->m_4x1[0] * b->m_4x1[0]) + (a->m_4x1[2] * b->m_4x1[2]));
}

bool	calc_inter(t_intersect	inter[2], double t[2], t_object *ob, t_ray *ray)
{
	double	delta;
	double	y;
	t_tuple	n;

	n.x = cy_dot_product(&ray->direc, &ray->direc);
	n.y = 2 * cy_dot_product(&ray->direc, &ray->ori);
	n.z = cy_dot_product(&ray->ori, &ray->ori) - 1;
	delta = n.y * n.y - 4 * n.x * n.z;
	if (delta < 0 || fabs(n.x) < EPSILON)
		return (false);
	if (fabs(delta) < EPSILON)
	{
		t[0] = -n.y / (2 * n.x);
		y = ray->ori.m_4x1[1] + t[0] * ray->direc.m_4x1[1];
		if (t[0] > EPSILON && -0.5 < y && y < 0.5)
		{
			inter[0].t = t[0];
			inter[0].obj = ob;
		}
		return (false);
	}
	t[0] = (-n.y - sqrt(delta)) / (2 * n.x);
	t[1] = (-n.y + sqrt(delta)) / (2 * n.x);
	return (true);
}

void	assing_inter(t_intersect inter[2], double t[2], t_object *ob,
			t_ray *ray)
{
	double	y;

	y = ray->ori.m_4x1[1] + t[0] * ray->direc.m_4x1[1];
	if (t[0] > EPSILON && -0.5 < y && y < 0.5)
	{
		inter[0].t = t[0];
		inter[0].obj = ob;
	}
	y = ray->ori.m_4x1[1] + t[1] * ray->direc.m_4x1[1];
	if (t[1] > EPSILON && -0.5 < y && y < 0.5)
	{
		inter[1].t = t[1];
		inter[1].obj = ob;
	}
}
