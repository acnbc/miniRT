/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 07:53:08 by jessica           #+#    #+#             */
/*   Updated: 2026/02/16 20:22:35 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	tester(t_scene *scene)
{
	print_scene(scene);
	test_matrix_comparison();
	test_matrix_multiplication();
	test_transposition();
	test_mult_matrix_id();
	test_determinant();
	test_submatrix();
	test_minor();
	test_final_determinant();
	test_is_invertible();
	test_inverse_matrix_basic();
	test_muilt_inverse_product();
}
