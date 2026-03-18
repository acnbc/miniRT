/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgl_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:53:27 by jessica           #+#    #+#             */
/*   Updated: 2026/03/17 23:32:47 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

void	create_amb_light(t_scene *scene, char ***infos, int index)
{
	t_msg_error	error;

	scene->amb_light = (t_amb_light *)ft_calloc(1, sizeof(t_amb_light));
	if (!scene->amb_light)
	{
		ft_split_free(infos);
		exit_error(ERR_MALLOC, NULL);
	}
	scene->amb_light->id = A;
	scene->amb_light->light_ratio = ft_atod((*infos)[index]);
	if (scene->amb_light->light_ratio < 0 || scene->amb_light->light_ratio > 1)
	{
		ft_split_free(infos);
		exit_error(ERR_RANGE, NULL);
	}
	error = get_coolors(&scene->amb_light->colors, *infos, index + 1);
	if (error)
	{
		ft_split_free(infos);
		exit_error(error, NULL);
	}
}

void	create_camera(t_scene *scene, char ***infos, int index)
{
	t_msg_error	error;

	scene->camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (!scene->camera)
	{
		ft_split_free(infos);
		exit_error(ERR_MALLOC, NULL);
	}
	scene->camera->id = C;
	scene->camera->view_point = get_coord(*infos, index, false);
	scene->camera->orientation_vector = get_coord(*infos, index + 1, true);
	error = valid_tuple(scene->camera->view_point);
	if (!error)
		error = valid_tuple(scene->camera->orientation_vector);
	if (error)
	{
		ft_split_free(infos);
		exit_error(error, NULL);
	}
	scene->camera->field_of_view = ft_atoi((*infos)[index + 2]);
	if (scene->camera->field_of_view < 0 || scene->camera->field_of_view > 180)
	{
		ft_split_free(infos);
		exit_error(ERR_RANGE, NULL);
	}
}

void	create_light(t_scene *scene, char ***infos, int index)
{
	t_msg_error	error;

	scene->light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (!scene->light)
	{
		ft_split_free(infos);
		exit_error(ERR_MALLOC, NULL);
	}
	scene->light->id = L;
	scene->light->light_point = get_coord(*infos, index, false);
	error = valid_tuple(scene->light->light_point);
	if (!error)
	{
		scene->light->brightness = ft_atod((*infos)[index + 1]);
		if (scene->light->brightness < 0 || scene->light->brightness > 1)
		{
			ft_split_free(infos);
			exit_error(ERR_RANGE, NULL);
		}
		error = get_coolors(&scene->light->colors, *infos, index + 2);
	}
	if (!error)
		return ;
	ft_split_free(infos);
	exit_error(error, NULL);
}
