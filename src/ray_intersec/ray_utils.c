/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:47:17 by ldos_sa2          #+#    #+#             */
/*   Updated: 2026/03/29 21:00:47 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	create_ray(t_ray *ray, t_matrix origin, t_matrix direction)
{
	ray->ori = origin;
	ray->direc = direction;
}
