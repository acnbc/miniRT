/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:08:22 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/13 15:09:10 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# include <math.h>
# define EPSILON 0.00001

t_matrix	*add_tuples(t_matrix *a, t_matrix *b);
t_matrix	*subtract_tuple(t_matrix *a, t_matrix *b);
t_matrix	*negate_tuple(t_matrix *tuple);
t_matrix	*scalar_multiplication(t_matrix *tuple, double scalar);
t_matrix	*scalar_division(t_matrix *tuple, double scalar);
double		vector_magnitude(t_matrix *tuple);
t_matrix	*vector_normalization(t_matrix *vector);
double		dot_product(t_matrix *a, t_matrix *b);
t_matrix	*cross_product(t_matrix *a, t_matrix *b);

t_matrix	*create_point(double x, double y, double z);
t_matrix	*create_vector(double x, double y, double z);
bool		is_equal(double a, double b);

double		mat_get(t_matrix *m, int row, int col);
void		mat_set(t_matrix *m, int row, int col, double value);
t_matrix	*matrix_multiplication(t_matrix *a, t_matrix *b);
t_matrix	*matrix_tuple_multiplication(t_matrix *a, t_matrix *b);
bool		matrix_comparison(t_matrix *a, t_matrix *b);
t_matrix	*matrix_transposition(t_matrix *m);
t_matrix	*create_identity_matrix(int dim);
double		get_2x2_determinant(t_matrix *a);
double		*get_matrix(t_matrix *m);
t_matrix	*creat_new_matrix(int rows, int cols);
t_matrix	*get_submatrix(t_matrix *m, int row, int col);
double		get_minor(t_matrix *m, int row, int col);
double		get_cofactor(t_matrix *m, int row, int col);
double		matrix_determinant(t_matrix *m);
bool		is_invertible(t_matrix *m);
t_matrix	*inverse_matrix(t_matrix *m);

#endif