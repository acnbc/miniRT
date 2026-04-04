/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:03:58 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 14:39:08 by jessica          ###   ########.fr       */
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

t_matrix	get_coord(char **infos, int index, bool vector)
{
	char		**arr;
	double		nbrs[3];
	t_matrix	matrix;

	arr = ft_split(infos[index], ',');
	if (ft_split_len(arr) != 3)
	{
		ft_split_free(&arr);
		exit_error(ERR_MALLOC, NULL);
	}
	nbrs[0] = ft_atod(arr[0]);
	nbrs[1] = ft_atod(arr[1]);
	nbrs[2] = ft_atod(arr[2]);
	ft_split_free(&arr);
	if (vector)
		init_vector(&matrix, nbrs[0], nbrs[1], nbrs[2]);
	else
		init_point(&matrix, nbrs[0], nbrs[1], nbrs[2]);
	return (matrix);
}

t_msg_error	valid_tuple(t_matrix matrix)
{
	if (matrix.m_4x1[3])
		return (0);
	if ((matrix.m_4x1[0] < -1 || matrix.m_4x1[0] > 1)
		|| (matrix.m_4x1[1] < -1 || matrix.m_4x1[1] > 1)
		|| (matrix.m_4x1[2] < -1 || matrix.m_4x1[2] > 1))
		return (ERR_RANGE);
	if (!matrix.m_4x1[0] && !matrix.m_4x1[1] && !matrix.m_4x1[2])
		return (ERR_ARGS);
	return (0);
}

t_msg_error	get_colors(t_rgb *colors, char **infos, int index)
{
	char	**arr;
	int		nbr[3];
	int		i;

	if (!colors)
		return (ERR_ARGS);
	arr = ft_split(infos[index], ',');
	i = 0;
	while (arr && arr[i] && i < 3)
	{
		nbr[i] = ft_atoi(arr[i]);
		if (nbr[i] < 0 || nbr[i] > 255)
		{
			ft_split_free(&arr);
			return (ERR_RANGE);
		}
		i++;
	}
	ft_split_free(&arr);
	if (i != 3)
		return (ERR_ARGS);
	colors->r = nbr[0] / 255.0;
	colors->g = nbr[1] / 255.0;
	colors->b = nbr[2] / 255.0;
	return (0);
}
