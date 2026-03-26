/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:43:56 by jessica           #+#    #+#             */
/*   Updated: 2026/03/25 20:45:49 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <stdbool.h>

typedef struct s_image
{
	void	*ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
}	t_image;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
	char	*title;
	t_image	*img;
}	t_window;

typedef struct s_tuple
{
	double			x;
	double			y;
	double			z;
	bool			is_point;
}	t_tuple;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_matrix
{
	union
	{
		double		m_2x2[4];
		double		m_4x1[4];
		double		m_3x3[9];
		double		m_4x4[16];
	};
	int				rows;
	int				cols;
}	t_matrix;

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
	t_matrix	light_point;
	double		brightness;
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
	t_rgb			colors;
	t_object_type	object;
	struct s_object	*next;
}	t_object;

typedef struct s_scene
{
	t_window	*window;
	t_amb_light	*amb_light;
	t_camera	*camera;
	t_light		*light;
	t_object	*objects;
	int			fd;
}	t_scene;

typedef enum e_msg_error
{
	ERR_MALLOC = 1,
	ERR_ARGS,
	ERR_FILE_FORMAT,
	ERR_FILE_READ,
	ERR_DUPLICATE,
	ERR_RANGE,
	ERR_MISSING_ELEM,
	ERR_MISSING_ARGS,
	ERR_ID,
	ERR_MLX_INIT,
	ERR_MLX_NEW_WIN,
	ERR_MLX_NEW_IMG,
	ERR_MLX_GET_DATA_ADDR
}	t_msg_error;



//ray_sphere_intersection

typedef struct s_ray
{
	t_matrix		ori;
	t_matrix		direc;
}				t_ray;

typedef struct s_intersect
{
	double			t;
	t_object		obj;
}				t_intersect;

typedef struct s_intersections
{
	t_intersect		*inter;
	int				n_inter;
}				t_intersections;

#endif
