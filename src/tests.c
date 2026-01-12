/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:38:20 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/12 13:30:26 by anogueir         ###   ########.fr       */
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

    result = determinant(&a);
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
    
    result_a = submatrix(&a, 0, 2);

    printf("result_a:\n");
    print_matrix(result_a);
    printf("sub_a:\n");
    print_matrix(&sub_a);
    if (matrix_comparison(result_a, &sub_a))
        printf("Correct submatrix\n");
    else
        printf("Incorrect submatrix\n");

    result_b = submatrix(&b, 2, 1);

    printf("result_b:\n");
    print_matrix(result_b);
    printf("sub_b:\n");
    print_matrix(&sub_b);
    
    if (matrix_comparison(result_b, &sub_b))
        printf("Correct submatrix\n");
    else
        printf("Incorrect submatrix\n");
}