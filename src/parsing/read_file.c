/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:36:45 by jessica           #+#    #+#             */
/*   Updated: 2026/03/17 23:29:53 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static int	open_file(char *file);
static void	add_object(char ***infos, t_scene *scene);
static bool	empty_line(char *line);
static void	args_object(t_scene *scene, char ***infos, t_id id);

void	read_image(t_scene **scene, char *file)
{
	char		*line;
	char		**infos;

	*scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (!*scene)
		exit_error(ERR_MALLOC, NULL);
	(*scene)->fd = open_file(file);
	while (*scene != NULL)
	{
		line = get_next_line((*scene)->fd);
		if (!line)
			break ;
		if (empty_line(line))
		{
			free(line);
			continue ;
		}
		infos = ft_split(line, ' ');
		free(line);
		add_object(&infos, *scene);
	}
	close((*scene)->fd);
	(*scene)->fd = -1;
	if (!(*scene)->amb_light || !(*scene)->camera || !(*scene)->light)
		exit_error(ERR_MISSING_ELEM, NULL);
}

static int	open_file(char *file)
{
	int		fd;
	size_t	len;

	len = ft_strlen(file);
	if (len < 3 || ft_strncmp(&file[len - 3], ".rt", 4))
		exit_error(ERR_FILE_FORMAT, NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(ERR_FILE_READ, NULL);
	return (fd);
}

static void	add_object(char ***infos, t_scene *scene)
{
	t_id		id;
	t_object	*node;

	if (!infos || !*infos)
		exit_error(ERR_MALLOC, NULL);
	id = get_id((*infos)[0]);
	if (id == Invalid)
	{
		ft_split_free(infos);
		exit_error(ERR_ARGS, NULL);
	}
	args_object(scene, infos, id);
	if (id == sp || id == pl || id == cy)
	{
		node = lst_new_object(infos, id);
		lst_add_back_object(&scene->objects, node);
	}
	if (id == A)
		create_amb_light(scene, infos, 1);
	if (id == C)
		create_camera(scene, infos, 1);
	if (id == L)
		create_light(scene, infos, 1);
	ft_split_free(infos);
}

static void	args_object(t_scene *scene, char ***infos, t_id id)
{
	bool		error;
	t_msg_error	msg_error;
	int			len;

	len = 2 + (id == C || id == sp || id == pl || id == cy);
	error = false;
	if (id == A)
		error = scene->amb_light != NULL;
	if (id == C)
		error = scene->camera != NULL;
	if (id == L)
		error = scene->light != NULL;
	msg_error = ERR_DUPLICATE;
	if (!infos || !*infos || ft_split_len(&(*infos)[1]) < len)
	{
		msg_error = ERR_MISSING_ARGS;
		error = true;
	}
	if (error)
	{
		ft_split_free(infos);
		exit_error(msg_error, NULL);
	}
}

static bool	empty_line(char *line)
{
	char	*line_trim;
	bool	empty;

	if (!line || !*line)
		return (true);
	line_trim = ft_strtrim(line, " \t\n\v\r");
	empty = ft_strlen(line_trim) == 0;
	free(line_trim);
	return (empty);
}
