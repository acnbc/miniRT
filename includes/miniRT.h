/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/03/21 17:05:03 by jessica          ###   ########.fr       */
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

#endif