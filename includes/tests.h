/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:39:05 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/12 13:25:13 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
void    print_tuples(t_tuple tuple);
void    print_matrix(t_matrix *matrix);
void    print_one_col_matrix(t_matrix *matrix);
void    print_one_col_matrix(t_matrix *matrix);
void    test_matrix_comparison(void);
void    test_matrix_multiplication(void);
void    test_transposition(void);
void    test_mult_matrix_id(void);
void    test_determinant(void);
void    test_submatrix(void);
#endif