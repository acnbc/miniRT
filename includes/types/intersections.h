/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:38:35 by jessica           #+#    #+#             */
/*   Updated: 2026/04/05 06:34:41 by ldos_sa2         ###   ########.fr       */
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

#endif
