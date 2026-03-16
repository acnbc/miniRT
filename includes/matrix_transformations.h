/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:35:52 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/16 14:17:54 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TRANSFORMATIONS_H
# define MATRIX_TRANSFORMATIONS_H

t_matrix	*translation(t_matrix *offset);
t_matrix	*scaling(t_matrix *offset);
t_matrix	*x_axis_rotation(double rotation_value);


#endif