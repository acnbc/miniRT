/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:38:35 by jessica           #+#    #+#             */
/*   Updated: 2026/04/02 21:43:49 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

typedef struct s_ray
{
	t_matrix		ori;
	t_matrix		direc;
}				t_ray;

typedef struct s_intersect
{
	double			t;
	t_object		*obj;
}				t_intersect;

typedef struct s_intersections
{
	t_intersect		*inter;
	int				n_inter;
}				t_intersections;

#endif
