/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:14:01 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/03/16 23:58:25 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrix	*position(t_ray ray, double t)
{
	return (add_tuples(ray.ori, scalar_multiplication(ray.direc, t)));
}

double	*intersect(t_sphere sp, t_ray ray) //por enquanto só esfera
{
	double		a;
	double		b;
	double		delta;
	double		*t;
	t_matrix	*sphere_ray;

	t = malloc(2 * sizeof(double));
	sphere_ray = subtract_tuple(ray.ori, create_point(0, 0, 0));
	a = dot_product(ray.direc, ray.direc);
	b = 2 * dot_product(ray.direc, sphere_ray);
	delta = delta_calc(sp, ray);
	if (delta < 0)
		return (NULL);
	t[0] = ((-1 * b) - sqrt(delta)) / (2 * a);
	t[1] = ((-1 * b) + sqrt(delta)) / (2 * a);
	return (t);
}

double	hit(double *inter) //ve qual é a interseção mais próxima
{
	int			i;
	double		t;

	i = 0;
	t = INF;
	while (i < 2)
	{
		if (inter[i] > 0 && inter[i] < t)
			t = inter[i];
		i++;
	}
	if (t == INF) //2 valores negativos
		return (-1);
	return (t);
}

t_ray	transform(t_ray ray, t_matrix *matrix) //em vez de mudar o obj de lugar eu mudo o raio
{
	t_ray	new_ray;

	new_ray.ori = matrix_multiplication(ray.ori, matrix);
	new_ray.direc = matrix_multiplication(ray.direc, matrix);
	return (new_ray);
}
