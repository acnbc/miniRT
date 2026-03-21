/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:35:52 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/21 15:53:41 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TRANSFORMATIONS_H
# define MATRIX_TRANSFORMATIONS_H

void	translation(t_matrix *matrix, const t_matrix *offset);
void	scaling(t_matrix *matrix, const t_matrix *offset);
void	x_axis_rotation(t_matrix *matrix, double rotation_value);
void	y_axis_rotation(t_matrix *matrix, double rotation_value);
void	z_axis_rotation(t_matrix *matrix, double rotation_value);
void	combine_transformations(t_matrix *matrix, t_matrix *transposed,
			t_matrix *rotated, t_matrix *scaled);

#endif