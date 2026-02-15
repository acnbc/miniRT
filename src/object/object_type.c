/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 01:40:17 by jessica           #+#    #+#             */
/*   Updated: 2026/02/15 06:53:00 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static t_sphere		*object_type_sphere(char **infos);
static t_plane		*object_type_plane(char **infos);
static t_cylinder	*object_type_cylinder(char **infos);

t_object_type	*get_object_type(t_id id, char **infos)
{
	t_object_type	*type;

	type = ft_calloc(1, sizeof(t_object_type));
	if (!type)
	{
		print_error("malloc error", false);
		return (NULL);
	}
	type->sphere = NULL;
	type->plane = NULL;
	type->cylinder = NULL;
	if (id == sp)
		type->sphere = object_type_sphere(infos);
	else if (id == pl)
		type->plane = object_type_plane(infos);
	else if (id == cy)
		type->cylinder = object_type_cylinder(infos);
	if (!type->sphere && !type->plane && !type->cylinder)
	{
		free(type);
		return (NULL);
	}
	return (type);
}

static t_sphere	*object_type_sphere(char **infos)
{
	t_sphere	*sphere;

	if (!infos || !*infos)
	{
		print_error("invalid arguments", false);
		return (NULL);
	}
	sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
	{
		print_error("malloc error", false);
		return (NULL);
	}
	sphere->diameter = ft_atod(infos[0]);
	return (sphere);
}

static t_plane	*object_type_plane(char **infos)
{
	t_plane	*plane;

	if (!infos || !*infos)
	{
		print_error("invalid arguments", false);
		return (NULL);
	}
	plane = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (!plane)
	{
		print_error("malloc error", false);
		return (NULL);
	}
	plane->normalized_vector = get_coord(infos[0], true);
	if (!plane->normalized_vector)
	{
		print_error("malloc error", false);
		return (NULL);
	}
	return (plane);
}

static t_cylinder	*object_type_cylinder(char **infos)
{
	t_cylinder	*cylinder;

	if (ft_split_len(infos) < 3)
	{
		print_error("invalid arguments", false);
		return (NULL);
	}
	cylinder = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
	{
		print_error("malloc error", false);
		return (NULL);
	}
	cylinder->normalized_vector = get_coord(infos[0], true);
	if (!cylinder->normalized_vector)
	{
		print_error("malloc error", false);
		return (NULL);
	}
	cylinder->diameter = ft_atoi(infos[1]);
	cylinder->height = ft_atoi(infos[2]);
	return (cylinder);
}
