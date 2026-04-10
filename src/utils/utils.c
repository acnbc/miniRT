/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:57 by anogueir          #+#    #+#             */
/*   Updated: 2026/04/03 15:19:34 by jessica          ###   ########.fr       */
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

void	exit_error(t_msg_error error, t_scene **_scene)
{
	static t_scene	**scene = NULL;

	if (_scene)
	{
		scene = _scene;
		return ;
	}
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(get_error_message(error), 2);
	if (scene)
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
