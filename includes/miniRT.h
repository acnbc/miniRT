/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/03/24 02:52:20 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "types.h"
# include <math.h>
# include "math.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "matrix_transformations.h"

/*------------- APAGAR ------------------*/
# include "tests.h"

void			read_image(t_scene **scene, char *file);

void			create_amb_light(t_scene *scene, char ***infos, int index);
void			create_camera(t_scene *scene, char ***infos, int index);
void			create_light(t_scene *scene, char ***infos, int index);

void			exit_error(t_msg_error error, t_scene **_scene);
void			free_scene(t_scene **scene);

t_id			get_id(char *str);
t_matrix		get_coord(char **infos, int index, bool vector);
void			get_object_type(t_object *object, char ***infos, int index);
t_msg_error		get_coolors(t_rgb *colors, char **infos, int index);
t_msg_error		valid_tuple(t_matrix matrix);

t_object		*lst_new_object(char ***infos, t_id id);
void			lst_add_back_object(t_object **lst, t_object *new);
t_object		*lst_back_object(t_object *lst);
void			lst_clear_object(t_object **lst);

void			*safe_malloc(size_t size);
void			free_matrix(t_matrix *matrix);

t_ray			create_ray(t_matrix origin, t_matrix direction);
double			delta_calc(t_object ob , t_ray ray);
t_matrix		position(t_ray ray, double t);
t_intersect		*sp_intersect(t_object ob , t_ray ray);
double			hit(t_intersections *inters);
t_ray			transform(t_ray ray, t_matrix *matrix);

#endif
