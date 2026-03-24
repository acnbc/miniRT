/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:14:01 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/03/24 03:53:33 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrix	position(t_ray ray, double t)
{
	t_matrix	mult;
	t_matrix	position;

	scalar_multiplication(&mult, &ray.direc, t);
	add_tuples(&position, &ray.ori, &mult);
	return (position);
}

t_intersect	*sp_intersect(t_object ob, t_ray ray) //por enquanto só esfera
{
	double		a;
	double		b;
	double		delta;
	t_intersect	*inter;
	t_matrix	sphere_ray;

	inter = safe_malloc(2 * sizeof(t_intersect));
	inter[0].obj = ob;
	inter[1].obj = ob;
	subtract_tuple(&sphere_ray, &ray.ori, &ob.coord);
	a = dot_product(&ray.direc, &ray.direc);
	b = 2 * dot_product(&ray.direc, &sphere_ray);
	delta = delta_calc(ob, ray);
	if (delta < 0) //ray não intercepta
	{
		free(inter);
		return (NULL);
	}
	inter[0].t = ((-1 * b) - sqrt(delta)) / (2 * a); //inter.t é a distancia escalar entre a origem do raio e onde intercepta
	inter[1].t = ((-1 * b) + sqrt(delta)) / (2 * a);
	return (inter);
}

t_intersect	*hit(t_intersections *inters) //vai retornar o object t_intersec com a menor intersect
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
	if (min == -1) //2 valores negativos
		return (NULL);
	return (&inters->inter[min]);
}

t_ray	transform(t_ray ray, t_matrix *matrix) //em vez de mudar o obj de lugar eu mudo o raio
{
	t_ray	new_ray;

	matrix_tuple_multiplication(&new_ray.ori, &ray.ori, matrix);
	matrix_tuple_multiplication(&new_ray.direc, &ray.direc, matrix);
	return (new_ray);
}
