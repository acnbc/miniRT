/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:39:05 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/24 02:52:38 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

/* FUNÇÃO PRINCIPAL DE TESTE */
void	tester(t_scene *scene);

void	print_matrix(const t_matrix *matrix);
void	print_one_col_matrix(const t_matrix *matrix);
void	test_matrix_comparison(void);
void	test_matrix_multiplication(void);
void	test_transposition(void);
void	test_mult_matrix_id(void);
void	test_submatrix(void);
void	test_minor(void);
void	test_final_determinant(void);
void	test_is_invertible(void);
void	test_inverse_matrix_basic(void);
void	test_muilt_inverse_product(void);
void	test_transformations(void);
void	test_ray_intersect(void);
void	test_cap_5(void);
void	test_mult_inverse_product(void);
void	test_translation(void);
void	test_scaling(void);
void	test_rotation(void);
void	test_rotation_y_axis(void);
void	test_rotation_z_axis(void);
void	test_chapter5(void);

void	print_scene(t_scene *scene);

#endif
