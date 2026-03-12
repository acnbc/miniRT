/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/03/12 00:33:25 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "types.h"
# include "math.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*------------- APAGAR ------------------*/
# include "tests.h"

t_scene			*read_image(char *file);

t_amb_light		*create_amb_light(char **infos);
t_camera		*create_camera(char **infos);
t_light			*create_light(char **infos);

void			exit_error(char *error, bool clean, t_scene **_scene);
void			free_scene(t_scene **scene);

t_id			get_id(char *str);
t_tuple			*get_coord(char *str, bool vector);
t_object_type	*get_object_type(t_id id, char **line);
t_rgb			*get_coolors(char *str);

t_object		*lst_new_object(char **infos, t_id id);
void			lst_add_back_object(t_object **lst, t_object *new);
t_object		*lst_back_object(t_object *lst);
void			lst_clear_object(t_object **lst);

void			*safe_malloc(size_t size);
void			free_matrix(t_matrix *matrix);

#endif