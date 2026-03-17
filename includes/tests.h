/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:39:05 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/16 23:15:31 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

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
void	test_ray_intersect(void);
void	test_cap_5(void);

#endif
