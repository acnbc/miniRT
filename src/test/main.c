/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 07:53:08 by jessica           #+#    #+#             */
/*   Updated: 2026/03/24 03:04:01 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	tester(t_scene *scene)
{
	print_scene(scene);
	test_matrix_comparison();
	test_matrix_multiplication();
	test_transposition();
	test_mult_matrix_id();
	test_submatrix();
	test_minor();
	test_final_determinant();
	test_is_invertible();
	test_inverse_matrix_basic();
	test_mult_inverse_product();
	test_translation();
	test_scaling();
	test_rotation();
	test_rotation_y_axis();
	test_rotation_z_axis();
	test_chapter5();
}
