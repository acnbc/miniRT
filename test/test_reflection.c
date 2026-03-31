/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reflection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:50:55 by jessica           #+#    #+#             */
/*   Updated: 2026/03/28 22:42:47 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_reflection(void)
{
	t_matrix	v;
	t_matrix	n;
	t_matrix	r;
	t_matrix	expected;

	printf("\n================ REFLECION DEBUG ================\n");
	init_vector(&v, 1, -1, 0);
	init_vector(&n, 0, 1, 0);
	reflect(&r, &v, &n);
	init_vector(&expected, 1, 1, 0);
	if (matrix_comparison(&r, &expected))
		printf("OK: Reflexao a 45 graus\n");
	else
		printf("KO: Reflexao a 45 graus\n");
	init_vector(&v, 0, -1, 0);
	init_vector(&n, sqrt(2)/2, sqrt(2)/2, 0);
	reflect(&r, &v, &n);
	init_vector(&expected, 1, 0, 0);
	if (matrix_comparison(&r, &expected))
		printf("OK: Reflexao em superficie inclinada\n");
	else
		printf("KO: Reflexao em superficie inclinada\n");
}
