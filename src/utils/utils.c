/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:57 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/11 23:29:41 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	free_matrix(t_matrix *matrix)
{
	if (matrix == NULL)
		return ;
	free(matrix);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (ptr == NULL)
		exit_error("malloc error", false, NULL);
	return (ptr);
}

void	exit_error(char *error, bool clean, t_scene **_scene)
{
	static t_scene	**scene;
	char			*str;

	if (_scene)
	{
		scene = _scene;
		return ;
	}
	if (error)
	{
		str = ft_sprintf("Error: %s\n", error);
		ft_putendl_fd(str, 2);
		free(str);
		if (clean)
			free(error);
	} else {
		ft_putendl_fd("Error\n", 2);
	}
	free_scene(scene);
	exit(1);
}
