/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:39:05 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/17 23:41:07 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

/* FUNÇÃO PRINCIPAL DE TESTE */
void	tester(t_scene *scene);

void	print_matrix(t_matrix *matrix);
void	print_one_col_matrix(t_matrix *matrix);
void	test_matrix_comparison(void);
void	test_matrix_multiplication(void);
void	test_transposition(void);
void	test_mult_matrix_id(void);
void	test_determinant(void);
void	test_submatrix(void);
void	test_minor(void);
void	test_final_determinant(void);
void	test_is_invertible(void);
void	test_inverse_matrix_basic(void);
void	test_muilt_inverse_product(void);
void	test_transformations(void);

void	print_scene(t_scene *scene);

#endif