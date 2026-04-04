/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:43:56 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 00:26:14 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "utils.h"
# include "elements.h"
# include "intersections.h"

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

typedef struct s_scene
{
	t_window	*window;
	t_amb_light	*amb_light;
	t_camera	*camera;
	t_light		*light;
	t_object	*objects;
	int			fd;
}	t_scene;

typedef struct s_viewport
{
	double	fov_rad;
	double	half_height;
	double	aspect;
	double	half_width;
}	t_viewport;

typedef struct s_cam_basis
{
	t_matrix	forward;
	t_matrix	right;
	t_matrix	up;
}	t_cam_basis;

typedef struct s_ray_gen
{
	const t_camera	*camera;
	t_cam_basis		basis;
	t_viewport		viewport;
}	t_ray_gen;

typedef struct s_hit_shade
{
	t_scene		*sc;
	t_ray		*ray;
	t_matrix	*pt;
	t_matrix	*nm;
	t_material	*mt;
	t_matrix	*o_pt;
}	t_hit_shade;

#endif
