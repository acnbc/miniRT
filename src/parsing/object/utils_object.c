/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:03:58 by jessica           #+#    #+#             */
/*   Updated: 2026/02/15 07:57:29 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static char	**split_arg(char *str);
static bool	valid_tuple(t_tuple *tuple);

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
	exit_error("invalid identifier", false, NULL);
	return (-1);
}

t_tuple	*get_coord(char *str, bool vector)
{
	t_tuple	*coord;
	char	**arr;

	arr = split_arg(str);
	if (!arr)
		return (NULL);
	coord = ft_calloc(1, sizeof(t_tuple));
	if (!coord)
	{
		ft_split_free(&arr);
		exit_error("malloc error", false, NULL);
	}
	coord->x = ft_atod(arr[0]);
	coord->y = ft_atod(arr[1]);
	coord->z = ft_atod(arr[2]);
	coord->is_point = !vector;
	if (!valid_tuple(coord))
	{
		free(coord);
		coord = NULL;
	}
	ft_split_free(&arr);
	return (coord);
}

static bool	valid_tuple(t_tuple *tuple)
{
	if (tuple->is_point)
		return (true);
	if ((tuple->x < -1 || tuple->x > 1)
		|| (tuple->y < -1 || tuple->y > 1)
		|| (tuple->z < -1 || tuple->z > 1))
		return (false);
	return (true);
}

t_rgb	*get_coolors(char *str)
{
	char	**arr;
	t_rgb	*colors;

	arr = split_arg(str);
	if (!arr)
		return (NULL);
	colors = ft_calloc(1, sizeof(t_rgb));
	if (!colors)
	{
		ft_split_free(&arr);
		exit_error("malloc error", false, NULL);
	}
	colors->r = (unsigned char)ft_atoi(arr[0]);
	colors->g = (unsigned char)ft_atoi(arr[1]);
	colors->b = (unsigned char)ft_atoi(arr[2]);
	ft_split_free(&arr);
	return (colors);
}

static char	**split_arg(char *str)
{
	char	**arr;

	arr = ft_split(str, ',');
	if (!arr)
		exit_error("malloc error", false, NULL);
	if (ft_split_len(arr) != 3)
	{
		ft_split_free(&arr);
		exit_error("invalid arguments", false, NULL);
	}
	return (arr);
}
