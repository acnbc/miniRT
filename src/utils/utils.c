/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:57 by anogueir          #+#    #+#             */
/*   Updated: 2026/03/25 20:46:00 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static char	*get_error_message(t_msg_error err);

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
		exit_error(ERR_MALLOC, NULL);
	return (ptr);
}

void	exit_error(t_msg_error error, t_scene **_scene)
{
	static t_scene	**scene;

	if (_scene)
	{
		scene = _scene;
		return ;
	}
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(get_error_message(error), 2);
	free_scene(scene);
	exit(1);
}

static char	*get_error_message(t_msg_error err)
{
	static char	*messages[] = {
		"",
		"malloc error",
		"invalid arguments",
		"invalid format file",
		"error reading file",
		"single element duplicated",
		"out of range",
		"missing A, C or L element",
		"missing arguments",
		"invalid element identifier",
		"mlx init error",
		"mlx new window error",
		"mlx new image error",
		"mlx get data addr error"
	};

	return (messages[err]);
}
