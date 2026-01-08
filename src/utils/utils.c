/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:57 by anogueir          #+#    #+#             */
/*   Updated: 2026/01/08 15:06:00 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (ptr == NULL)
	{
		// free function;
		exit (1);
	}
	return (ptr);
}