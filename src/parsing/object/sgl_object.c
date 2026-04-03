/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgl_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:53:27 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 01:11:02 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static void	error_create_element(char ***infos, t_msg_error error);
static void	calc_intensity(t_light *light);

void	create_amb_light(t_scene *scene, char ***infos, int index)
{
	t_msg_error	error;
	t_amb_light	*amb_light;

	scene->amb_light = (t_amb_light *)ft_calloc(1, sizeof(t_amb_light));
	if (!scene->amb_light)
		error_create_element(infos, ERR_MALLOC);
	amb_light = scene->amb_light;
	amb_light->id = A;
	amb_light->light_ratio = ft_atod((*infos)[index]);
	if (amb_light->light_ratio < 0 || amb_light->light_ratio > 1)
		error_create_element(infos, ERR_RANGE);
	error = get_coolors(&amb_light->colors, *infos, index + 1);
	if (error)
		error_create_element(infos, error);
}

void	create_camera(t_scene *scene, char ***infos, int index)
{
	t_msg_error	error;
	t_camera	*camera;

	scene->camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (!scene->camera)
		error_create_element(infos, ERR_MALLOC);
	camera = scene->camera;
	camera->id = C;
	camera->view_point = get_coord(*infos, index, false);
	camera->orientation_vector = get_coord(*infos, index + 1, true);
	error = valid_tuple(camera->view_point);
	if (error)
		error_create_element(infos, error);
	error = valid_tuple(camera->orientation_vector);
	if (error)
		error_create_element(infos, error);
	camera->field_of_view = ft_atoi((*infos)[index + 2]);
	if (camera->field_of_view < 0 || camera->field_of_view > 180)
		error_create_element(infos, ERR_RANGE);
}

void	create_light(t_scene *scene, char ***infos, int index)
{
	t_msg_error	error;
	t_light		*light;

	scene->light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (!scene->light)
		error_create_element(infos, ERR_MALLOC);
	light = scene->light;
	light->id = L;
	light->point = get_coord(*infos, index, false);
	error = valid_tuple(light->point);
	if (error)
		error_create_element(infos, error);
	light->brightness = ft_atod((*infos)[index + 1]);
	if (light->brightness < 0 || light->brightness > 1)
		error_create_element(infos, ERR_RANGE);
	light->colors.r = 1;
	light->colors.g = 1;
	light->colors.b = 1;
	if ((*infos)[index + 2])
	{
		error = get_coolors(&light->colors, *infos, index + 2);
		if (error)
			error_create_element(infos, error);
	}
	calc_intensity(scene->light);
}

static void	calc_intensity(t_light *light)
{
	light->intensity = (t_rgb){{
		.r = light->colors.r * light->brightness,
		.g = light->colors.g * light->brightness,
		.b = light->colors.b * light->brightness}};
}

static void	error_create_element(char ***infos, t_msg_error error)
{
	ft_split_free(infos);
	exit_error(error, NULL);
}
