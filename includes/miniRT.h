/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/02/15 03:49:15 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "types.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

t_scene			*read_image(char *file);

t_amb_light		*create_amb_light(char **infos);
t_camera		*create_camera(char **infos);
t_light			*create_light(char **infos);

void			print_error(char *error, bool clean);
void			free_scene(t_scene **scene);

t_id			get_id(char *str);
t_tuple			*get_coord(char *str, bool vector);
t_object_type	*get_object_type(t_id id, char **line);
t_rgb			*get_coolors(char *str);

t_object		*lst_new_object(char **infos, t_id id);
void			lst_add_back_object(t_object **lst, t_object *new);
t_object		*lst_back_object(t_object *lst);
void			lst_clear_object(t_object **lst);


#endif