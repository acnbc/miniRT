/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:08:22 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:18 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# include <math.h>
# define EPSILON 0.00001

void		add_tuples(t_matrix *a, t_matrix *b, t_matrix *out);
void		subtract_tuple(t_matrix *a, t_matrix *b, t_matrix *out);
void		negate_tuple(t_matrix *tuple, t_matrix *out);
void		scalar_multiplication(t_matrix *tuple, double scalar, t_matrix *out);
void		scalar_division(t_matrix *tuple, double scalar, t_matrix *out);
double		vector_magnitude(t_matrix *tuple);
void		vector_normalization(t_matrix *vector, t_matrix *out);
double		dot_product(t_matrix *a, t_matrix *b);
void		cross_product(t_matrix *a, t_matrix *b, t_matrix *out);

void		init_point(t_matrix *out, double x, double y, double z);
void		init_vector(t_matrix *out, double x, double y, double z);
void		init_matrix(t_matrix *out, int rows, int cols);
void		init_identity_matrix(t_matrix *out, int dim);
bool		is_equal(double a, double b);

double		mat_get(t_matrix *m, int row, int col);
void		mat_set(t_matrix *m, int row, int col, double value);
void		matrix_multiplication(t_matrix *a, t_matrix *b, t_matrix *out);
void		matrix_tuple_multiplication(t_matrix *a, t_matrix *b, t_matrix *out);
bool		matrix_comparison(t_matrix *a, t_matrix *b);
void		matrix_transposition(t_matrix *m, t_matrix *out);
double		get_2x2_determinant(t_matrix *a);
double		*get_matrix(t_matrix *m);
void		get_submatrix(t_matrix *m, int row, int col, t_matrix *out);
double		get_minor(t_matrix *m, int row, int col, t_matrix *s1, t_matrix *s2);
double		get_cofactor(t_matrix *m, int row, int col, t_matrix *s1, t_matrix *s2);
double		matrix_determinant(t_matrix *m);
bool		is_invertible(t_matrix *m);
void		inverse_matrix(t_matrix *m, t_matrix *out);

#endif