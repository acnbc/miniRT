/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/03/21 17:02:13 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

void			create_window(t_scene *scene, char *file);
void			create_image(t_window *win);
void			free_window(t_window **win);
void			free_image(t_image **img, void *mlx_ptr);

unsigned int	conver_color(t_rgb *rgb, unsigned char opacity);
void			pixel_put(t_window *win, int x, int y, unsigned int color);

#endif