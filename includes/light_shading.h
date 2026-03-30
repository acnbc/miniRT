/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shading.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:43:57 by jessica           #+#    #+#             */
/*   Updated: 2026/03/30 02:18:17 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_SHADING_H
# define LIGHT_SHADING_H

void			normal_at(t_matrix *normal, t_object *sphere, t_matrix *point);
void			reflect(t_matrix *result, t_matrix *vector, t_matrix *normal);

void			default_material(t_material *material);

void			tuple_addition(t_tuple *result, const t_tuple *a,
					const t_tuple *b);
void			tuple_multiplication(t_tuple *result, const t_tuple *a,
					const t_tuple *b);
void			tuple_scalar_multiplication(t_tuple *result,
					const t_tuple *color, double scalar);

#endif
