/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:11:15 by jessica           #+#    #+#             */
/*   Updated: 2026/02/15 06:15:39 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	print_scene(t_scene *scene);

int	main(int argc, char **argv)
{
	t_scene		*scene;

	if (argc < 2)
		return (0);
	scene = read_image(argv[1]);
	if (!scene)
		return (1);
	print_scene(scene);
	free_scene(&scene);
	return (0);
}

void	print_error(char *error, bool clean)
{
	ft_putendl_fd("Error", 2);
	if (!error)
		return ;
	ft_putendl_fd(error, 2);
	if (clean)
		free(error);
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
	free(*scene);
	*scene = NULL;
}
