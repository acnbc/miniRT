/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:14:01 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/03/16 23:27:50 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_ray	create_ray(t_matrix *origin, t_matrix *direction)
{
	t_ray	ray;

	ray.ori = origin;
	ray.direc = direction;
	return(ray);
}

t_matrix	*position(t_ray ray, double t)
{
	return(add_tuples(ray.ori, scalar_multiplication(ray.direc, t)));
}

t_sphere	create_sphere(int id)
{
	t_sphere sp;

	sp.diameter = 2.0;
	sp.id = id;
	return(sp);
}

double	*intersect(t_sphere sp, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	t_matrix	*sphere_ray;
	double	delta;
	double	*t;

	t = malloc(2 * sizeof(double));
	sphere_ray = subtract_tuple(ray.ori, create_point(0, 0, 0));  //center sphere
	a = dot_product(ray.direc, ray.direc);
	b = 2 * dot_product(ray.direc, sphere_ray);
	c = (dot_product(sphere_ray, sphere_ray)) - pow(sp.diameter / 2, 2);
	delta = ((b * b) - (4 * a * c));
	if (delta < 0)
		return (NULL);
	t[0] = ((-1 * b) - sqrt(delta)) / (2 * a);
	t[1] = ((-1 * b) + sqrt(delta)) / (2 * a);
	return(t);
}
double	hit(double *inter)
{
	int			i;
	double		t;

	i = 0;
	t = INF;
	while(i < 2)
	{
		if(inter[i] > 0 && inter[i] < t)
			t = inter[i];
		i++;
	}
	if (t == INF) //2 valores negativos
		return (-1);
	return (t);
}

t_ray	transform(t_ray ray, t_matrix *matrix)
{
	t_ray new_ray;

	new_ray.ori = matrix_multiplication(ray.ori, matrix);
	new_ray.direc = matrix_multiplication(ray.direc, matrix);
	return (new_ray);
}
