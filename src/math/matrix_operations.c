/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:17:42 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/12 18:05:29 by anogueir         ###   ########.fr       */
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
    else
    {
        if (m->rows * m->cols <= 16)
            return m->m_4x4;
        else
            return NULL;
    }
    return (ptr);
}

double  mat_get(t_matrix *m, int row, int col)
{
    double  *ptr;

    ptr = get_matrix(m);
    return (ptr[row * m->cols + col]);
}

void    mat_set(t_matrix *m, int row, int col, double value)
{
    double  *ptr;

    ptr = get_matrix(m);
    ptr[row * m->cols + col] = value;
}

t_matrix    *creat_new_matrix(int rows, int cols)
{
    t_matrix    *new;
    int         i;

    new = (t_matrix *)safe_malloc(sizeof(t_matrix));
    new->rows = rows;
    new->cols = cols;
    i = -1;
    while (++i < 16)
        new->m_4x4[i] = 0.0;
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

    if (a->cols != b->rows)
        return (NULL);
    row = -1;
    col = -1;
    product = creat_new_matrix(a->rows, b->cols);
    while (++row < a->rows)
    {
        col = -1;
        while (++col < a->cols)
        {
            sum = 0;
            k = -1;
            while (++k < b->cols)
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

double  get_2x2_determinant(t_matrix *a)
{
    double  ac;
    double  bd;
    
    ac = mat_get(a, 0, 0) * mat_get(a, 1, 1);
    bd = mat_get(a, 0, 1) * mat_get(a, 1, 0);
    return (ac - bd);
}

t_matrix    *get_submatrix(t_matrix *m, int row, int col)
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

double  get_minor(t_matrix *m, int row, int col)
{
    t_matrix    *sub;
    double      minor;

    sub = get_submatrix(m, row, col);
    if (sub->rows == 2 && sub->cols == 2)
        minor = get_2x2_determinant(sub);
    else
        minor = matrix_determinant(sub);
    return (minor);
}

double  get_cofactor(t_matrix *m, int row, int col)
{
    double  cofactor;
    double  minor;

    minor = get_minor(m, row, col);
    if ((row + col) % 2 == 0)
        cofactor = minor;
    else
        cofactor = -minor;
    return (cofactor);
}

double matrix_determinant(t_matrix *m)
{
    double det;
    int i;
    
    if (m->rows == 2 && m->cols == 2)
        return (get_2x2_determinant(m));
    det = 0.0;
    i = -1;
    while (++i < m->cols)
        det += mat_get(m, 0, i) * get_cofactor(m, 0, i);
    return (det);
}

bool    is_invertible(t_matrix *m)
{
    if (fabs(matrix_determinant(m)) < EPSILON)
        return (false);
    return (true);
}

t_matrix    *inverse_matrix(t_matrix *m)
{
    t_matrix    *inverted;
    int         row;
    int         col;
    double      det;
    double      c;
    
    if (!is_invertible(m))
        return (NULL);
    inverted = creat_new_matrix(m->rows, m->cols);
    det =  matrix_determinant(m);
    row = -1;
    while (++row < m->rows)
    {
        col = -1;
        while (++col < m->cols)
        {
            c = get_cofactor(m, col, row);
            mat_set(inverted, row, col, c / det);
        }
    }
    return (inverted);
}