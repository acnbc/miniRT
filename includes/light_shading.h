/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shading.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:43:57 by jessica           #+#    #+#             */
/*   Updated: 2026/04/08 17:51:19 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_SHADING_H
# define LIGHT_SHADING_H

t_tuple			lighting(t_light_base *light_calc, t_material *material,
					t_matrix *v_eye, t_matrix *v_norm);

void			normal_at(t_matrix *normal, t_object *sphere, t_matrix *point);
void			reflect(t_matrix *result, t_matrix *vector, t_matrix *normal);
bool			is_shadowed(const t_hit_shade *in);

t_light_base	calc_light_base(const t_hit_shade *in);
void			default_material(t_material *material);
void			calc_over_point(t_matrix *over_point, const t_matrix *norm_v,
					const t_matrix *hit_pt);

void			rgb_addition(t_tuple *result, const t_tuple *a,
					const t_tuple *b);
void			rgb_multiplication(t_tuple *result, const t_tuple *a,
					const t_tuple *b);
void			rgb_scalar_multiplication(t_tuple *result,
					const t_tuple *a, double scalar);

#endif
