/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:41:22 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/13 15:17:05 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrix	*translation(t_matrix *offset)
{
	t_matrix	*m;

	m = create_identity_matrix(4);
	if (!m || !offset)
		return (m);
	mat_set(m, 0, 3, offset->m_4x1[0]);
	mat_set(m, 1, 3, offset->m_4x1[1]);
	mat_set(m, 2, 3, offset->m_4x1[2]);
	return (m);
}
