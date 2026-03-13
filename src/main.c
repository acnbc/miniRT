/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:11:15 by jessica           #+#    #+#             */
/*   Updated: 2026/03/13 15:33:01 by anogueir         ###   ########.fr       */
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
	return (0);
}
