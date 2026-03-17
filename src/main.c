/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:11:15 by jessica           #+#    #+#             */
/*   Updated: 2026/03/16 23:20:47 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	main(void)
{
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
	test_transformations();
	test_ray_intersect();
	test_cap_5();
	return (0);
}
