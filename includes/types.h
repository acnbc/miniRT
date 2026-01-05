/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:43:56 by jessica           #+#    #+#             */
/*   Updated: 2026/01/05 16:37:03 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <stdbool.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	bool	is_point;
}	t_tuple;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct	s_matrix
{
	double	m[16];
	int		i;
	int		j;
}				t_matrix;

typedef	struct	s_id_matrix
{
	static int	id_m[] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	int			i;
	int			j;
}

typedef enum e_id
{
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
	t_id	id;
	t_tuple	view_point;
	t_tuple	orientation_vector;
	double	field_of_view;
}	t_camera;

typedef struct s_light
{
	t_id	id;
	t_tuple	light_point;
	double	brightness;
}	t_light;

typedef struct s_sphere
{
	double	diameter;
}	t_sphere;

typedef struct s_plane
{
	t_tuple	normalized_vector;
}	t_plane;

typedef struct s_cylinder
{
	t_tuple	normalized_vector;
	double	diameter;
	double	height;
}	t_cylinder;

typedef union u_object_type
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_object_type;

typedef struct s_object
{
	t_id			id;
	t_tuple			coord;
	t_rgb			colors;
	t_object_type	object;
	struct s_object	*next;
}	t_object;

typedef struct s_scene
{
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;
	t_object	*objects;
}	t_scene;

#endif