/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:08:22 by anogueir          #+#    #+#             */
/*   Updated: 2026/04/07 00:30:47 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATH_H
# define MINIRT_MATH_H
# include <math.h>
# include "types/types.h"
# define EPSILON 0.00001
# define INF INFINITY

void		add_tuples(t_matrix *matrix, const t_matrix *a, const t_matrix *b);
void		subtract_tuple(t_matrix *matrix, const t_matrix *a,
				const t_matrix *b);
void		negate_tuple(t_matrix *matrix, const t_matrix *tuple);
void		scalar_multiplication(t_matrix *matrix, const t_matrix *tuple,
				double scalar);
void		scalar_division(t_matrix *matrix, const t_matrix *tuple,
				double scalar);
double		vector_magnitude(const t_matrix *tuple);
void		vector_normalization(t_matrix *matrix, const t_matrix *vector);
double		dot_product(const t_matrix *a, const t_matrix *b);
void		cross_product(t_matrix *matrix, const t_matrix *a,
				const t_matrix *b);

void		init_point(t_matrix *matrix, double x, double y, double z);
void		init_vector(t_matrix *matrix, double x, double y, double z);
void		init_matrix(t_matrix *matrix, int rows, int cols);
void		init_identity_matrix(t_matrix *matrix, int dim);
void		init_scaling_matrix(t_matrix *scale_mat, double x, double y,
				double z);
bool		is_equal(double a, double b);

double		mat_get(const t_matrix *m, int row, int col);
void		mat_set(t_matrix *m, int row, int col, double value);
void		matrix_multiplication(t_matrix *matrix, const t_matrix *a,
				const t_matrix *b);
void		matrix_tuple_multiplication(t_matrix *matrix, const t_matrix *a,
				const t_matrix *b);
bool		matrix_comparison(const t_matrix *a, const t_matrix *b);
void		matrix_transposition(t_matrix *matrix, const t_matrix *m);
double		get_2x2_determinant(const t_matrix *a);
double		*get_matrix(const t_matrix *m);
void		get_submatrix(t_matrix *matrix, const t_matrix *m, int row,
				int col);
double		get_minor(const t_matrix *m, int row, int col);
double		get_cofactor(const t_matrix *m, int row, int col);
double		matrix_determinant(const t_matrix *m);
bool		is_invertible(const t_matrix *m);
void		inverse_matrix(t_matrix *matrix, const t_matrix *m);

#endif
