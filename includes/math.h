/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:08:22 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/05 11:39:40 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# include <math.h>
# define EPSILON 0.00001
# define MATRIX_DIM 16

t_tuple add_tuples(t_tuple a, t_tuple b);
t_tuple subtract_tuple(t_tuple a, t_tuple b);
t_tuple negate_tuple(t_tuple tuple);
t_tuple scalar_multiplication(t_tuple tuple, double scalar);
t_tuple scalar_division(t_tuple tuple, double scalar);
double  vector_magnitude(t_tuple t_tuple);
t_tuple vector_normalization(t_tuple vector);
double  dot_product(t_tuple a, t_tuple b);
t_tuple cross_product(t_tuple a, t_tuple b);

t_tuple create_point(double x, double y, double z);
t_tuple create_vector(double x, double y, double z);
bool    is_equal(double a, double b);

double	mat_get(const t_matrix *m, int row, int col);
void	mat_set(t_matrix *m, int row, int col, double value);
t_matrix    *matrix_multiplication(t_matrix *a, t_matrix *b);
t_matrix    *matrix_tuple_multiplication(t_matrix *a, t_matrix *b);
bool    matrix_comparison(t_matrix *a, t_matrix *b);
t_matrix    *matrix_transposition(t_matrix *m);

#endif