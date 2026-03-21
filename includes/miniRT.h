/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/03/21 16:58:10 by jessica          ###   ########.fr       */
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
# include <X11/keysymdef.h>
# include <X11/X.h>
# include "matrix_transformations.h"

/*------------- APAGAR ------------------*/
# include "tests.h"

void			read_image(t_scene **scene, char *file);
void			init_hooks(t_scene *scene);

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

void			create_window(t_scene *scene, char *file);
void			create_image(t_window *win);
void			free_window(t_window **win);
void			free_image(t_image **img, void *mlx_ptr);

unsigned int	conver_color(t_rgb *rgb, unsigned char opacity);
void			pixel_put(t_window *win, int x, int y, unsigned int color);

#endif