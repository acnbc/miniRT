/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:38:20 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/12 17:49:56 by anogueir         ###   ########.fr       */
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
        printf("\n✓ Multiplicaçã correta!\n");
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

void test_final_determinant(void)
{
    printf("=== TESTANDO DETERMINANTES (com nova estrutura) ===\n\n");
    
    // ============================================
    // Helper para criar matrizes
    // ============================================
    t_matrix* create_test_matrix(int rows, int cols, double *values)
    {
        t_matrix *m = creat_new_matrix(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            m->m_4x4[i] = values[i];  // Usamos m_4x4 pois é o maior array
        }
        return m;
    }
    
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
    
    //free_matrix(m2x2);
    
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
    
    //free_matrix(m3x3);
    
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
    
    //free_matrix(m3x3b);
    
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
    
    //free_matrix(m4x4);
    
    // ============================================
    // Teste 5: Matriz identidade 4x4
    // ============================================
    printf("Teste 5: Matriz identidade 4x4\n");
    t_matrix *identity = create_identity_matrix(4);
    
    double det_id = matrix_determinant(identity);
    printf("  Calculado: %f\n", det_id);
    printf("  Esperado:  1.0\n");
    printf("  Resultado: %s\n\n", fabs(det_id - 1.0) < EPSILON ? "✓ OK" : "✗ FALHOU");
    
    //free_matrix(identity);
    
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
    
    //free_matrix(translation);
    
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

void test_inverse_matrix_basic(void)
{
    printf("=== TESTE BÁSICO DA inverse_matrix() ===\n\n");
    
    int total_tests = 0;
    int passed_tests = 0;
    
    // Função auxiliar para verificar A × A⁻¹ = I
    bool verify_inverse(t_matrix *A, t_matrix *A_inv, const char *test_name)
    {
        t_matrix *product = matrix_multiplication(A, A_inv);
        if (!product) {
            printf("%s: ✗ FALHOU - multiplicação retornou NULL\n", test_name);
            return false;
        }
        
        t_matrix *identity = create_identity_matrix(A->rows);
        bool ok = matrix_comparison(product, identity);
        
        printf("%s: ", test_name);
        if (ok) {
            printf("✓ A × A⁻¹ = I\n");
        } else {
            printf("✗ FALHOU: A × A⁻¹ ≠ I\n");
        }
        
        //free_matrix(product);
        //free_matrix(identity);
        return ok;
    }
    
    // ============================================
    // Teste 1: Matriz identidade 2x2
    // ============================================
    printf("Teste 1: Matriz identidade 2x2\n");
    total_tests++;
    
    t_matrix *I2 = create_identity_matrix(2);
    t_matrix *inv_I2 = inverse_matrix(I2);
    
    if (inv_I2) {
        if (matrix_comparison(I2, inv_I2)) {
            printf("  ✓ I²⁻¹ == I²\n");
        } else {
            printf("  ✗ I²⁻¹ ≠ I²\n");
        }
        
        if (verify_inverse(I2, inv_I2, "  A×A⁻¹=I")) {
            passed_tests++;
        }
        //free_matrix(inv_I2);
    } else {
        printf("  ✗ FALHOU: inversa retornou NULL\n");
    }
    //free_matrix(I2);
    
    printf("\n");
    
    // ============================================
    // Teste 2: Matriz 2x2 simples (fácil verificar)
    // ============================================
    printf("Teste 2: Matriz 2x2 [[1, 2], [3, 4]]\n");
    total_tests++;
    
    t_matrix *m2 = creat_new_matrix(2, 2);
    mat_set(m2, 0, 0, 1); mat_set(m2, 0, 1, 2);
    mat_set(m2, 1, 0, 3); mat_set(m2, 1, 1, 4);
    
    printf("  Matriz original:\n");
    print_matrix(m2);
    
    t_matrix *inv_m2 = inverse_matrix(m2);
    
    if (inv_m2) {
        printf("  Matriz inversa calculada:\n");
        print_matrix(inv_m2);
        
        // Inversa esperada: (1/-2) * [[4, -2], [-3, 1]] = [[-2, 1], [1.5, -0.5]]
        // det = 1*4 - 2*3 = 4 - 6 = -2
        printf("  Inversa esperada:\n");
        printf("    m[0][0] = -2.00\n");
        printf("    m[0][1] =  1.00\n");
        printf("    m[1][0] =  1.50\n");
        printf("    m[1][1] = -0.50\n");
        
        if (verify_inverse(m2, inv_m2, "  Verificação A×A⁻¹")) {
            passed_tests++;
        }
        
        //free_matrix(inv_m2);
    } else {
        printf("  ✗ FALHOU: inversa retornou NULL\n");
    }
    //free_matrix(m2);
    
    printf("\n");
    
    // ============================================
    // Teste 3: Matriz 2x2 com determinante positivo
    // ============================================
    printf("Teste 3: Matriz 2x2 [[4, 1], [3, 2]]\n");
    total_tests++;
    
    t_matrix *m2b = creat_new_matrix(2, 2);
    mat_set(m2b, 0, 0, 4); mat_set(m2b, 0, 1, 1);
    mat_set(m2b, 1, 0, 3); mat_set(m2b, 1, 1, 2);
    
    t_matrix *inv_m2b = inverse_matrix(m2b);
    
    if (inv_m2b) {
        // det = 4*2 - 1*3 = 8 - 3 = 5
        // Inversa esperada: (1/5) * [[2, -1], [-3, 4]] = [[0.4, -0.2], [-0.6, 0.8]]
        t_matrix *expected2b = creat_new_matrix(2, 2);
        mat_set(expected2b, 0, 0, 0.4);  mat_set(expected2b, 0, 1, -0.2);
        mat_set(expected2b, 1, 0, -0.6); mat_set(expected2b, 1, 1, 0.8);
        
        printf("  Comparando com valores esperados: ");
        if (matrix_comparison(inv_m2b, expected2b)) {
            printf("✓ CORRETO\n");
        } else {
            printf("✗ INCORRETO\n");
            printf("  Calculado:\n");
            print_matrix(inv_m2b);
            printf("  Esperado:\n");
            print_matrix(expected2b);
        }
        
        if (verify_inverse(m2b, inv_m2b, "  Verificação A×A⁻¹")) {
            passed_tests++;
        }
        
        //free_matrix(expected2b);
        //free_matrix(inv_m2b);
    } else {
        printf("  ✗ FALHOU: inversa retornou NULL\n");
    }
    //free_matrix(m2b);
    
    printf("\n");
    
    // ============================================
    // Teste 4: Matriz 3x3 (exemplo clássico)
    // ============================================
    printf("Teste 4: Matriz 3x3 [[1, 2, 3], [0, 1, 4], [5, 6, 0]]\n");
    total_tests++;
    
    t_matrix *m3 = creat_new_matrix(3, 3);
    // Linha 0
    mat_set(m3, 0, 0, 1); mat_set(m3, 0, 1, 2); mat_set(m3, 0, 2, 3);
    // Linha 1
    mat_set(m3, 1, 0, 0); mat_set(m3, 1, 1, 1); mat_set(m3, 1, 2, 4);
    // Linha 2
    mat_set(m3, 2, 0, 5); mat_set(m3, 2, 1, 6); mat_set(m3, 2, 2, 0);
    
    t_matrix *inv_m3 = inverse_matrix(m3);
    
    if (inv_m3) {
        printf("  Matriz inversa calculada:\n");
        print_matrix(inv_m3);
        
        // Valores esperados (calculados anteriormente):
        // [[-24, 18, 5], [20, -15, -4], [-5, 4, 1]]
        printf("  Inversa esperada (aproximada):\n");
        printf("    [-24.00,  18.00,   5.00]\n");
        printf("    [ 20.00, -15.00,  -4.00]\n");
        printf("    [ -5.00,   4.00,   1.00]\n");
        
        if (verify_inverse(m3, inv_m3, "  Verificação A×A⁻¹")) {
            passed_tests++;
        }
        
        //free_matrix(inv_m3);
    } else {
        printf("  ✗ FALHOU: inversa retornou NULL\n");
    }
    //free_matrix(m3);
    
    printf("\n");
    
    // ============================================
    // Teste 5: Matriz singular (não invertível)
    // ============================================
    printf("Teste 5: Matriz singular 2x2 [[1, 2], [2, 4]]\n");
    total_tests++;
    
    t_matrix *singular = creat_new_matrix(2, 2);
    mat_set(singular, 0, 0, 1); mat_set(singular, 0, 1, 2);
    mat_set(singular, 1, 0, 2); mat_set(singular, 1, 1, 4);
    
    t_matrix *inv_singular = inverse_matrix(singular);
    
    if (inv_singular == NULL) {
        printf("  ✓ CORRETO: retornou NULL para matriz singular\n");
        printf("    (det = 1*4 - 2*2 = 0)\n");
        passed_tests++;
    } else {
        printf("  ✗ FALHOU: deveria retornar NULL para matriz singular\n");
        //free_matrix(inv_singular);
    }
    //free_matrix(singular);
    
    printf("\n");
    
    // ============================================
    // Teste 6: Matriz 3x3 com det = 1 (fácil)
    // ============================================
    printf("Teste 6: Matriz 3x3 triangular superior\n");
    total_tests++;
    
    t_matrix *m3b = creat_new_matrix(3, 3);
    // Matriz triangular superior: det = produto da diagonal = 1*2*3 = 6
    mat_set(m3b, 0, 0, 1); mat_set(m3b, 0, 1, 2); mat_set(m3b, 0, 2, 3);
    mat_set(m3b, 1, 0, 0); mat_set(m3b, 1, 1, 2); mat_set(m3b, 1, 2, 4);
    mat_set(m3b, 2, 0, 0); mat_set(m3b, 2, 1, 0); mat_set(m3b, 2, 2, 3);
    
    t_matrix *inv_m3b = inverse_matrix(m3b);
    
    if (inv_m3b) {
        if (verify_inverse(m3b, inv_m3b, "  Verificação A×A⁻¹")) {
            passed_tests++;
        }
        //free_matrix(inv_m3b);
    } else {
        printf("  ✗ FALHOU: inversa retornou NULL\n");
    }
    //free_matrix(m3b);
    
    printf("\n");
    
    // ============================================
    // Teste 7: Propriedade (A⁻¹)⁻¹ = A
    // ============================================
    printf("Teste 7: Propriedade (A⁻¹)⁻¹ = A\n");
    total_tests++;
    
    t_matrix *m_test = creat_new_matrix(3, 3);
    // Valores aleatórios mas não singulares
    mat_set(m_test, 0, 0, 2); mat_set(m_test, 0, 1, 0); mat_set(m_test, 0, 2, 1);
    mat_set(m_test, 1, 0, 1); mat_set(m_test, 1, 1, 2); mat_set(m_test, 1, 2, 0);
    mat_set(m_test, 2, 0, 0); mat_set(m_test, 2, 1, 1); mat_set(m_test, 2, 2, 2);
    
    t_matrix *inv_test = inverse_matrix(m_test);
    
    if (inv_test) {
        t_matrix *inv_inv_test = inverse_matrix(inv_test);
        
        if (inv_inv_test) {
            if (matrix_comparison(m_test, inv_inv_test)) {
                printf("  ✓ (A⁻¹)⁻¹ == A\n");
                passed_tests++;
            } else {
                printf("  ✗ FALHOU: (A⁻¹)⁻¹ ≠ A\n");
            }
            //free_matrix(inv_inv_test);
        } else {
            printf("  ✗ FALHOU: não conseguiu inverter a inversa\n");
        }
        //free_matrix(inv_test);
    } else {
        printf("  ✗ FALHOU: não conseguiu inverter matriz original\n");
    }
    //free_matrix(m_test);
    
    printf("\n");
    
    // ============================================
    // Resumo
    // ============================================
    printf("=== RESUMO ===\n");
    printf("Testes realizados: %d\n", total_tests);
    printf("Testes passados: %d\n", passed_tests);
    printf("Testes falhados: %d\n", total_tests - passed_tests);
    
    if (passed_tests == total_tests) {
        printf("✓ TODOS OS TESTES PASSARAM!\n");
    } else {
        printf("✗ ALGUNS TESTES FALHARAM\n");
        printf("  Verifique especialmente:\n");
        printf("  1. O cálculo do determinante\n");
        printf("  2. A função get_cofactor()\n");
        printf("  3. Se está transpondo a matriz de cofatores\n");
    }
}