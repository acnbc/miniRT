/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 07:53:08 by jessica           #+#    #+#             */
/*   Updated: 2026/04/04 01:29:52 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	tester(t_scene *scene)
{
	draw_test_3d_sphere(scene);
	// print_scene(scene);
	// test_matrix_comparison();
	// test_matrix_multiplication();
	// test_transposition();
	// test_mult_matrix_id();
	// test_submatrix();
	// test_minor();
	// test_final_determinant();
	// test_is_invertible();
	// test_inverse_matrix_basic();
	// test_mult_inverse_product();
	// test_translation();
	// test_scaling();
	//test_rotation();
	//test_rotation_y_axis();
	//test_rotation_z_axis();
	test_chapter5();
	test_normals();
	test_reflection();
	// test_lighting(); // depreciado
}
