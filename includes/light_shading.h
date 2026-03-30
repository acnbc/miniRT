/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shading.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:43:57 by jessica           #+#    #+#             */
/*   Updated: 2026/03/30 02:08:16 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_SHADING_H
# define LIGHT_SHADING_H

void			tuple_addition(t_tuple *result, const t_tuple *a,
					const t_tuple *b);
void			tuple_multiplication(t_tuple *result, const t_tuple *a,
					const t_tuple *b);
void			tuple_scalar_multiplication(t_tuple *result,
					const t_tuple *color, double scalar);

#endif
