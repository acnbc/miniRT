/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_normals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:45:30 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 00:30:39 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	test_normals(void)
{
	t_object	sphere;
	t_matrix	p;
	t_matrix	n;
	t_matrix	expected;
	t_sphere	object_sphere;

	printf("\n================ NORMALS DEBUG ================\n");

	sphere.id = sp;
	default_material(&sphere.material);
	sphere.material.color = (t_tuple){{.r = 200, .g = 0, .b = 200}};
	init_identity_matrix(&sphere.coord, 4);
	object_sphere.diameter = 2; // Raio 1
	sphere.object.sphere = &object_sphere;
	sphere.object.plane = NULL;
	sphere.object.cylinder = NULL;

	// Cenário 1: Normal na esfera num ponto no eixo X
	init_point(&p, 1, 0, 0);
	normal_at(&n, &sphere, &p); // Função a ser criada
	init_vector(&expected, 1, 0, 0);
	if (matrix_comparison(&n, &expected))
		printf("OK: Normal no eixo X\n");
	else
		printf("KO: Normal no eixo X\n");

	// Cenário 2: Normal na esfera num ponto no eixo Y
	init_point(&p, 0, 1, 0);
	normal_at(&n, &sphere, &p);
	init_vector(&expected, 0, 1, 0);
	if (matrix_comparison(&n, &expected))
		printf("OK: Normal no eixo Y\n");
	else
		printf("KO: Normal no eixo Y\n");

	// Cenário 3: Normal na esfera num ponto no eixo Z
	init_point(&p, 0, 0, 1);
	normal_at(&n, &sphere, &p);
	init_vector(&expected, 0, 0, 1);
	if (matrix_comparison(&n, &expected))
		printf("OK: Normal no eixo Z\n");
	else
		printf("KO: Normal no eixo Z\n");

	// Cenário 4: Normal num ponto não axial
	double val = sqrt(3) / 3;
	init_point(&p, val, val, val);
	normal_at(&n, &sphere, &p);
	init_vector(&expected, val, val, val);
	if (matrix_comparison(&n, &expected))
		printf("OK: Normal em ponto nao axial\n");
	else
		printf("KO: Normal em ponto nao axial\n");

	// Cenário 5: A normal deve ser sempre um vetor normalizado
	t_matrix normalized_n;
	vector_normalization(&normalized_n, &n);
	if (matrix_comparison(&n, &normalized_n))
		printf("OK: A normal e um vetor normalizado\n");
	else
		printf("KO: A normal e um vetor normalizado\n");

	// Cenário 6: Calcular a normal numa esfera transladada
	t_matrix	offset;
	init_identity_matrix(&sphere.coord, 4);
	init_point(&offset, 0, 1, 0);
	translation(&sphere.coord, &offset);
	init_point(&p, 0, 1.70711, -0.70711);
	normal_at(&n, &sphere, &p);
	init_vector(&expected, 0, 0.70711, -0.70711);
	// Verificar se matrix_comparison aprova (lembra-te da margem de erro EPSILON)
	if (matrix_comparison(&n, &expected))
		printf("OK: Normal de esfera transladada\n");
	else
		printf("KO: Normal de esfera transladada\n");

	// Cenário 7: Calcular a normal numa esfera transformada (Escala + Rotação)
	t_matrix	scaling_m;
	t_matrix	rotation_m;
	t_matrix	matrix;

	init_identity_matrix(&sphere.coord, 4);
	init_point(&offset, 1, 0.5, 1);
	scaling(&scaling_m, &offset);
	z_axis_rotation(&rotation_m, M_PI / 5);
	matrix_multiplication(&matrix, &rotation_m, &scaling_m);
	matrix_transposition(&sphere.coord, &matrix);

	init_point(&p, 0, sqrt(2)/2, -sqrt(2)/2);
	normal_at(&n, &sphere, &p);
	init_vector(&expected, 0, 0.97014, -0.24254);
	if (matrix_comparison(&n, &expected))
		printf("OK: Normal de esfera transformada (escala + rotacao)\n");
	else
		printf("KO: Normal de esfera transformada (escala + rotacao)\n");
}
