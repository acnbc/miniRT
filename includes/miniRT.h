/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/03/14 23:23:02 by ldos_sa2         ###   ########.fr       */
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
# include "matrix_transformations.h"

/*------------- APAGAR ------------------*/
# include "tests.h"

// adicionar aqui as funcoes que forem criadas
void	*safe_malloc(size_t size);
void	free_matrix(t_matrix *matrix);

t_ray	create_ray(t_matrix *origin, t_matrix *direction);
t_matrix	*position(t_ray ray, double t);
t_sphere	create_sphere(int id);
double	*intersect(t_sphere sp, t_ray ray);
double	hit(double *inter);
double	*intersect(t_sphere sp, t_ray ray);

#endif
