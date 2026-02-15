/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:57 by anogueir          #+#    #+#             */
/*   Updated: 2026/02/15 08:00:01 by jessica          ###   ########.fr       */
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

	if (_scene)
	{
		scene = _scene;
		return ;
	}
	ft_putendl_fd("Error", 2);
	if (error)
	{
		ft_putendl_fd(error, 2);
		if (clean)
			free(error);
	}
	free_scene(scene);
	*scene = NULL;
	exit(1);
}
