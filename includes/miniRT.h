/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/04/08 17:51:34 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <sys/time.h>
# include <X11/keysymdef.h>
# include <X11/X.h>

# include "types/types.h"
# include "minirt_math.h"
# include "interface.h"
# include "parsing.h"
# include "light_shading.h"
# include "ray_tracing.h"

void			read_image(t_scene **scene, char *file);
void			init_hooks(t_scene *scene);

void			exit_error(t_msg_error error, t_scene **_scene);
void			free_scene(t_scene **scene);

void			free_matrix(t_matrix *matrix);

void			create_ray(t_ray *ray, t_matrix origin, t_matrix direction);
void			position(t_matrix *point, t_ray *ray, double t);

#endif
