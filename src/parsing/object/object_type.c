/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 01:40:17 by jessica           #+#    #+#             */
/*   Updated: 2026/03/17 22:59:02 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static void	object_type_sphere(t_object *object, char ***infos, int index);
static void	object_type_plane(t_object *object, char ***infos, int index);
static void	object_type_cylinder(t_object *object, char ***infos, int index);

void	get_object_type(t_object *object, char ***infos, int index)
{
	int	len;

	len = 1;
	if (object->id == cy)
		len = 3;
	if (!infos || !*infos || ft_split_len(&(*infos)[index]) < len)
	{
		free(object);
		ft_split_free(infos);
		exit_error(ERR_MISSING_ARGS, NULL);
	}
	if (object->id == sp)
		object_type_sphere(object, infos, index);
	if (object->id == pl)
		object_type_plane(object, infos, index);
	if (object->id == cy)
		object_type_cylinder(object, infos, index);
}

static void	object_type_sphere(t_object *object, char ***infos, int index)
{
	t_sphere	*sphere;

	object->object.sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	sphere = object->object.sphere;
	if (!sphere)
	{
		free(object);
		ft_split_free(infos);
		exit_error(ERR_MALLOC, NULL);
	}
	sphere->diameter = ft_atod((*infos)[index]);
}

static void	object_type_plane(t_object *object, char ***infos, int index)
{
	t_plane		*plane;
	t_msg_error	error;

	object->object.plane = (t_plane *)ft_calloc(1, sizeof(t_plane));
	plane = object->object.plane;
	if (!plane)
	{
		free(object);
		ft_split_free(infos);
		exit_error(ERR_MALLOC, NULL);
	}
	plane->normalized_vector = get_coord(*infos, index, true);
	error = valid_tuple(plane->normalized_vector);
	if (error)
	{
		free(object);
		ft_split_free(infos);
		exit_error(error, NULL);
	}
}

static void	object_type_cylinder(t_object *object, char ***infos, int index)
{
	t_cylinder	*cylinder;
	t_msg_error	error;

	object->object.cylinder = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	cylinder = object->object.cylinder;
	if (!cylinder)
	{
		free(object);
		ft_split_free(infos);
		exit_error(ERR_MALLOC, NULL);
	}
	cylinder->normalized_vector = get_coord(*infos, index, true);
	error = valid_tuple(cylinder->normalized_vector);
	if (error)
	{
		free(object);
		ft_split_free(infos);
		exit_error(error, NULL);
	}
	cylinder->diameter = ft_atoi((*infos)[index + 1]);
	cylinder->height = ft_atoi((*infos)[index + 2]);
}
