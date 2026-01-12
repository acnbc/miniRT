/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:17:42 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/12 13:39:32 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double  *get_matrix(t_matrix *m)
{
    double  *ptr;

    if (m->rows == 4 && m->cols == 4)
        ptr = m->m_4x4;
    else if (m->rows == 4 && m->cols == 1)
        ptr = m->m_4x1;
    else if (m->rows == 3)
        ptr = m->m_3x3;
    else if (m->rows == 2)
        ptr = m->m_2x2;
    return (ptr);
}

double  mat_get(t_matrix *m, int row, int col)
{
    double  *ptr;

    ptr = get_matrix(m);
    return (ptr[row * m->rows + col]);
}

void    mat_set(t_matrix *m, int row, int col, double value)
{
    double  *ptr;

    ptr = get_matrix(m);
    ptr[row * m->rows + col] = value;
}

t_matrix    *creat_new_matrix(int rows, int cols)
{
    t_matrix    *new;

    new = (t_matrix *)safe_malloc(sizeof(t_matrix));
    new->rows = rows;
    new->cols = cols;
    return (new);
}

bool    matrix_comparison(t_matrix *a, t_matrix *b)
{
    int     i;
    int     dimension;
    double  *ptr_a;
    double  *ptr_b;

    i = -1;
    if ((a->rows != b->rows) || (a->cols != b->cols))
        return (false);
    dimension = a->rows * a->cols;
    ptr_a = get_matrix(a);
    ptr_b = get_matrix(b);
    while (++i < dimension)
    {
        if (!is_equal(ptr_a[i], ptr_b[i]))
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

    if ((a->rows != b->rows) || (a->cols != b->cols))
        return (NULL);
    row = -1;
    col = -1;
    product = creat_new_matrix(a->rows, a->cols);
    while (++row < a->rows)
    {
        col = -1;
        while (++col < a->cols)
        {
            sum = 0;
            k = -1;
            while (++k < a->cols)
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
    double      *ptr_a;
    double      *ptr_b;
    double      *ptr;

    result = creat_new_matrix(a->rows, b->cols);
    ptr_a = get_matrix(a);
    ptr_b = get_matrix(b);
    ptr = get_matrix(result);
    row = -1;
    while (++row < a->rows)
    {
        sum = 0;
        k = -1;
        while (++k < a->cols)
            sum += ptr_a[row * a->rows + k] * ptr_b[k];
        ptr[row] = sum;
    }
    return (result);
}

t_matrix    *matrix_transposition(t_matrix *m)
{
    t_matrix    *transposed;
    double      *ptr;
    double      *ptr_tr;
    int         row;
    int         col;

    transposed = creat_new_matrix(m->rows, m->cols);
    ptr = get_matrix(m);
    ptr_tr = get_matrix(transposed);
    row = -1;
    while (++row < m->rows)
    {
        col = -1;
        while (++col < m->rows)
            ptr_tr[col * m->rows + row] = ptr[row * m->rows + col];
    }
    return (transposed);
}

double  determinant(t_matrix *a)
{
    double  ac;
    double  bd;

    ac = mat_get(a, 0, 0) * mat_get(a, 1, 1);
    bd = mat_get(a, 0, 1) * mat_get(a, 1, 0);
    printf("ac %.2f\nbd = %.2f\n", ac, bd);
    return ((ac - bd));
}

t_matrix    *submatrix(t_matrix *m, int row, int col)
{
    int         i;
    int         j;
    int         k;
    int         l;
    t_matrix    *sub;
    
    i = -1;
    k = 0;
    sub = creat_new_matrix(m->rows - 1, m->cols - 1);
    while (++i < m->rows)
    {
        if (i == row)
                continue ;
        j = -1;
        l = 0;
        while (++j < m->cols)
        {
            if (j == col)
                continue ;
            mat_set(sub, k, l++, mat_get(m, i, j));
        }
        k++;
    }
    return (sub);
}