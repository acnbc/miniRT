/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:11:15 by jessica           #+#    #+#             */
/*   Updated: 2026/02/16 19:55:45 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	main(int argc, char **argv)
{
	t_scene		*scene;

	if (argc < 2)
		return (0);
	scene = read_image(argv[1]);
	if (!scene)
		return (1);
	exit_error(NULL, false, &scene);
	tester(scene);
	create_window(scene, argv[1]);
	create_image(scene->window);
	init_hooks(scene);
	return (0);
}

void	free_scene(t_scene **scene)
{
	lst_clear_object(&(*scene)->objects);
	if ((*scene)->light)
		free((*scene)->light->light_point);
	free((*scene)->light);
	if ((*scene)->camera)
	{
		free((*scene)->camera->view_point);
		free((*scene)->camera->orientation_vector);
	}
	free((*scene)->camera);
	if ((*scene)->amb_light)
		free((*scene)->amb_light->colors);
	free((*scene)->amb_light);
	if ((*scene)->window)
		free_window(&(*scene)->window);
	free(*scene);
	*scene = NULL;
}
