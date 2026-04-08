/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 01:40:17 by jessica           #+#    #+#             */
/*   Updated: 2026/04/08 07:54:40 by ldos_sa2         ###   ########.fr       */
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

	object->object.sphere.diameter = ft_atod((*infos)[index]);
}

static void	object_type_plane(t_object *object, char ***infos, int index)
{
	t_msg_error	error;

	object->object.plane.normalized_vector = get_coord(*infos, index, true);
	error = valid_tuple(object->object.plane.normalized_vector);
	if (error)
	{
		free(object);
		ft_split_free(infos);
		exit_error(error, NULL);
	}
}

static void	object_type_cylinder(t_object *object, char ***infos, int index)
{
	t_msg_error	error;

	object->object.cylinder.normalized_vector = get_coord(*infos, index, true);
	error = valid_tuple(object->object.cylinder.normalized_vector);
	if (error)
	{
		free(object);
		ft_split_free(infos);
		exit_error(error, NULL);
	}
	object->object.cylinder.diameter = ft_atod((*infos)[index + 1]);
	object->object.cylinder.height = ft_atod((*infos)[index + 2]);
}
