/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:35:28 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 00:55:18 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

typedef enum e_id
{
	Invalid = -1,
	A,
	C,
	L,
	sp,
	pl,
	cy
}	t_id;

typedef struct s_amb_light
{
	t_id	id;
	double	light_ratio;
	t_rgb	colors;
}	t_amb_light;

typedef struct s_camera
{
	t_id		id;
	t_matrix	view_point;
	t_matrix	orientation_vector;
	double		field_of_view;
}	t_camera;

typedef struct s_light
{
	t_id		id;
	t_matrix	point;
	double		brightness;
	t_rgb		intensity;
	t_rgb		colors;
}	t_light;

typedef struct s_sphere
{
	double			diameter;
}	t_sphere;

typedef struct s_plane
{
	t_matrix	normalized_vector;
}	t_plane;

typedef struct s_cylinder
{
	t_matrix	normalized_vector;
	double		diameter;
	double		height;
}	t_cylinder;

typedef union u_object_type
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_object_type;

typedef struct s_object
{
	t_id			id;
	t_matrix		coord;
	t_object_type	object;
	t_material		material;
	struct s_object	*next;
}	t_object;

#endif
