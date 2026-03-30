/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/03/30 01:06:05 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

void			create_window(t_scene *scene, char *file);
void			create_image(t_window *win);
void			free_window(t_window **win);
void			free_image(t_image **img, void *mlx_ptr);

unsigned int	convert_color(const t_tuple *rgb);
void			pixel_put(t_window *win, int x, int y, unsigned int color);

#endif