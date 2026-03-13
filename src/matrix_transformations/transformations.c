/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:41:22 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/13 14:52:58 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrix	*translation(double x, double y, double z)
{
	t_matrix	*m;

	m = create_identity_matrix(4);

	mat_set(m, 0, 3, x);
	mat_set(m, 1, 3, y);
	mat_set(m, 2, 3, z);

	return (m);
}
