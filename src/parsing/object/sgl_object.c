/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgl_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:53:27 by jessica           #+#    #+#             */
/*   Updated: 2026/02/15 07:43:25 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_amb_light	*create_amb_light(char **infos)
{
	t_amb_light	*amb_light;

	if (ft_split_len(infos) < 2)
		exit_error("invalid arguments", false, NULL);
	amb_light = (t_amb_light *)malloc(sizeof(t_amb_light));
	if (!amb_light)
		exit_error("malloc error", false, NULL);
	amb_light->id = A;
	amb_light->light_ratio = ft_atod(infos[0]);
	if (amb_light->light_ratio < 0 || amb_light->light_ratio > 1)
	{
		free(amb_light);
		exit_error("malloc error", false, NULL);
	}
	amb_light->colors = get_coolors(infos[1]);
	if (!amb_light->colors)
	{
		free(amb_light);
		exit_error("malloc error", false, NULL);
	}
	return (amb_light);
}

t_camera	*create_camera(char **infos)
{
	t_camera	*camera;

	if (ft_split_len(infos) < 3)
		exit_error("invalid arguments", false, NULL);
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		exit_error("malloc error", false, NULL);
	camera->id = C;
	camera->view_point = get_coord(infos[0], false);
	if (!camera->view_point)
		exit_error("malloc error", false, NULL);
	camera->orientation_vector = get_coord(infos[1], true);
	if (!camera->orientation_vector)
		exit_error("malloc error", false, NULL);
	camera->field_of_view = ft_atoi(infos[2]);
	if (camera->field_of_view < 0 || camera->field_of_view > 180)
		exit_error("malloc error", false, NULL);
	return (camera);
}

t_light	*create_light(char **infos)
{
	t_light	*light;

	if (ft_split_len(infos) < 2)
		exit_error("invalid arguments", false, NULL);
	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		exit_error("malloc error", false, NULL);
	light->id = L;
	light->light_point = get_coord(infos[0], false);
	if (!light->light_point)
		exit_error("malloc error", false, NULL);
	light->brightness = ft_atod(infos[1]);
	if (light->brightness < 0 || light->brightness > 1)
		exit_error("invalid arguments", false, NULL);
	return (light);
}
