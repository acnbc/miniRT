/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shading.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:43:57 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 02:02:31 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_SHADING_H
# define LIGHT_SHADING_H

t_tuple			lighting(t_light_base *light_calc, t_material *material,
					t_matrix *v_eye, t_matrix *v_norm);

void			normal_at(t_matrix *normal, t_object *sphere, t_matrix *point);
void			reflect(t_matrix *result, t_matrix *vector, t_matrix *normal);

t_light_base	calc_light_base(const t_hit_shade *in);
void			default_material(t_material *material);

void			tuple_addition(t_tuple *result, const t_tuple *a,
					const t_tuple *b);
void			tuple_multiplication(t_tuple *result, const t_tuple *a,
					const t_tuple *b);
void			tuple_scalar_multiplication(t_tuple *result,
					const t_tuple *a, double scalar);

#endif
