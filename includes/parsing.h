/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/04/07 01:05:20 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void			create_amb_light(t_scene *scene, char ***infos, int index);
void			create_camera(t_scene *scene, char ***infos, int index);
void			create_light(t_scene *scene, char ***infos, int index);

t_id			get_id(char *str);
t_matrix		get_coord(char **infos, int index, bool vector);
void			get_object_type(t_object *object, char ***infos, int index);
t_msg_error		get_colors(t_rgb *colors, char **infos, int index);
t_msg_error		valid_tuple(t_matrix matrix);

t_object		*lst_new_object(char ***infos, t_id id);
void			lst_add_back_object(t_object **lst, t_object *new);
t_object		*lst_back_object(t_object *lst);
void			lst_clear_object(t_object **lst);

void			transformation_matrix(t_object *object);

#endif