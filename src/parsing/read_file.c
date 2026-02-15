/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:36:45 by jessica           #+#    #+#             */
/*   Updated: 2026/02/15 07:41:20 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	open_file(char *file);
static bool	add_object(char *line, t_scene *scene);
static bool	add_slg_object(t_scene *scene, char **infos, t_id id);
static bool	empty_line(char *line);

t_scene	*read_image(char *file)
{
	char		*line;
	t_scene		*scene;
	int			fd;

	fd = open_file(file);
	if (fd < 0)
		return (NULL);
	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	line = NULL;
	while (scene != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (add_object(line, scene))
		{
			free_scene(&scene);
			free(line);
			break ;
		}
	}
	close(fd);
	return (scene);
}

static int	open_file(char *file)
{
	int		fd;
	size_t	len;

	if (!file)
		return (-1);
	len = ft_strlen(file);
	if (len < 3 || ft_strncmp(&file[len - 3], ".rt", 4))
		exit_error(ft_sprintf("invalid format file: %s", file), true, NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(ft_sprintf("error reading file: %s", file), true, NULL);
	return (fd);
}

static bool	add_object(char *line, t_scene *scene)
{
	t_id		id;
	t_object	*node;
	bool		error;
	char		**infos;

	if (empty_line(line))
		return (false);
	id = get_id(line);
	if (id == (t_id)-1)
		return (true);
	infos = ft_split(line, ' ');
	if (!infos)
		exit_error("malloc error", false, NULL);
	if (id == sp || id == pl || id == cy)
	{
		node = lst_new_object(infos, id);
		if (node)
			lst_add_back_object(&scene->objects, node);
		error = node == NULL;
	}
	else
		error = add_slg_object(scene, infos, id);
	ft_split_free(&infos);
	return (error);
}

static bool	add_slg_object(t_scene *scene, char **infos, t_id id)
{
	if (id == A)
	{
		if (scene->amb_light)
			exit_error("single element duplicated", false, NULL);
		scene->amb_light = create_amb_light(&infos[1]);
		if (!scene->amb_light)
			return (true);
	}
	if (id == C)
	{
		if (scene->camera)
			exit_error("single element duplicated", false, NULL);
		scene->camera = create_camera(&infos[1]);
		if (!scene->camera)
			return (true);
	}
	if (id == L)
	{
		if (scene->light)
			exit_error("single element duplicated", false, NULL);
		scene->light = create_light(&infos[1]);
		if (!scene->light)
			return (true);
	}
	return (false);
}

static bool	empty_line(char *line)
{
	char	*line_trim;
	bool	empty;

	if (!line || !*line)
		return (true);
	line_trim = ft_strtrim(line, " \t\n\v\r");
	empty = false;
	if (!line_trim || !*line_trim)
		empty = true;
	free(line_trim);
	return (empty);
}
