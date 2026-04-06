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

void			compute_camera_axes(t_cam_basis *basis,
					const t_camera *camera);
void			init_viewport(t_viewport *viewport, t_scene *scene);
void			map_pixel_ndc(t_scene *scene, int x, int y, t_ndc *out);
void			ray_gen_init(t_ray_gen *context, t_scene *scene);
void			make_primary_ray(t_ray_gen *context, const t_ndc *ndc,
					t_ray *ray);

size_t			count_objects(t_object *objects);
bool			resolve_closest_hit(t_intersect *buf, size_t n,
					t_intersect *out_hit);
bool			closest_hit(t_object *objects, t_ray *ray,
					t_intersect *out_hit);

void			shade_orient_normal(t_matrix *norm, t_ray *ray);
t_rgb			shade_lit_color(t_hit_shade *in);
t_rgb			shade_sphere_pixel(t_scene *scene, t_ray *ray,
					t_intersect *hit);

void			ray_show_image(t_window *win);
void			ray_trace_scanline(t_scene *scene, t_ray_gen *context, int y);
void			ray_trace_loop(t_scene *scene, t_ray_gen *context);

void			print_put_row(t_window *win, int y, double den_x,
					double den_y);

void			ray_tracer(t_scene *scene);

void			sp_intersect(t_intersect inter[2], t_object *ob, t_ray *ray);
t_intersect		*hit(t_intersect *buf, size_t n);
void			transform_ray(t_ray *transformed, t_object *ob, t_ray *ray);
void			pl_intersect(t_intersect inter[1], t_object *ob, t_ray *ray);
void			cy_intersect(t_intersect inter[4], t_object *ob, t_ray *ray);
size_t			fill_hits(t_object *objects, t_ray *ray, t_intersect *buf,
					t_intersect pair[4]);
#endif
