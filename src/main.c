/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:11:15 by jessica           #+#    #+#             */
/*   Updated: 2026/03/21 16:05:05 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	main(int argc, char **argv)
{
	t_scene		*scene;

	if (argc < 2)
		return (0);
	scene = NULL;
	exit_error(-1, &scene);
	read_image(&scene, argv[1]);
	create_window(scene, argv[1]);
	create_image(scene->window);
	init_hooks(scene);
	tester(scene);
	return (0);
}

static void	free_gnl(int *fd)
{
	char		*line;

	line = get_next_line(*fd);
	while (line)
	{
		free(line);
		line = get_next_line(*fd);
	}
	close(*fd);
	*fd = -1;
}

void	free_scene(t_scene **scene)
{
	if (!scene || !*scene)
		return ;
	lst_clear_object(&(*scene)->objects);
	free((*scene)->light);
	free((*scene)->camera);
	free((*scene)->amb_light);
	if ((*scene)->window)
		free_window(&(*scene)->window);
	if ((*scene)->fd != -1)
		free_gnl(&(*scene)->fd);
	free(*scene);
	*scene = NULL;
}
