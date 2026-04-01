/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 00:00:00 by anogueir         #+#    #+#             */
/*   Updated: 2026/03/31 00:00:00 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACING_H
# define RAY_TRACING_H

# include "types.h"
# include <stddef.h>
# include <stdbool.h>

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

typedef struct s_ndc
{
	double	x;
	double	y;
}	t_ndc;

typedef struct s_hit_shade
{
	t_scene		*sc;
	t_ray		*ray;
	t_matrix	*pt;
	t_matrix	*nm;
	t_material	*mt;
}	t_hit_shade;

void			compute_camera_axes(t_cam_basis *basis,
					const t_camera *camera);
void			init_viewport(t_viewport *viewport, t_scene *scene);
void			map_pixel_ndc(t_scene *scene, int x, int y, t_ndc *out);
void			ray_gen_init(t_ray_gen *ctx, t_scene *scene);
void			make_primary_ray(t_ray_gen *ctx, const t_ndc *ndc,
					t_ray *ray);

size_t			count_spheres(t_object *objects);
size_t			fill_sphere_hits(t_object *objects, t_ray *ray,
					t_intersect *buf, t_intersect pair[2]);
bool			resolve_closest_hit(t_intersect *buf, size_t n,
					t_intersect *out_hit);
bool			closest_hit_spheres(t_object *objects, t_ray *ray,
					t_intersect *out_hit);
void			amb_tuple(t_scene *scene, t_tuple *out);

void			rgb_to_tuple(t_tuple *out, const t_rgb *rgb);
void			scene_amb_times_material(t_tuple *out, t_scene *scene,
					const t_tuple *mat_color);
void			shade_orient_normal(t_matrix *norm, t_ray *ray);
t_tuple			shade_lit_color(t_hit_shade *in);
unsigned int	shade_sphere_pixel(t_scene *scene, t_ray *ray,
					t_intersect *hit);

void			ray_show_image(t_window *win);
void			ray_trace_scanline(t_scene *scene, t_ray_gen *ctx, int y,
					unsigned int amb_c);
void			ray_trace_loop(t_scene *scene, t_ray_gen *ctx,
					t_tuple *amb);

void			print_put_row(t_window *win, int y, double den_x,
					double den_y);

void			ray_tracer(t_scene *scene);

#endif
