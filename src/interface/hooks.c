/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:35:44 by jessica           #+#    #+#             */
/*   Updated: 2026/03/21 16:58:45 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static int	key_hook(int keycode, void *param);
static int	hook(void *param);

void	init_hooks(t_scene *scene)
{
	mlx_key_hook(scene->window->win_ptr, &key_hook, scene);
	mlx_hook(scene->window->win_ptr, DestroyNotify, NoEventMask, &hook, scene);
	mlx_loop(scene->window->mlx_ptr);
}

static int	key_hook(int keycode, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (keycode == XK_Escape)
	{
		mlx_loop_end(scene->window->mlx_ptr);
	}
	return (0);
}

static int	hook(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	mlx_loop_end(scene->window->mlx_ptr);
	return (0);
}
