/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:38:20 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/21 12:52:54 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void    print_matrix(t_matrix *matrix)
{
    int i;
    int dimension;
    int row = 0;
    int col = 0;
    double  *ptr;

    i = -1;
    dimension = matrix->rows * matrix->cols;
    ptr = get_matrix(matrix);
    while (++i < dimension)
    {
        row = i / matrix->rows;
        col = i % matrix->rows;
        printf("m[%d][%d] = %8.2f\n", row, col, ptr[i]);
    }
}

void    print_one_col_matrix(t_matrix *matrix)
{
    int i;
    double  *ptr;
    
    i = -1;
    ptr = get_matrix(matrix);
    while (++i < matrix->rows * matrix->cols)
    {
        printf("m[%d] = %8.2f\n", i, ptr[i]);
    }
}

void    test_matrix_comparison(void)
{
    t_matrix	matrix_a = {
    	.m_4x4 = 
    	{
    	    1.0, 2.0, 3.0, 4.0,
    	    5.5, 6.5, 7.5, 8.5,
    	    9.0, 10.0, 11.0, 12.0,
    	    13.5, 14.5, 15.5, 16.5
    	},
        .rows = 4,
        .cols = 4
    };

    t_matrix	matrix_b = {
    	.m_4x4 =
    	{
    		1, 2, 3, 4,
    		5, 6, 7, 8,
    		9, 8, 7, 6,
    		5, 4, 3, 2
    	},
        .rows = 4,
        .cols = 4
    };

    t_matrix	matrix_c = {
    	.m_4x4 =
    	{
    		1, 2, 3, 4,
    		5, 6, 7, 8,
    		9, 8, 7, 6,
    		5, 4, 3, 2
    	},
        .rows = 4,
        .cols = 4
    };

    bool result;
	printf("/ ============= TESTE DE COMPARAÇÃO ====================== /:\n");
	printf("Matriz a:\n");
    print_matrix(&matrix_a);
    printf("Matriz b:\n");
    print_matrix(&matrix_b);
    printf("Matriz c:\n");
    print_matrix(&matrix_c);
	result = matrix_comparison(&matrix_b, &matrix_c);
    printf("Resultado Teste 2: %s\n", result ? "true" : "false");
	result = matrix_comparison(&matrix_a, &matrix_c);
    printf("Resultado Teste 2: %s\n", result ? "true" : "false");
}

void    test_matrix_multiplication(void)
{
    t_matrix	matrix_c = {
    	.m_4x4 =
    	{
    		1, 2, 3, 4,
    		5, 6, 7, 8,
    		9, 8, 7, 6,
    		5, 4, 3, 2
    	},
        .rows = 4,
        .cols = 4
    };

    t_matrix	matrix_d = {
    	.m_4x4 =
    	{
    		-2, 1, 2, 3,
    		3, 2, 1, -1,
    		4, 3, 6, 5,
    		1, 2, 7, 8
    	},
        .rows = 4,
        .cols = 4
    };

    t_matrix	matrix_r = {
    	.m_4x4 =
    	{
            20, 22, 50, 48,
            44, 54, 114, 108,
            40, 58, 110, 102,
            16, 26, 46, 42
    	},
        .rows = 4,
        .cols = 4
    };

    t_matrix	matrix_e = {
    	.m_4x1 = {1, 2, 3, 1},
        .rows = 4,
        .cols = 1
    };

    t_matrix	matrix_f = {
    	.m_4x4 =
    	{
    		1, 2, 3, 4,
    		2, 4, 4, 2,
    		8, 6, 4, 1,
    		0, 0, 0, 1
    	},
        .rows = 4,
        .cols = 4
    };

    t_matrix	matrix_re = {
    	.m_4x1 = {18, 24, 33, 1},
        .rows = 4,
        .cols = 1
    };
    
    printf("/ ============= TESTE DE MULTIPLICAÇÃO ====================== /:\n");
	printf("Matriz c:\n");
    print_matrix(&matrix_c);
    printf("Matriz d:\n");
    print_matrix(&matrix_d);
    t_matrix result;
    matrix_multiplication(&matrix_c, &matrix_d, &result);
    printf("Resultado:\n");
    print_matrix(&result);
    printf("Matriz esperada:\n");
    print_matrix(&matrix_r);
    if (matrix_comparison(&result, &matrix_r)) {
        printf("\n✓ Multiplicação correta!\n");
    } else {
        printf("\n✗ multiplicação incorreta!\n");
    }
    printf("Matriz e:\n");
    print_one_col_matrix(&matrix_e);
    printf("Matriz f:\n");
    print_matrix(&matrix_f);    
    matrix_tuple_multiplication(&matrix_f, &matrix_e, &result);
    printf("Resultado:\n");
    print_one_col_matrix(&result);
    printf("Esperado:\n");
    print_one_col_matrix(&matrix_re);
}

void    test_transposition(void)
{
    t_matrix original = {
        .m_4x4 = {
            0, 9, 3, 0,
            9, 8, 0, 8,
            1, 8, 5, 3,
            0, 0, 5, 8
        },
        .rows = 4,
        .cols = 4
    };
    
    t_matrix expected = {
        .m_4x4 = {
            0, 9, 1, 0,
            9, 8, 8, 0,
            3, 0, 5, 5,
            0, 8, 3, 8
        },
        .rows = 4,
        .cols = 4
    };
    
    t_matrix result;
    matrix_transposition(&original, &result);
    printf("/ ============= TESTE DE TRANSPOSIÇÃO ====================== /:\n");
	printf("Original:\n");
    print_matrix(&original);
    printf("\nTransposta:\n");
    print_matrix(&result);
    printf("\nEsperada:\n");
    print_matrix(&expected);
    if (matrix_comparison(&result, &expected)) {
        printf("\n✓ Transposição correta!\n");
    } else {
        printf("\n✗ Transposição incorreta!\n");
    }
}

void    test_mult_matrix_id(void)
{
    t_matrix	matrix_a = {
    	.m_4x4 =
    	{
    		1, 2, 3, 4,
    		5, 6, 7, 8,
    		9, 8, 7, 6,
    		5, 4, 3, 2
    	},
        .rows = 4,
        .cols = 4
    };

    t_matrix	matrix_b = {
    	.m_4x1 = {1, 2, 3, 1},
        .rows = 4,
        .cols = 1
    };

    t_matrix	id;
    t_matrix	result;

    init_identity_matrix(&id, 4);
    printf("Matriz identidade:\n");
    print_matrix(&id);
    printf("Matriz a:\n");
    print_matrix(&matrix_a);
    printf("Matriz b:\n");
    print_one_col_matrix(&matrix_b);
    matrix_multiplication(&matrix_a, &id, &result);
    if (matrix_comparison(&result, &matrix_a))
        printf("\n✓ Multiplicação por matriz identidade correta!\n");
    else
        printf("\n✗ Multiplicação por matriz identidade incorreta!\n");
    matrix_tuple_multiplication(&id, &matrix_b, &result);
    printf("Multiplicação de matriz de uma coluna:\n");
    print_one_col_matrix(&result);
}

void    test_determinant(void)
{
    t_matrix    a = {
        .m_2x2= {
            1, 5,
            -3, 2
        },
        .rows = 2,
        .cols = 2
    };
    
    double  result;
    double  expected = 17;

    result = get_2x2_determinant(&a);
    printf("result %.2f\n", result);
    
    if (is_equal(result, expected))
        printf("✓ Determinante de matriz 2x2 correto\n");
    else
        printf("✗ Determinante de matriz 2x2 incorreto\n");
}

void    test_submatrix(void)
{
    t_matrix	a = {
    	.m_3x3 =
    	{
    		1, 5, 0,
            -3, 2, 7,
            0, 6, -3
    	},
        .rows = 3,
        .cols = 3
    };

    t_matrix    sub_a = {
        .m_2x2= {
            -3, 2,
            0, 6
        },
        .rows = 2,
        .cols = 2
    };
    
    t_matrix	b = {
    	.m_4x4 =
    	{
    		-6, 1, 1, 6,
            -8, 5, 8, 6,
            -1, 0, 8, 2,
            -7, 1, -1, 1
        },
        .rows = 4,
        .cols = 4
    };

    t_matrix    sub_b = {
        .m_3x3= {
            -6, 1, 6,
            -8, 8, 6,
            -7, -1, 1
        },
        .rows = 3,
        .cols = 3
    };
    
    t_matrix	result_a;
    t_matrix	result_b;

    get_submatrix(&a, 0, 2, &result_a);
    printf("result_a:\n");
    print_matrix(&result_a);
    printf("sub_a:\n");
    print_matrix(&sub_a);
    if (matrix_comparison(&result_a, &sub_a))
        printf("Correct submatrix\n");
    else
        printf("Incorrect submatrix\n");
    get_submatrix(&b, 2, 1, &result_b);
    printf("result_b:\n");
    print_matrix(&result_b);
    printf("sub_b:\n");
    print_matrix(&sub_b);
    if (matrix_comparison(&result_b, &sub_b))
		printf("Correct submatrix\n");
    else
		printf("Incorrect submatrix\n");
}

void    test_minor(void)
{
    t_matrix	a = {
    	.m_3x3 =
    	{
    		3, 5,   0,
            2, -1, -7,
            6, -1, 5
    	},
        .rows = 3,
        .cols = 3
    };

    double  expected = 25;

    double	result;
    t_matrix	s1;
    t_matrix	s2;

    result = get_minor(&a, 1, 0, &s1, &s2);
    if (is_equal(result, expected))
        printf("Menor obtido corretamente = %.2f\n", result);
    else
        printf("Menor incorreto\n");
    printf("Cofactor %.2f\n", get_cofactor(&a, 1, 0, &s1, &s2));
}

// ============================================
// Helper para criar matrizes
// ============================================
static void	init_test_matrix(t_matrix *out, int rows, int cols, double *values)
{
	int	i;

	init_matrix(out, rows, cols);
	i = 0;
	while (i < rows * cols)
	{
		out->m_4x4[i] = values[i];
		i++;
	}
}
    
    
void test_final_determinant(void)
{
    printf("=== TESTANDO DETERMINANTES (com nova estrutura) ===\n\n");
    
    // ============================================
    // Teste 1: Matriz 2x2
    // ============================================
    printf("Teste 1: Matriz 2x2\n");
    double vals2[] = {1, 2, 3, 4};
    t_matrix m2x2;
    init_test_matrix(&m2x2, 2, 2, vals2);
    double det2 = matrix_determinant(&m2x2);
    double expected2 = 1*4 - 2*3;
    printf("  Calculado: %f\n", det2);
    printf("  Esperado:  %f\n", expected2);
    printf("  Resultado: %s\n\n", fabs(det2 - expected2) < EPSILON ? "✓ OK" : "✗ FALHOU");
    printf("Teste 2: Matriz 3x3 (deve ser 0)\n");
    double vals3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    t_matrix m3x3;
    init_test_matrix(&m3x3, 3, 3, vals3);
    double det3 = matrix_determinant(&m3x3);
    printf("  Calculado: %f\n", det3);
    printf("  Esperado:  0.0\n");
    printf("  Resultado: %s\n\n", fabs(det3) < EPSILON ? "✓ OK" : "✗ FALHOU");
    printf("Teste 3: Matriz 3x3 (não singular)\n");
    double vals3b[] = {2, -3, 1, 2, 0, -1, 1, 4, 5};
    t_matrix m3x3b;
    init_test_matrix(&m3x3b, 3, 3, vals3b);
    double det3b = matrix_determinant(&m3x3b);
    double expected3b = 49.0;
    printf("  Calculado: %f\n", det3b);
    printf("  Esperado:  %f\n", expected3b);
    printf("  Resultado: %s\n\n", fabs(det3b - expected3b) < EPSILON ? "✓ OK" : "✗ FALHOU");
    printf("Teste 4: Matriz 4x4\n");
    double vals4[] = {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9};
    t_matrix m4x4;
    init_test_matrix(&m4x4, 4, 4, vals4);
    double det4 = matrix_determinant(&m4x4);
    double expected4 = -4071.0;
    printf("  Calculado: %f\n", det4);
    printf("  Esperado:  %f\n", expected4);
    printf("  Resultado: %s\n\n", fabs(det4 - expected4) < EPSILON ? "✓ OK" : "✗ FALHOU");
    printf("Teste 5: Matriz identidade 4x4\n");
    t_matrix identity;
    init_identity_matrix(&identity, 4);
    double det_id = matrix_determinant(&identity);
    printf("  Calculado: %f\n", det_id);
    printf("  Esperado:  1.0\n");
    printf("  Resultado: %s\n\n", fabs(det_id - 1.0) < EPSILON ? "✓ OK" : "✗ FALHOU");
    printf("Teste 6: Matriz de translação 4x4\n");
    t_matrix translation;
    init_identity_matrix(&translation, 4);
    mat_set(&translation, 0, 3, 5.0);
    mat_set(&translation, 1, 3, -3.0);
    mat_set(&translation, 2, 3, 2.0);
    double det_trans = matrix_determinant(&translation);
    printf("  Calculado: %f\n", det_trans);
    printf("  Esperado:  1.0 (matriz de translação preserva volume)\n");
    printf("  Resultado: %s\n\n", fabs(det_trans - 1.0) < EPSILON ? "✓ OK" : "✗ FALHOU");
    
    printf("=== FIM DOS TESTES ===\n");
}

void    test_is_invertible(void)
{
    t_matrix	a = {
    	.m_4x4 =
    	{
    		6, 4, 4, 4,
            5, 5, 7, 6,
            4, -9, 3, -7,
            9, 1, 7, -6
        },
        .rows = 4,
        .cols = 4
    }; 
    
    t_matrix	b = {
    	.m_4x4 =
    	{
    		-4, 2, -2, -3,
            9, 6, 2, 6,
            0, -5, 1, -5,
            0, 0, 0, 0
        },
        .rows = 4,
        .cols = 4
    };

    printf("Matriz a:\n");
    if (is_invertible(&a))
        printf("Matriz reversível\n");
    else
        printf("Matriz irreversível\n");
    printf("Matriz b:\n");
    if (is_invertible(&b))
        printf("Matriz reversível\n");
    else
        printf("Matriz irreversível\n");
}

void    test_inverse_matrix_basic(void)
{
    t_matrix	a = {
    	.m_4x4 =
    	{
            -5, 2, 6, -8,
            1, -5, 1, 8,
            7, 7, -6, -7,
            1, -3, 7, 4
        },
        .rows = 4,
        .cols = 4
    };

        t_matrix	b = {
    	.m_4x4 =
    	{
            0.21805, 0.45113, 0.24060, -0.04511,
            -0.80827, -1.45677, -0.44361, 0.52068,
            -0.07895, -0.22368, -0.05263, 0.19737,
            -0.52256, -0.81391, -0.30075, 0.30639
        },
        .rows = 4,
        .cols = 4
    };

    t_matrix	c = {
    	.m_4x4 =
    	{
            8, -5, 9, 2,
            7, 5, 6, 1,
            -6, 0, 9, 6,
            -3, 0, -9, -4
        },
        .rows = 4,
        .cols = 4
    };

    t_matrix	d = {
    	.m_4x4 =
    	{
            -0.15385, -0.15385, -0.28205, -0.53846,
            -0.07692, 0.12308, 0.02564, 0.03077,
            0.35897, 0.35897, 0.43590, 0.92308,
            -0.69231, -0.69231, -0.76923, -1.92308
        },
        .rows = 4,
        .cols = 4
    };

    t_matrix	e = {
    	.m_4x4 =
    	{
            9, 3, 0, 9,
            -5, -2, -6, -3,
            -4, 9, 6, 4,
            -7, 6, 6, 2
        },
        .rows = 4,
        .cols = 4
    }; 

    t_matrix	f = {
    	.m_4x4 =
    	{
            -0.04074, -0.07778, 0.14444, -0.22222,
            -0.07778, 0.03333, 0.36667, -0.33333,
            -0.02901, -0.14630, -0.10926, 0.12963,
            0.17778, 0.06667, -0.26667, 0.33333
        },
        .rows = 4,
        .cols = 4
    }; 

    t_matrix	result;

    inverse_matrix(&a, &result);
    if (matrix_comparison(&result, &b))
		printf("Matriz inversa gerada corretamente\n");
    else
		printf("Matriz inversa gerada incorretamente\n");
    inverse_matrix(&c, &result);
    if (matrix_comparison(&result, &d))
		printf("Matriz inversa gerada corretamente\n");
    else
		printf("Matriz inversa gerada incorretamente\n");
    inverse_matrix(&e, &result);
    if (matrix_comparison(&result, &f))
		printf("Matriz inversa gerada corretamente\n");
    else
		printf("Matriz inversa gerada incorretamente\n");
}

void    test_muilt_inverse_product(void)
{
    t_matrix	a = {
    	.m_4x4 =
    	{
            -5, 2, 6, -8,
            1, -5, 1, 8,
            7, 7, -6, -7,
            1, -3, 7, 4
        },
        .rows = 4,
        .cols = 4
    };

        t_matrix	b = {
    	.m_4x4 =
    	{
            8, -5, 9, 2,
            7, 5, 6, 1,
            -6, 0, 9, 6,
            -3, 0, -9, -4
        },
        .rows = 4,
        .cols = 4
    };


    t_matrix	result;
    t_matrix	revert;
    t_matrix	result_final;

    matrix_multiplication(&a, &b, &result);
    inverse_matrix(&b, &revert);
    matrix_multiplication(&result, &revert, &result_final);
    if (matrix_comparison(&result_final, &a))
		printf("Reversão da multiplicação correta\n");
    else
		printf("Reversão da multiplicação incorreta\n");
}

void	test_translation(void)
{
	t_matrix	offset;
	t_matrix	transform;
	t_matrix	point_m;
	t_matrix	expected;
	t_matrix	result;
	t_matrix	inversa;
	t_matrix	point_mi;
	t_matrix	expectedi;

	init_point(&offset, 5.0, -3.0, 2.0);
	translation(&offset, &transform);
	init_point(&point_m, -3.0, 4.0, 5.0);
	init_point(&expected, 2.0, 1.0, 7.0);
	printf("\n=== Translação: multiplicação por matriz de translação ===\n");
	matrix_tuple_multiplication(&transform, &point_m, &result);
	if (matrix_comparison(&result, &expected))
		printf("Translação correta\n");
	else
		printf("Translação incorreta\n");
	inverse_matrix(&transform, &inversa);
	init_point(&point_mi, -3.0, 4.0, 5.0);
	init_point(&expectedi, -8.0, 7.0, 3.0);
	printf("\n=== Translação: multiplicação por inversa da matriz de translação ===\n");
	matrix_tuple_multiplication(&inversa, &point_mi, &result);
	if (matrix_comparison(&result, &expectedi))
		printf("Translação correta\n");
	else
		printf("Translação incorreta\n");
}

void	test_scaling(void)
{
	t_matrix	transform;
	t_matrix	result;
	t_matrix	expected;
	t_matrix	point;
	t_matrix	offset;
	t_matrix	vector;
	t_matrix	inversa;

	init_point(&expected, -8, 18, 32);
	init_point(&offset, 2, 3, 4);
	scaling(&offset, &transform);
	init_point(&point, -4, 6, 8);
	matrix_tuple_multiplication(&transform, &point, &result);
	printf("\n=== Scaling: point ===\n");
	if (matrix_comparison(&result, &expected))
		printf("Scaling com ponto correta\n");
	else
		printf("Scaling com ponto incorreta\n");
	init_vector(&expected, -8, 18, 32);
	init_vector(&offset, 2, 3, 4);
	scaling(&offset, &transform);
	init_vector(&vector, -4, 6, 8);
	matrix_tuple_multiplication(&transform, &vector, &result);
	printf("\n=== Scaling: vector ===\n");
	if (matrix_comparison(&result, &expected))
		printf("Scaling com vector correta\n");
	else
		printf("Scaling com vector incorreta\n");
	init_vector(&expected, -2, 2, 2);
	scaling(&offset, &transform);
	inverse_matrix(&transform, &inversa);
	matrix_tuple_multiplication(&inversa, &vector, &result);
	printf("\n=== Scaling: vector ===\n");
	if (matrix_comparison(&result, &expected))
		printf("Scaling com inversa e vector correta\n");
	else
		printf("Scaling com inversa vector incorreta\n");
}

void	test_rotation(void)
{
	t_matrix	point;
	t_matrix	expected_half;
	t_matrix	expected_full;
	t_matrix	half_quarter;
	t_matrix	full_quarter;
	t_matrix	half_result;
	t_matrix	full_result;
	t_matrix	inverted;
	t_matrix	result_inverted;
	t_matrix	expected_inverted;

	init_point(&point, 0, 1, 0);
	init_point(&expected_half, 0, M_SQRT2 / 2, M_SQRT2 / 2);
	init_point(&expected_full, 0, 0, 1);
	x_axis_rotation(M_PI_4, &half_quarter);
	x_axis_rotation(M_PI_2, &full_quarter);
	inverse_matrix(&half_quarter, &inverted);
	init_point(&expected_inverted, 0, M_SQRT2 / 2, -M_SQRT2 / 2);
	matrix_tuple_multiplication(&half_quarter, &point, &half_result);
	matrix_tuple_multiplication(&full_quarter, &point, &full_result);
	matrix_tuple_multiplication(&inverted, &point, &result_inverted);
	printf("\n=== Rotação no eixo x: half quarter ===\n");
	if (matrix_comparison(&half_result, &expected_half))
		printf("Rotação correta\n");
	else
		printf("Rotação incorreta\n");
	printf("\n=== Rotação no eixo x: invertida ===\n");
	if (matrix_comparison(&result_inverted, &expected_inverted))
		printf("Rotação correta\n");
	else
		printf("Rotação incorreta\n");
	printf("\n=== Rotação no eixo x: half quarter ===\n");
	if (matrix_comparison(&full_result, &expected_full))
		printf("\nRotação correta\n");
	else
		printf("\nRotação incorreta\n");
}

void	test_rotation_y_axis(void)
{
	t_matrix	point;
	t_matrix	expected_half;
	t_matrix	expected_full;
	t_matrix	half_quarter;
	t_matrix	full_quarter;
	t_matrix	half_result;
	t_matrix	full_result;
	t_matrix	inverted;
	t_matrix	result_inverted;
	t_matrix	expected_inverted;

	init_point(&point, 0, 0, 1);
	init_point(&expected_half, M_SQRT2 / 2, 0, M_SQRT2 / 2);
	init_point(&expected_full, 1, 0, 0);
	y_axis_rotation(M_PI_4, &half_quarter);
	y_axis_rotation(M_PI_2, &full_quarter);
	inverse_matrix(&half_quarter, &inverted);
	init_point(&expected_inverted, -M_SQRT2 / 2, 0, M_SQRT2 / 2);
	matrix_tuple_multiplication(&half_quarter, &point, &half_result);
	matrix_tuple_multiplication(&full_quarter, &point, &full_result);
	matrix_tuple_multiplication(&inverted, &point, &result_inverted);
	printf("\n=== Rotação no eixo Y: half quarter ===\n");
	if (matrix_comparison(&half_result, &expected_half))
		printf("Rotação correta\n");
	else
		printf("Rotação incorreta\n");
	printf("\n=== Rotação no eixo Y: invertida ===\n");
	if (matrix_comparison(&result_inverted, &expected_inverted))
		printf("Rotação correta\n");
	else
		printf("Rotação incorreta\n");
	printf("\n=== Rotação no eixo Y: full quarter ===\n");
	if (matrix_comparison(&full_result, &expected_full))
		printf("Rotação correta\n");
	else
		printf("Rotação incorreta\n");
}

void	test_rotation_z_axis(void)
{
	t_matrix	point;
	t_matrix	expected_half;
	t_matrix	expected_full;
	t_matrix	half_quarter;
	t_matrix	full_quarter;
	t_matrix	half_result;
	t_matrix	full_result;
	t_matrix	inverted;
	t_matrix	result_inverted;
	t_matrix	expected_inverted;

	init_point(&point, 0, 1, 0);
	init_point(&expected_half, -M_SQRT2 / 2, M_SQRT2 / 2, 0);
	init_point(&expected_full, -1, 0, 0);
	z_axis_rotation(M_PI_4, &half_quarter);
	z_axis_rotation(M_PI_2, &full_quarter);
	inverse_matrix(&half_quarter, &inverted);
	init_point(&expected_inverted, M_SQRT2 / 2, M_SQRT2 / 2, 0);
	matrix_tuple_multiplication(&half_quarter, &point, &half_result);
	matrix_tuple_multiplication(&full_quarter, &point, &full_result);
	matrix_tuple_multiplication(&inverted, &point, &result_inverted);
	printf("\n=== Rotação no eixo Z: half quarter ===\n");
	if (matrix_comparison(&half_result, &expected_half))
		printf("Rotação correta\n");
	else
		printf("Rotação incorreta\n");
	printf("\n=== Rotação no eixo Z: invertida ===\n");
	if (matrix_comparison(&result_inverted, &expected_inverted))
		printf("Rotação correta\n");
	else
		printf("Rotação incorreta\n");
	printf("\n=== Rotação no eixo Z: full quarter ===\n");
	if (matrix_comparison(&full_result, &expected_full))
		printf("Rotação correta\n");
	else
		printf("Rotação incorreta\n");
}

