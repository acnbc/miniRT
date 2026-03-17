/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:03:58 by jessica           #+#    #+#             */
/*   Updated: 2026/03/17 01:44:21 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

t_id	get_id(char *str)
{
	while (str && *str && *str == ' ')
		str++;
	if (!ft_strncmp(str, "A", 2))
		return (A);
	else if (!ft_strncmp(str, "C", 2))
		return (C);
	else if (!ft_strncmp(str, "L", 2))
		return (L);
	else if (!ft_strncmp(str, "sp", 3))
		return (sp);
	else if (!ft_strncmp(str, "pl", 3))
		return (pl);
	else if (!ft_strncmp(str, "cy", 3))
		return (cy);
	return (Invalid);
}

t_tuple	get_coord(char **infos, int index, bool vector)
{
	t_tuple	coord;
	char	**arr;

	coord.x = 0;
	coord.y = 0;
	coord.z = 0;
	coord.is_point = false;
	arr = ft_split(infos[index], ',');
	if (ft_split_len(arr) != 3)
	{
		ft_split_free(&arr);
		return (coord);
	}
	coord.x = ft_atod(arr[0]);
	coord.y = ft_atod(arr[1]);
	coord.z = ft_atod(arr[2]);
	coord.is_point = !vector;
	ft_split_free(&arr);
	return (coord);
}

bool	valid_tuple(t_tuple tuple)
{
	if (tuple.is_point)
		return (true);
	if ((tuple.x < -1 || tuple.x > 1)
		|| (tuple.y < -1 || tuple.y > 1)
		|| (tuple.z < -1 || tuple.z > 1))
		return (false);
	if (!tuple.x && !tuple.y && !tuple.z)
		return (false);
	return (true);
}

bool	get_coolors(t_rgb *colors, char **infos, int index)
{
	char	**arr;
	int		nbr[3];
	int		i;

	if (!colors)
		return (true);
	arr = ft_split(infos[index], ',');
	i = 0;
	while (arr && arr[i] && i < 3)
	{
		nbr[i] = ft_atoi(arr[i]);
		if (nbr[i] < 0 || nbr[i] > 255)
		{
			ft_split_free(&arr);
			return (true);
		}
		i++;
	}
	ft_split_free(&arr);
	colors->r = (unsigned char)nbr[0];
	colors->g = (unsigned char)nbr[1];
	colors->b = (unsigned char)nbr[2];
	return (i != 3);
}
