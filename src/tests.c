/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:38:20 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/05 16:19:55 by anogueir         ###   ########.fr       */
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
    int row = 0;
    int col = 0;

    i = -1;

    while (++i < MATRIX_DIM)
    {
        row = i / 4;
        col = i % 4;
        printf("m[%d][%d] = %8.2f\n", row, col, matrix->m[i]);
    }
}

void    print_one_col_matrix(t_matrix *matrix)
{
    int i;
    i = -1;
    while (++i < 4)
    {
        printf("m[%d] = %8.2f\n", i, matrix->m[i]);
    }
}

void    test_matrix_comparison(void)
{
    t_matrix	matrix_a = {
    	.m = 
    	{
    	    1.0, 2.0, 3.0, 4.0,
    	    5.5, 6.5, 7.5, 8.5,
    	    9.0, 10.0, 11.0, 12.0,
    	    13.5, 14.5, 15.5, 16.5
    	}
    };

    t_matrix	matrix_b = {
    	.m =
    	{
    		1, 2, 3, 4,
    		5, 6, 7, 8,
    		9, 8, 7, 6,
    		5, 4, 3, 2
    	}
    };

    t_matrix	matrix_c = {
    	.m =
    	{
    		1, 2, 3, 4,
    		5, 6, 7, 8,
    		9, 8, 7, 6,
    		5, 4, 3, 2
    	}
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
    	.m =
    	{
    		1, 2, 3, 4,
    		5, 6, 7, 8,
    		9, 8, 7, 6,
    		5, 4, 3, 2
    	}
    };

    t_matrix	matrix_d = {
    	.m =
    	{
    		-2, 1, 2, 3,
    		3, 2, 1, -1,
    		4, 3, 6, 5,
    		1, 2, 7, 8
    	}
    };

    t_matrix	matrix_r = {
    	.m =
    	{
            20, 22, 50, 48,
            44, 54, 114, 108,
            40, 58, 110, 102,
            16, 26, 46, 42
    	}
    };

    t_matrix	matrix_e = {
    	.t = {1, 2, 3, 1}
    };

    t_matrix	matrix_f = {
    	.m =
    	{
    		1, 2, 3, 4,
    		2, 4, 4, 2,
    		8, 6, 4, 1,
    		0, 0, 0, 1
    	}
    };

    t_matrix	matrix_re = {
    	.t = {18, 24, 33, 1}
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
        .m = {
            0, 9, 3, 0,
            9, 8, 0, 8,
            1, 8, 5, 3,
            0, 0, 5, 8
        }
    };
    
    t_matrix expected = {
        .m = {
            0, 9, 1, 0,
            9, 8, 8, 0,
            3, 0, 5, 5,
            0, 8, 3, 8
        }
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