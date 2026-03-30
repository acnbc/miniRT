/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/03/25 20:45:25 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "types.h"
# include "math.h"
# include "interface.h"
# include "parsing.h"
# include <math.h>
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

void			exit_error(t_msg_error error, t_scene **_scene);
void			free_scene(t_scene **scene);

void			*safe_malloc(size_t size);
void			free_matrix(t_matrix *matrix);

void			create_ray(t_ray *ray, t_matrix origin, t_matrix direction);
void			position(t_matrix *point, t_ray *ray, double t);

void			sp_intersect(t_intersect *inter, t_object *ob, t_ray *ray);
t_intersect		*hit(t_intersections *inters);

#endif
