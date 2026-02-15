/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:57 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/14 09:28:07 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	free_matrix(t_matrix *matrix)
{
	if (matrix == NULL)
		return ;
	free(matrix);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (ptr == NULL)
		exit(1);
	return (ptr);
}
