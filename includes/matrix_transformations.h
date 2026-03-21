/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:35:52 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TRANSFORMATIONS_H
# define MATRIX_TRANSFORMATIONS_H

void		translation(t_matrix *offset, t_matrix *out);
void		scaling(t_matrix *offset, t_matrix *out);
void		x_axis_rotation(double rotation_value, t_matrix *out);
void		y_axis_rotation(double rotation_value, t_matrix *out);
void		z_axis_rotation(double rotation_value, t_matrix *out);
void		combine_transformations(t_matrix *transposed,
				t_matrix *rotated, t_matrix *scaled, t_matrix *out);

#endif