/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:38:20 by anogueir          #+#    #+#             */
/*   Updated: 2026/02/15 07:32:31 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void    print_tuples(t_tuple tuple)
{
    printf("Tuple:\n\tx = %.2f\n\ty = %.2f\n\tz = %.2f\n", tuple.x, tuple.y, tuple.z);
    if (tuple.is_point)
        printf("The tuple is a point\n");
    else
        printf("The tuple is a vector\n");
}

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
    t_matrix *result = matrix_multiplication(&matrix_c, &matrix_d);
    printf("Resultado:\n");
    print_matrix(result);
    printf("Matriz esperada:\n");
    print_matrix(&matrix_r);
    if (matrix_comparison(result, &matrix_r)) {
        printf("\n✓ Multiplicação correta!\n");
    } else {
        printf("\n✗ multiplicação incorreta!\n");
    }
    printf("Matriz e:\n");
    print_one_col_matrix(&matrix_e);
    printf("Matriz f:\n");
    print_matrix(&matrix_f);    
    result = matrix_tuple_multiplication(&matrix_f, &matrix_e);
    printf("Resultado:\n");
    print_one_col_matrix(result);
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
    
    t_matrix *result = matrix_transposition(&original);
    
    printf("/ ============= TESTE DE TRANSPOSIÇÃO ====================== /:\n");
	printf("Original:\n");
    print_matrix(&original);
    
    printf("\nTransposta:\n");
    print_matrix(result);
    
    printf("\nEsperada:\n");
    print_matrix(&expected);
    
    if (matrix_comparison(result, &expected)) {
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

    t_matrix    *id = create_identity_matrix(4);

    printf("Matriz identidade:\n");
    print_matrix(id);
    printf("Matriz a:\n");
    print_matrix(&matrix_a); 
    printf("Matriz b:\n");
    print_one_col_matrix(&matrix_b);

    t_matrix *result = matrix_multiplication(&matrix_a, id);
    if (matrix_comparison(result, &matrix_a)) {
        printf("\n✓ Multiplicação por matriz identidade correta!\n");
    } else {
        printf("\n✗ Multiplicação por matriz identidade incorreta!\n");
    }
    result = matrix_tuple_multiplication(id, &matrix_b);
    printf("Multiplicação de matriz de uma coluna:\n");
    print_one_col_matrix(result);    
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
    
    t_matrix    *result_a;
    t_matrix    *result_b;
    
    result_a = get_submatrix(&a, 0, 2);

    printf("result_a:\n");
    print_matrix(result_a);
    printf("sub_a:\n");
    print_matrix(&sub_a);
    if (matrix_comparison(result_a, &sub_a))
        printf("Correct submatrix\n");
    else
        printf("Incorrect submatrix\n");

    result_b = get_submatrix(&b, 2, 1);

    printf("result_b:\n");
    print_matrix(result_b);
    printf("sub_b:\n");
    print_matrix(&sub_b);
    
    if (matrix_comparison(result_b, &sub_b))
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

    double  result;

    result = get_minor(&a, 1, 0);

    if (is_equal(result, expected))
        printf("Menor obtido corretamente = %.2f\n", result);
    else
        printf("Menor incorreto\n");
    printf("Cofactor %.2f\n", get_cofactor(&a, 1, 0));
}

// ============================================
// Helper para criar matrizes
// ============================================
static t_matrix* create_test_matrix(int rows, int cols, double *values)
{
    t_matrix *m = creat_new_matrix(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        m->m_4x4[i] = values[i];  // Usamos m_4x4 pois é o maior array
    }
    return m;
}
    
    
void test_final_determinant(void)
{
    printf("=== TESTANDO DETERMINANTES (com nova estrutura) ===\n\n");
    
    // ============================================
    // Teste 1: Matriz 2x2
    // ============================================
    printf("Teste 1: Matriz 2x2\n");
    double vals2[] = {1, 2, 3, 4};
    t_matrix *m2x2 = create_test_matrix(2, 2, vals2);
    
    double det2 = matrix_determinant(m2x2);
    double expected2 = 1*4 - 2*3;  // -2
    printf("  Calculado: %f\n", det2);
    printf("  Esperado:  %f\n", expected2);
    printf("  Resultado: %s\n\n", fabs(det2 - expected2) < EPSILON ? "✓ OK" : "✗ FALHOU");
    
    free_matrix(m2x2);
    
    // ============================================
    // Teste 2: Matriz 3x3 (determinante zero)
    // ============================================
    printf("Teste 2: Matriz 3x3 (deve ser 0)\n");
    double vals3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    t_matrix *m3x3 = create_test_matrix(3, 3, vals3);
    
    double det3 = matrix_determinant(m3x3);
    printf("  Calculado: %f\n", det3);
    printf("  Esperado:  0.0\n");
    printf("  Resultado: %s\n\n", fabs(det3) < EPSILON ? "✓ OK" : "✗ FALHOU");
    
    free_matrix(m3x3);
    
    // ============================================
    // Teste 3: Matriz 3x3 (não singular)
    // ============================================
    printf("Teste 3: Matriz 3x3 (não singular)\n");
    double vals3b[] = {2, -3, 1, 2, 0, -1, 1, 4, 5};
    t_matrix *m3x3b = create_test_matrix(3, 3, vals3b);
    
    double det3b = matrix_determinant(m3x3b);
    double expected3b = 49.0;
    printf("  Calculado: %f\n", det3b);
    printf("  Esperado:  %f\n", expected3b);
    printf("  Resultado: %s\n\n", fabs(det3b - expected3b) < EPSILON ? "✓ OK" : "✗ FALHOU");
    
    free_matrix(m3x3b);
    
    // ============================================
    // Teste 4: Matriz 4x4 (do livro The Ray Tracer Challenge)
    // ============================================
    printf("Teste 4: Matriz 4x4\n");
    double vals4[] = {
        -2, -8,  3,  5,
        -3,  1,  7,  3,
         1,  2, -9,  6,
        -6,  7,  7, -9
    };
    t_matrix *m4x4 = create_test_matrix(4, 4, vals4);
    
    double det4 = matrix_determinant(m4x4);
    double expected4 = -4071.0;
    printf("  Calculado: %f\n", det4);
    printf("  Esperado:  %f\n", expected4);
    printf("  Resultado: %s\n\n", fabs(det4 - expected4) < EPSILON ? "✓ OK" : "✗ FALHOU");
    
    free_matrix(m4x4);
    
    // ============================================
    // Teste 5: Matriz identidade 4x4
    // ============================================
    printf("Teste 5: Matriz identidade 4x4\n");
    t_matrix *identity = create_identity_matrix(4);
    
    double det_id = matrix_determinant(identity);
    printf("  Calculado: %f\n", det_id);
    printf("  Esperado:  1.0\n");
    printf("  Resultado: %s\n\n", fabs(det_id - 1.0) < EPSILON ? "✓ OK" : "✗ FALHOU");
    
    free_matrix(identity);
    
    // ============================================
    // Teste 6: Matriz 4x4 com translação (deve ter det = 1)
    // ============================================
    printf("Teste 6: Matriz de translação 4x4\n");
    t_matrix *translation = create_identity_matrix(4);
    mat_set(translation, 0, 3, 5.0);   // tx = 5
    mat_set(translation, 1, 3, -3.0);  // ty = -3
    mat_set(translation, 2, 3, 2.0);   // tz = 2
    
    double det_trans = matrix_determinant(translation);
    printf("  Calculado: %f\n", det_trans);
    printf("  Esperado:  1.0 (matriz de translação preserva volume)\n");
    printf("  Resultado: %s\n\n", fabs(det_trans - 1.0) < EPSILON ? "✓ OK" : "✗ FALHOU");
    
    free_matrix(translation);
    
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

    t_matrix    *result;

    result = inverse_matrix(&a);

    if (matrix_comparison(result, &b))
        printf("Matriz inversa gerada corretamente\n");
    else
        printf("Matriz inversa gerada incorretamente\n");

    result = inverse_matrix(&c);

    if (matrix_comparison(result, &d))
        printf("Matriz inversa gerada corretamente\n");
    else
        printf("Matriz inversa gerada incorretamente\n");

    result = inverse_matrix(&e);

    if (matrix_comparison(result, &f))
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


    t_matrix    *result;

    t_matrix    *revert;

    t_matrix    *result_final;

    result = matrix_multiplication(&a, &b);

    print_matrix(result);

    revert = inverse_matrix(&b);

    result_final = matrix_multiplication(result, revert);

    if (matrix_comparison(result_final, &a))
        printf("Reversão da multiplicação correta\n");
    else
        printf("Reversão da multiplicação incorreta\n");

}
