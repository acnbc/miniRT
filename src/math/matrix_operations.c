/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:17:42 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/05 16:39:52 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double  mat_get(const t_matrix *m, int row, int col)
{
    return m->m[row * 4 + col];
}

void    mat_set(t_matrix *m, int row, int col, double value)
{
    m->m[row * 4 + col] = value;
}



bool    matrix_comparison(t_matrix *a, t_matrix *b)
{
    int i;

    i = -1;
    while (++i < MATRIX_DIM)
    {
        if (!is_equal(a->m[i], b->m[i]))
            return (false);
    }
    return (true);
}


t_matrix    *matrix_multiplication(t_matrix *a, t_matrix *b)
{
    t_matrix    *product;
    int         row;
    int         col;
    int         k;
    double      sum;

    row = -1;
    col = -1;
    product = (t_matrix *)safe_malloc(sizeof(t_matrix));
    while (++row < 4)
    {
        col = -1;
        while (++col < 4)
        {
            sum = 0;
            k = -1;
            while (++k < 4)
                sum += mat_get(a, row, k) * mat_get(b, k, col);
            mat_set(product, row, col, sum);
        }
    }
    return (product);
}

t_matrix    *matrix_tuple_multiplication(t_matrix *a, t_matrix *b)
{
    t_matrix    *result;
    int         row;
    int         k;
    double      sum;

    result = (t_matrix *)safe_malloc(sizeof(t_matrix));
    row = -1;
    while (++row < 4)
    {
        sum = 0;
        k = -1;
        while (++k < 4)
            sum += a->m[row * 4 + k] * b->t[k];
        result->t[row] = sum;
    }
    return (result);
}

t_matrix    *matrix_transposition(t_matrix *m)
{
    t_matrix    *transposed;
    int         row;
    int         col;

    transposed = (t_matrix *)safe_malloc(sizeof(t_matrix));
    row = -1;
    while (++row < 4)
    {
        col = -1;
        while (++col < 4)
        {
            transposed->m[col * 4 + row] = m->m[row * 4 + col];
        }
    }
    return (transposed);
}